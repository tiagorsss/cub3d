/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:15:13 by treis-ro          #+#    #+#             */
/*   Updated: 2025/10/12 12:49:40 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_one_texture(t_cub3d *cub, t_texture_img *dst, char *path)
{
	dst->img = mlx_xpm_file_to_image(cub->mlx_connection, path,
		&dst->width, &dst->height);
	if (!dst->img)
	{
		ft_printf("Error\nFailed to load texture: %s\n", path);
		exit(1);
	}
	dst->addr = (int *)mlx_get_data_addr(dst->img, &dst->bpp,
		&dst->line_length, &dst->endian);
}

void	load_textures(t_cub3d *cub, t_textures *tex)
{
	load_one_texture(cub, &tex->no_img, tex->NO);
	load_one_texture(cub, &tex->so_img, tex->SO);
	load_one_texture(cub, &tex->we_img, tex->WE);
	load_one_texture(cub, &tex->ea_img, tex->EA);
}
