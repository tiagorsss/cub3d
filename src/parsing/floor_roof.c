/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_roof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:49:16 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/10 13:12:26 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	valid_rgb_range(int *rgb)
{
	if (!rgb)
		return (false);
	for (int i = 0; i < 3; i++)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (false);
	}
	return (true);
}

int	*set_color(char *line, char id)
{
	int		*rgb;
	char	*p;
	int		i;

	i = 0;
	p = line;
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (NULL);
	if (*p == id)
		p++;
	while (*p && ft_isspace(*p))
		p++;
	while (*p)
	{
		if (i >= 3)
			return (free(rgb), printf("File not right: too many numbers\n"), NULL);
		if (!(*p >= '0' && *p <= '9'))
			return (free(rgb), printf("File not right: expected number\n"), NULL);
		rgb[i] = ft_atoi(p);
		while (*p && (*p >= '0' && *p <= '9'))
			p++;
		if (*p == ',')
			p++;
		while (*p && ft_isspace(*p))
			p++;
		i++;
	}
	if (i != 3)
		return (free(rgb), printf("File not right: few numbers\n"), NULL);
	return (rgb);
}
