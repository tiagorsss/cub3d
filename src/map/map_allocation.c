/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:06:25 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/10 13:30:26 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*m_struct_alloc(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_length = 0;
	map->map_height = 0;
	map->invalid = false;
	map->map = NULL;
	return (map);
}

void	print_map(t_map *map, t_pos *pos)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("PLAYER POS: X = %f, Y = %f\n", pos->x, pos->y);
	printf("Facing: X = %f, Y = %f\n", pos->dir_x, pos->dir_y);
	printf("Plane: X = %f, Y = %f\n", pos->plane_x, pos->plane_y);
}

t_map	*map_alloc(t_map *map, int fd)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	while (y < map->map_start)
	{
		line = get_next_line(fd, 0);
		free(line);
		y++;
	}
	map->map = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->map)
		return (NULL);
	y = 0;
	while (y < map->map_height && (line = get_next_line(fd, 0)))
	{
		map->map[y] = malloc(sizeof(char) * (map->map_length + 1));
		if (!map->map[y])
			return (NULL);
		x = 0;
		while (line[x] && line[x] != '\n' && x < map->map_length)
		{
			map->map[y][x] = line[x];
			x++;
		}
		while (x < map->map_length)
			map->map[y][x++] = ' ';
		map->map[y][x] = '\0';
		free(line);
		y++;
	}
	map->map[y] = NULL;
	return (map);
}

t_map	*map_prep(char *file, t_index *index)
{
	t_map	*map;
	int		fd;

	map = m_struct_alloc();
	if (!map)
		return (NULL);
	map->invalid = false;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = map_exist(fd, map);
	if (map->invalid == true)
		return (map);
	fd = open(file, O_RDONLY);
	map = map_alloc(map, fd);
	if (!map_array_validation(map))
		map->invalid = true;
	if (!map->invalid)
	{
		if (!validate_map_fill(map, index->pos))
			map->invalid = true;
	}
	print_map(map, index->pos);
	return (map);
}
