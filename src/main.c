/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:14:49 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/12 12:16:41 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_index	*index;

	if (!arg_validation(ac, av))
		return (ft_putstr_fd("invalid arguments\n", 2), 1);
	index = init_index();
	if (!index)
		return (ft_putstr_fd("error initializing\n", 2), 1);
	index->textures = texture_init(av[1]);
	if (index->textures == NULL || index->textures->invalid)
    	clean_exit_basic(index);
	index->map = map_prep(av[1], index);
	if (index->map->invalid)
		clean_exit_basic(index);
	mlx_creation(index->cub3d);
	load_textures(index->cub3d, index->textures);
	mlx_loop_hook(index->cub3d->mlx_connection, render_frame, index);
	mlx_hook(index->cub3d->mlx_win, 2, 1L << 0, handle_key, index);
	mlx_hook(index->cub3d->mlx_win, 17, 0, handle_closing, index);
	mlx_loop(index->cub3d->mlx_connection);
	free(index);
	return (0);
}
