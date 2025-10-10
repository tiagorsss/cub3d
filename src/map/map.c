/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:06:25 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/10 12:30:16 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_header_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "F ", 2)
		|| !ft_strncmp(line, "C ", 2))
		return (true);
	return (false);
}

bool	is_empty_line(char *line)
{
	int	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

t_map	*map_exist(int fd, t_map *map)
{
	char	*line;
	int		start;

	start = 0;
	line = get_next_line(fd, 1);
	while (line)
	{
		if (!is_header_line(line) && !is_empty_line(line))
			break;
		free(line);
		line = get_next_line(fd, 0);
		start++;
	}
	if (!line)
		return (close(fd), map->invalid = true, map);
	map->map_start = start;
	get_size(fd, line, map);
	return (map);
}

void	get_size(int fd, char *line, t_map *map)
{
	size_t	size;
	int		height;

	height = 0;
	size = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) > size)
			size = ft_strlen(line);
		height++;
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	map->map_length = size - 1;
	map->map_height = height;
	return ;
}

bool	valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

bool	is_map_line(char *line)
{
	int	i;
	int	has_map_char;

	i = 0;
	has_map_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!valid_map_char(line[i]))
			return (false);
		if (line[i] == '1' || line[i] == '0' || ft_strchr("NSEW", line[i]))
			has_map_char = 1;
		i++;
	}
	return (has_map_char);
}

bool	check_enclosure(t_map *map, int y, int x)
{
	if (y == 0 || y == map->map_height - 1 || x == 0 || x == map->map_length - 1)
		return (false);
	if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' '
		|| map->map[y][x - 1] == ' ' || map->map[y][x + 1] == ' ')
		return (false);
	return (true);
}

bool	map_array_validation(t_map *map)
{
	int	y, x, player_count;
	char	c;

	player_count = 0;
	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_length)
		{
			c = map->map[y][x];
			if (!valid_map_char(c))
				return (false);
			if (ft_strchr("NSEW", c))
				player_count++;
			if (ft_strchr("0NSEW", c))
			{
				if (!check_enclosure(map, y, x))
					return (false);
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (false);
	return (true);
}
