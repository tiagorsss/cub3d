/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:41:42 by treis-ro          #+#    #+#             */
/*   Updated: 2025/10/12 11:53:12 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

#define RAY_COUNT 200 // number of rays to draw
#define RAY_RANGE  60.0 

static void	draw_single_ray(t_index *idx, double ray_dir_x, double ray_dir_y)
{
	double ray_x = idx->pos->x;
	double ray_y = idx->pos->y;

	double delta_x = fabs(1 / ray_dir_x);
	double delta_y = fabs(1 / ray_dir_y);

	int map_x = (int)ray_x;
	int map_y = (int)ray_y;

	int step_x = (ray_dir_x < 0) ? -1 : 1;
	int step_y = (ray_dir_y < 0) ? -1 : 1;

	double side_dist_x = (ray_dir_x < 0)
		? (ray_x - map_x) * delta_x
		: (map_x + 1.0 - ray_x) * delta_x;
	double side_dist_y = (ray_dir_y < 0)
		? (ray_y - map_y) * delta_y
		: (map_y + 1.0 - ray_y) * delta_y;

	int hit = 0;
	double dist = 0;

	while (!hit && dist < RAY_RANGE)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_x;
			map_x += step_x;
		}
		else
		{
			side_dist_y += delta_y;
			map_y += step_y;
		}
		if (map_y < 0 || map_y >= idx->map->map_height
			|| map_x < 0 || map_x >= idx->map->map_length)
			break ;
		if (idx->map->map[map_y][map_x] == '1')
			hit = 1;
		dist += 0.1;
	}

	// convert world coords to minimap pixel coords
	int start_x = MINI_OFFX + (int)(idx->pos->x * MINI_TILE);
	int start_y = MINI_OFFY + (int)(idx->pos->y * MINI_TILE);
	int end_x = MINI_OFFX + (int)(map_x * MINI_TILE + MINI_TILE / 2);
	int end_y = MINI_OFFY + (int)(map_y * MINI_TILE + MINI_TILE / 2);

	draw_line(idx->cub3d, start_x, start_y, end_x, end_y, 0xFF0000);
}

void	render_rays(t_index *idx)
{
	double fov = 0.66; // roughly 66° field of view
	int i = 0;

	while (i < RAY_COUNT)
	{
		// map screen-space to range [-1, +1]
		double camera_x = 2 * i / (double)RAY_COUNT - 1;
		double ray_dir_x = idx->pos->dir_x + idx->pos->plane_x * camera_x * fov;
		double ray_dir_y = idx->pos->dir_y + idx->pos->plane_y * camera_x * fov;
		draw_single_ray(idx, ray_dir_x, ray_dir_y);
		i++;
	}
}

static inline int in_bounds(t_cub3d *c, int x, int y)
{
	return (x >= 0 && x < c->width && y >= 0 && y < c->height);
}

void	my_mlx_pixel_put(t_cub3d *c, int x, int y, int color)
{
	char	*dst;

	if (!in_bounds(c, x, y))
		return;
	dst = c->addr + (y * c->line_length + x * (c->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_cub3d *c, int color)
{
	int y, x;

	y = 0;
	while (y < c->height)
	{
		x = 0;
		while (x < c->width)
		{
			my_mlx_pixel_put(c, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_rect(t_cub3d *c, int x, int y, int w, int h, int color)
{
	int i, j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			my_mlx_pixel_put(c, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

// Bresenham line (int-only, solid enough for a short dir line)
void	draw_line(t_cub3d *c, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		my_mlx_pixel_put(c, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}

void	render_minimap(t_index *idx)
{
	t_cub3d	*c = idx->cub3d;
	int		y, x;
	int		tx, ty;
	char	cell;

	// draw grid: walls vs floor/void
	y = 0;
	while (y < idx->map->map_height)
	{
		x = 0;
		while (x < idx->map->map_length)
		{
			cell = idx->map->map[y][x];
			tx = MINI_OFFX + x * MINI_TILE;
			ty = MINI_OFFY + y * MINI_TILE;
			if (cell == '1')
				draw_rect(c, tx, ty, MINI_TILE, MINI_TILE, COL_WALL);
			else if (cell == '0' || cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
				draw_rect(c, tx, ty, MINI_TILE, MINI_TILE, COL_FLOOR);
			else
				draw_rect(c, tx, ty, MINI_TILE, MINI_TILE, COL_VOID);
			x++;
		}
		y++;
	}

	render_rays(idx);
	// player dot
	int px = MINI_OFFX + (int)(idx->pos->x * MINI_TILE);
	int py = MINI_OFFY + (int)(idx->pos->y * MINI_TILE);
	draw_rect(c, px - 2, py - 2, 4, 4, COL_PLAYER);

	// short facing line (length ~ 3 tiles)
	int lx = px + (int)(idx->pos->dir_x * (MINI_TILE * 3));
	int ly = py + (int)(idx->pos->dir_y * (MINI_TILE * 3));
	draw_line(c, px, py, lx, ly, COL_DIR);
}

int	render_frame(void *param)
{
	t_index *idx = (t_index *)param;

	clear_image(idx->cub3d, COL_BG);
	render_3d(idx);
	render_minimap(idx);

	mlx_put_image_to_window(idx->cub3d->mlx_connection,
		idx->cub3d->mlx_win, idx->cub3d->img, 0, 0);
    return 0;
}
