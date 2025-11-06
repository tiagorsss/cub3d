/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:23:02 by treis-ro          #+#    #+#             */
/*   Updated: 2025/11/05 13:58:16 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

/* local helpers */
static inline int	clamp_int(int v, int lo, int hi)
{
	if (v < lo) return lo;
	if (v > hi) return hi;
	return v;
}

static inline int	rgb_from_arr(int *rgb) /* expects 3 ints [0..255] */
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	render_3d(t_index *idx)
{
	t_cub3d	*c = idx->cub3d;

	/* prefer colours from .cub file, fallback to compile-time constants */
	int ceil_col = (idx->textures && idx->textures->roof)
		? rgb_from_arr(idx->textures->roof) : COL_CEIL_3D;
	int floor_col = (idx->textures && idx->textures->floor)
		? rgb_from_arr(idx->textures->floor) : COL_FLOOR_3D;

	for (int x = 0; x < WIDTH; x++)
	{
		/* --- ray setup --- */
		double camera_x  = 2.0 * x / (double)WIDTH - 1.0;
		double ray_dir_x = idx->pos->dir_x + idx->pos->plane_x * camera_x;
		double ray_dir_y = idx->pos->dir_y + idx->pos->plane_y * camera_x;

		int    map_x = (int)idx->pos->x;
		int    map_y = (int)idx->pos->y;

		/* guard for zero to avoid INF/NaN; use a big number (like lodev) */
		double delta_dist_x = (ray_dir_x == 0.0) ? 1e30 : fabs(1.0 / ray_dir_x);
		double delta_dist_y = (ray_dir_y == 0.0) ? 1e30 : fabs(1.0 / ray_dir_y);

		double side_dist_x;
		double side_dist_y;
		int    step_x;
		int    step_y;

		int hit  = 0;
		int side = 0; /* 0: x-side, 1: y-side */

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (idx->pos->x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - idx->pos->x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (idx->pos->y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - idx->pos->y) * delta_dist_y;
		}

		/* --- DDA --- */
		while (!hit)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			/* defensive bounds: skip column if we ever step outside map */
			if (map_y < 0 || map_y >= idx->map->map_height
			 || map_x < 0 || map_x >= idx->map->map_length)
				break;
			if (idx->map->map[map_y][map_x] == '1')
				hit = 1;
		}

		/* if no hit (e.g., malformed/open map), draw flat and continue */
		if (!hit)
		{
			for (int y = 0; y < HEIGHT; ++y)
				my_mlx_pixel_put(c, x, y, (y < HEIGHT / 2) ? ceil_col : floor_col);
			continue;
		}

		/* --- distance to wall (perp) --- */
		double perp_wall_dist = (side == 0) ? (side_dist_x - delta_dist_x)
											: (side_dist_y - delta_dist_y);
		if (perp_wall_dist <= 0.0) /* avoid division blow-ups */
			perp_wall_dist = 1e-6;

		/* --- vertical stripe extents --- */
		int line_height = (int)(HEIGHT / perp_wall_dist);
		int draw_start  = -line_height / 2 + HEIGHT / 2;
		int draw_end    =  line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)       draw_start = 0;
		if (draw_end >= HEIGHT)   draw_end   = HEIGHT - 1;

		/* --- select texture by face --- */
		t_texture_img *tex;
		if (side == 0 && ray_dir_x > 0)
			tex = &idx->textures->we_img; /* hit west face (looking +X) */
		else if (side == 0 && ray_dir_x < 0)
			tex = &idx->textures->ea_img; /* hit east face (looking -X) */
		else if (side == 1 && ray_dir_y > 0)
			tex = &idx->textures->no_img; /* hit north face (looking +Y) */
		else
			tex = &idx->textures->so_img; /* hit south face */

		/* --- texture X coordinate (where the ray hit horizontally along wall) --- */
		double wall_x;
		if (side == 0)
			wall_x = idx->pos->y + perp_wall_dist * ray_dir_y;
		else
			wall_x = idx->pos->x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x); /* keep fractional part 0..1 */

		int tex_x = (int)(wall_x * (double)tex->width);
		if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
			tex_x = tex->width - tex_x - 1; /* flip for correct orientation */
		tex_x = clamp_int(tex_x, 0, tex->width - 1);

		/* --- ceiling --- */
		for (int y = 0; y < draw_start; y++)
			my_mlx_pixel_put(c, x, y, ceil_col);

		/* --- textured wall (size-agnostic) --- */
		double step    = (double)tex->height / (double)line_height;
		double tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;

		for (int y = draw_start; y <= draw_end; y++)
		{
			int tex_y = (int)tex_pos;
			tex_pos += step;
			tex_y = clamp_int(tex_y, 0, tex->height - 1);

			int row_off = (tex->line_length / 4) * tex_y;
			int color   = tex->addr[row_off + tex_x];

			/* subtle darkening for y-side to give depth */
			if (side == 1)
				color = (color >> 1) & 0x7F7F7F;

			my_mlx_pixel_put(c, x, y, color);
		}

		/* --- floor --- */
		for (int y = draw_end + 1; y < HEIGHT; y++)
			my_mlx_pixel_put(c, x, y, floor_col);
	}
}
