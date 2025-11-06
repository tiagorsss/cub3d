/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:48:08 by lumiguel          #+#    #+#             */
/*   Updated: 2025/11/05 13:45:25 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_textures	*texture_init(char *file)
{
	t_textures	*tex;
	int			fd;
	int			step;
	char		*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCannot open file\n"), NULL);
	tex = init_textures();
	step = 0;
	line = get_next_line(fd, 0);
	while (step < 6 && (line != NULL))
	{
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		if (!parse_texture_line(tex, line, step))
		{
			tex->invalid = true;
			free(line);
			break ;
		}
		step++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	if (step != 6 || tex_check(tex))
	{
		printf("Error\nIncomplete or invalid texture configuration\n");
		free_textures(tex);
		return (NULL);
	}
	return (tex);
}

bool	parse_texture_line(t_textures *tex, char *line, int step)
{
	char	*ids[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	char	*trimmed;

	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, ids[step], ft_strlen(ids[step])) != 0)
		return (false);
	if (step <= 3)
	{
		trimmed = extract_path(line, (char *)ids[step], tex);
		if (!trimmed)
			return (false);
		if (check_file(trimmed))
			return (free(trimmed), false);
		if (step == 0)
			tex->no = trimmed;
		if (step == 1)
			tex->so = trimmed;
		if (step == 2)
			tex->we = trimmed;
		if (step == 3)
			tex->ea = trimmed;
	}
	else if (step == 4)
	{
		tex->floor = set_color(line, 'F');
		if (!tex->floor || !valid_rgb_range(tex->floor))
			return (false);
	}
	else if (step == 5)
	{
		tex->roof = set_color(line, 'C');
		if (!tex->roof || !valid_rgb_range(tex->roof))
			return (false);
	}
	return (true);
}

// void	path_setter(t_textures *tex, int fd)
// {
// 	char	*line;

// 	line = get_next_line(fd, 0);
// 	while (line)
// 	{
// 		if (line[0] == 'N' && line[1] == 'O')
// 			tex->NO = extract_path(line, "NO", tex);
// 		else if (line[0] == 'S' && line[1] == 'O')
// 			tex->SO = extract_path(line, "SO", tex);
// 		else if (line[0] == 'W' && line[1] == 'E')
// 			tex->WE = extract_path(line, "WE", tex);
// 		else if (line[0] == 'E' && line[1] == 'A')
// 			tex->EA = extract_path(line, "EA", tex);
// 		else if (line[0] == 'F')
// 			tex->floor = set_color(line, 'F');
// 		else if (line[0] == 'C')
// 		{
// 			tex->roof = set_color(line, 'C');
// 			free(line);
// 			break ;
// 		}
// 		free(line);
// 		line = get_next_line(fd, 0);
// 	}
// }

char	*extract_path(char *line, char *id, t_textures *tex)
{
	size_t		id_len;
	char		*path;
	size_t		len;
	const char	*p;

	id_len = ft_strlen(id);
	if (ft_strncmp(line, id, id_len) != 0 || !ft_isspace(line[id_len]))
		return (NULL);
	p = line + id_len;
	while (*p && ft_isspace(*p))
		p++;
	if (*p == '\0')
		return (NULL);
	path = ft_strdup(p);
	if (!path)
		return (NULL);
	len = ft_strlen(path);
	while (len > 0 && ft_isspace(path[len - 1]))
		path[--len] = '\0';
	if (check_file(path))
		tex->invalid = true;
	return (path);
}

bool	tex_check(t_textures *tex)
{
	if (tex->invalid)
		return (true);
	if (tex->no == NULL)
		return (true);
	if (tex->roof == NULL)
		return (true);
	if (tex->ea == NULL)
		return (true);
	if (tex->so == NULL)
		return (true);
	if (tex->we == NULL)
		return (true);
	if (tex->floor == NULL)
		return (true);
	return (false);
}

t_textures	*init_textures(void)
{
	t_textures	*tex;

	tex = malloc(sizeof(t_textures));
	if (!tex)
	{
		ft_putstr_fd("Error\nFile not right\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tex->no = NULL;
	tex->so = NULL;
	tex->we = NULL;
	tex->ea = NULL;
	tex->roof = NULL;
	tex->floor = NULL;
	tex->invalid = false;
	return (tex);
}
