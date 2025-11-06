/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:59:38 by lumiguel          #+#    #+#             */
/*   Updated: 2025/11/05 13:58:56 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

#define MOVE_SPEED 0.08
#define ROT_SPEED 0.05

// -------------------- Utility --------------------

static int	is_wall(t_map *map, double y, double x)
{
	int	map_x = (int)x;
	int	map_y = (int)y;

	if (map_y < 0 || map_y >= map->map_height || map_x < 0 || map_x >= map->map_length)
		return (1);
	return (map->map[map_y][map_x] == '1');
}

// -------------------- Movement --------------------

static void	move_forward_backward(t_index *idx, int dir)
{
	double	new_x = idx->pos->x + idx->pos->dir_x * MOVE_SPEED * dir;
	double	new_y = idx->pos->y + idx->pos->dir_y * MOVE_SPEED * dir;

	if (!is_wall(idx->map, idx->pos->y, new_x))
		idx->pos->x = new_x;
	if (!is_wall(idx->map, new_y, idx->pos->x))
		idx->pos->y = new_y;
}

static void	move_strafe(t_index *idx, int dir)
{
	double	new_x = idx->pos->x + idx->pos->plane_x * MOVE_SPEED * dir;
	double	new_y = idx->pos->y + idx->pos->plane_y * MOVE_SPEED * dir;

	if (!is_wall(idx->map, idx->pos->y, new_x))
		idx->pos->x = new_x;
	if (!is_wall(idx->map, new_y, idx->pos->x))
		idx->pos->y = new_y;
}

// -------------------- Rotation --------------------

static void	rotate_player(t_index *idx, double angle)
{
	double	old_dir_x = idx->pos->dir_x;
	double	old_plane_x = idx->pos->plane_x;

	idx->pos->dir_x = idx->pos->dir_x * cos(angle) - idx->pos->dir_y * sin(angle);
	idx->pos->dir_y = old_dir_x * sin(angle) + idx->pos->dir_y * cos(angle);
	idx->pos->plane_x = idx->pos->plane_x * cos(angle) - idx->pos->plane_y * sin(angle);
	idx->pos->plane_y = old_plane_x * sin(angle) + idx->pos->plane_y * cos(angle);
}

// -------------------- Input Hook --------------------

int	handle_key(int keycode, t_index *idx)
{
	// ESC — quit
	if (keycode == 65307)
		clean_exit_basic(idx);

	// Movement: W/S forward/back, A/D strafe
	if (keycode == 'w' || keycode == 119)
		move_forward_backward(idx, 1);
	if (keycode == 's' || keycode == 115)
		move_forward_backward(idx, -1);
	if (keycode == 'a' || keycode == 97)
		move_strafe(idx, -1);
	if (keycode == 'd' || keycode == 100)
		move_strafe(idx, 1);

	// Rotation: ← → arrows
	if (keycode == 65361) // left arrow
		rotate_player(idx, -ROT_SPEED);
	if (keycode == 65363) // right arrow
		rotate_player(idx, ROT_SPEED);

	return (0);
}

int	handle_closing(t_index *index)
{
	clean_exit(index);
	return (0);
}
