/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:27:11 by lumiguel          #+#    #+#             */
/*   Updated: 2025/11/02 17:33:48 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	arg_validation(int argc, char **argv)
{
	int	i;
	int	len;

	if (argc != 2 || !argv[1] || !argv[1][0])
		return (false);
	len = ft_strlen(argv[1]);
	i = len - 1;
	while (i >= 0 && argv[1][i] != '.')
		i--;
	if (i < 0 || ft_strncmp(argv[1] + i, ".cub", 4) != 0)
		return (false);
	return (true);
}

bool	check_file(const char *path)
{
	int	fd;

	if (access(path, R_OK) == -1)
		return (true);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (true);
	close(fd);
	return (false);
}
