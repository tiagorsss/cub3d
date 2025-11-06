/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:37:29 by lumiguel          #+#    #+#             */
/*   Updated: 2025/11/05 13:58:50 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*

why allocate this shit when it can be static 

only pos needs allocation? not even prob

*/

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
