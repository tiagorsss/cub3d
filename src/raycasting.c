/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:23:02 by treis-ro          #+#    #+#             */
/*   Updated: 2025/10/12 12:46:01 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	render_3d(t_index *idx)
{
	t_cub3d *c = idx->cub3d;
	int x = 0;

	while (x < WIDTH)
	{
		double camera_x = 2 * x / (double)WIDTH - 1;
		double ray_dir_x = idx->pos->dir_x + idx->pos->plane_x * camera_x;
		double ray_dir_y = idx->pos->dir_y + idx->pos->plane_y * camera_x;

		int map_x = (int)idx->pos->x;
		int map_y = (int)idx->pos->y;

		double side_dist_x;
		double side_dist_y;

		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;

		int step_x;
		int step_y;
		int hit = 0;
		int side;

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

		// perform DDA
		while (hit == 0)
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
			if (map_y < 0 || map_y >= idx->map->map_height
			|| map_x < 0 || map_x >= idx->map->map_length)
				break;
			if (idx->map->map[map_y][map_x] == '1')
				hit = 1;
		}

		t_texture_img *tex;
		if (side == 0 && ray_dir_x > 0)
			tex = &idx->textures->we_img; // we hit a west wall (looking right)
		else if (side == 0 && ray_dir_x < 0)
			tex = &idx->textures->ea_img; // hit east wall (looking left)
		else if (side == 1 && ray_dir_y > 0)
			tex = &idx->textures->no_img; // hit north wall (looking down)
		else
			tex = &idx->textures->so_img;
			
		// Calculate distance projected on camera direction
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		// Calculate height of line to draw on screen
		int line_height = (int)(HEIGHT / perp_wall_dist);

		// calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		// Calculate exact position of wall hit
		double wall_x;
		if (side == 0)
			wall_x = idx->pos->y + perp_wall_dist * ray_dir_y;
		else
			wall_x = idx->pos->x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x); // fractional part only (0–1)

		int tex_x = (int)(wall_x * (double)tex->width);
		if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
			tex_x = tex->width - tex_x - 1; // flip for certain orientations

		double step = 1.0 * tex->height / line_height;
		double tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;

		// draw ceiling
		for (int y = 0; y < draw_start; y++)
			my_mlx_pixel_put(c, x, y, COL_CEIL_3D);

		// Draw textured wall
		for (int y = draw_start; y < draw_end; y++)
		{
			int tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			int color = tex->addr[(tex->line_length / 4) * tex_y + tex_x];
		
			// make Y-sides slightly darker for pseudo-lighting
			if (side == 1)
				color = (color >> 1) & 0x7F7F7F;
		
			my_mlx_pixel_put(c, x, y, color);
		}

		// draw floor
		for (int y = draw_end; y < HEIGHT; y++)
			my_mlx_pixel_put(c, x, y, COL_FLOOR_3D);

		x++;
	}
}
