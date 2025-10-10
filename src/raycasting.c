/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:23:02 by treis-ro          #+#    #+#             */
/*   Updated: 2025/10/10 19:03:56 by treis-ro         ###   ########.fr       */
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
			if (idx->map->map[map_y][map_x] == '1')
				hit = 1;
		}

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

		// draw ceiling
		for (int y = 0; y < draw_start; y++)
			my_mlx_pixel_put(c, x, y, COL_CEIL_3D);

		// draw wall
		int wall_col = (side == 1) ? 0x888888 : 0xFFFFFF;
		for (int y = draw_start; y <= draw_end; y++)
			my_mlx_pixel_put(c, x, y, wall_col);

		// draw floor
		for (int y = draw_end; y < HEIGHT; y++)
			my_mlx_pixel_put(c, x, y, COL_FLOOR_3D);

		x++;
	}
}
