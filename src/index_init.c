/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:37:29 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/09 18:24:28 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_index	*init_index(void)
{
	t_index	*index;

	index = malloc(sizeof(t_index));
	if (!index)
		return (NULL);
	index->cub3d = NULL;
	index->textures = NULL;
	index->map = NULL;
	index->pos = malloc(sizeof(t_pos));
	if (!index->pos)
	{
		free(index);
		return (NULL);
	}
	index->cub3d = malloc(sizeof(t_cub3d));
	if (!index->cub3d)
	{
		free(index->pos);
		free(index);
		return (NULL);
	}
	index->cub3d->mlx_connection = NULL;
	index->cub3d->mlx_win = NULL;
	index->cub3d->img = NULL;
	return (index);
}
