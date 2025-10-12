/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:30:55 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/12 11:57:52 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	flood_fill_dfs(t_map *map, bool **visited, int y, int x)
{
	if (y < 0 || y >= map->map_height || x < 0 || x >= map->map_length)
		return (false);
	if (visited[y][x] || map->map[y][x] == '1')
		return (true);
	if (map->map[y][x] == ' ' || map->map[y][x] == '\0'
		|| map->map[y][x] == '\n')
		return (false);
	visited[y][x] = (true);
	if (!flood_fill_dfs(map, visited, y - 1, x))
		return (false);
	if (!flood_fill_dfs(map, visited, y + 1, x))
		return (false);
	if (!flood_fill_dfs(map, visited, y, x - 1))
		return (false);
	if (!flood_fill_dfs(map, visited, y, x + 1))
		return (false);
	return (true);
}

bool	validate_map_fill(t_map *map, t_pos *start)
{
	int		i;
	bool	**visited;
	bool	ok;

	i = 0;
	visited = malloc(sizeof(bool *) * map->map_height);
	if (!visited)
		return (false);
	while (i < map->map_height)
	{
		visited[i] = calloc(map->map_length, sizeof(bool));
		if (!visited[i])
		{
			bool_array_clean(visited, i);
			return (false);
		}
		i++;
	}
	if (!find_player_start(map, start))
		return (false);
	ok = flood_fill_dfs(map, visited, start->y, start->x);
	bool_array_clean(visited, map->map_height);
	return (ok);
}

void	set_player_orientation(t_pos *pos, char dir)
{
	if (dir == 'N')
	{
		pos->dir_x = 0;
		pos->dir_y = -1;
		pos->plane_x = 0.66;
		pos->plane_y = 0;
	}
	else if (dir == 'S')
	{
		pos->dir_x = 0;
		pos->dir_y = 1;
		pos->plane_x = -0.66;
		pos->plane_y = 0;
	}
	else if (dir == 'E')
	{
		pos->dir_x = 1;
		pos->dir_y = 0;
		pos->plane_x = 0;
		pos->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		pos->dir_x = -1;
		pos->dir_y = 0;
		pos->plane_x = 0;
		pos->plane_y = -0.66;
	}
}

bool	find_player_start(t_map *map, t_pos *pos)
{
	int		y;
	int		x;
	int		found;
	char	c;

	found = 0;
	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_length)
		{
			c = map->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				pos->y = y + 0.5;
				pos->x = x + 0.5;
				set_player_orientation(pos, c);
				map->map[y][x] = '0';
				found++;
			}
			x++;
		}
		y++;
	}
	return (found == 1);
}

void	bool_array_clean(bool **visited, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
