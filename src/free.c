/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:06:38 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/10 11:55:50 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_index(t_index *index)
{
	if (!index)
		return ;
	if (index->cub3d)
	{
		free(index->cub3d);
		index->cub3d = NULL;
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	if (map->invalid)
		printf("invalid map\n");
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	free(map);
}



void	clean_exit(t_index *index)
{
	if (!index)
		exit(1);
	mlx_destroy_image(index->cub3d->mlx_connection, index->cub3d->img);
	mlx_destroy_window(index->cub3d->mlx_connection, index->cub3d->mlx_win);
	mlx_destroy_display(index->cub3d->mlx_connection);
	if (index->cub3d->mlx_connection)
		free(index->cub3d->mlx_connection);
	index->cub3d->mlx_connection = NULL;
	if (index->textures)
		free_textures(index->textures);
	if (index->pos)
		free_pos(index->pos);
	if (index->map)
		free_map(index->map);
	free(index->cub3d);
	index->cub3d = NULL;
	free(index);
	exit(0);
}

void	clean_exit_basic(t_index *index)
{
	if (!index)
		exit(1);
	if (index->textures)
		free_textures(index->textures);
	if (index->pos)
		free_pos(index->pos);
	if (index->map)
		free_map(index->map);
	free(index);
	exit(1);
}

void	clean_exit_full(t_index *index)
{
	clean_exit(index);
}

void	free_textures(t_textures *tex)
{
	if (!tex)
		return ;
	if (tex->EA)
		free(tex->EA);
	if (tex->NO)
		free(tex->NO);
	if (tex->SO)
		free(tex->SO);
	if (tex->WE)
		free(tex->WE);
	if (tex->floor)
		free(tex->floor);
	if (tex->roof)
		free(tex->roof);
	free(tex);
}

void	free_pos(t_pos *pos)
{
	if (!pos)
		return ;
	free(pos);
}
