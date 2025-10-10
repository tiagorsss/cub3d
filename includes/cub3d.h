/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treis-ro <treis-ro@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:12:04 by lumiguel          #+#    #+#             */
/*   Updated: 2025/10/10 19:09:28 by treis-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define M_PI 3.14159265358979323846
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define WIDTH 800
# define HEIGHT 600


#define COL_FLOOR_3D 0x555555
#define COL_CEIL_3D  0xAAAAAA
#define COL_WALL_3D  0xFFFFFF

# define MINI_TILE 8    // pixels per map cell on the minimap
# define MINI_OFFX 10     // minimap offset from left
# define MINI_OFFY 10     // minimap offset from top
 
// --- colors (0xRRGGBB)
# define COL_BG     0x000000
# define COL_WALL   0xFFFFFF
# define COL_FLOOR  0x222222
# define COL_VOID   0x000000
# define COL_PLAYER 0xFF0000
# define COL_DIR    0xFFAA00

# define MOVE_SPEED 0.08
# define ROT_SPEED 0.05

typedef struct s_cub3d
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_win;
	void	*mlx_connection;
	int		width;
	int		height;
}	t_cub3d;

typedef struct s_textures
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		*roof;
	int		*floor;
	bool	invalid;
}	t_textures;

typedef struct s_map
{
	int		map_length;
	int		map_height;
	int		map_start;
	char	**map;
	bool	invalid;
}	t_map;

typedef struct s_pos
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_pos;

typedef struct s_index
{
	t_cub3d		*cub3d;
	t_map		*map;
	t_textures	*textures;
	t_pos		*pos;
}	t_index;


void	mlx_creation(t_cub3d *img);
void	mlx_creation2(t_cub3d *img);
int		handle_key(int keycode,t_index *index);
int		handle_closing(t_index *index);
t_index *init_index(void);

//arguments
bool	arg_validation(int argc, char **argv);
t_textures	*texture_init(char *file);
char		*extract_path(char *line, char *id, t_textures *tex);
void		path_setter(t_textures *tex, int fd);
t_textures	*init_textures(void);
bool	is_map_line(char *line);
bool	validate_map_fill(t_map *mapa, t_pos *player);
bool	find_player_start(t_map *map, t_pos *start);

//cleanup
void	free_index(t_index *index);
void 	clean_exit(t_index *index);
void	free_map(t_map *map);
void	free_textures(t_textures *tex);
void	error_file(void);
bool	tex_check(t_textures *tex);
bool	map_array_validation(t_map *map);
bool	validate_map_fill(t_map *map, t_pos *start);
void	free_pos(t_pos *pos);
void 	bool_array_clean(bool **visited, int map_height);

void	clean_exit_basic(t_index *index);
//error handling
void	ft_putstr_fd(char *s, int fd);

//map 
t_map	*map_prep(char *file, t_index *index);
t_map	*map_exist( int fd, t_map *map);
void	get_size(int fd, char *line, t_map *map);
t_map	*map_alloc(t_map *map, int fd);
void	print_map(t_map *map, t_pos *pos);
char	*map_setup(int fd, t_map *map, char *line);
int		*set_color(char *line, char id);
bool	check_file(const char *path);
t_map	*m_struct_alloc(void);
bool	is_empty_line(char *line);

bool	parse_texture_line(t_textures *tex, char *line, int step);
bool	valid_rgb_range(int *rgb);


//rendering debugging

int	render_frame(void *param);
void	render_minimap(t_index *idx);
void	my_mlx_pixel_put(t_cub3d *c, int x, int y, int color);
void	draw_rect(t_cub3d *c, int x, int y, int w, int h, int color);
void	draw_line(t_cub3d *c, int x0, int y0, int x1, int y1, int color);
void	clear_image(t_cub3d *c, int color);

int	handle_key(int keycode, t_index *idx);
void	render_3d(t_index *idx);
// void	rotate_player(t_index *idx, double angle);
// void	move_strafe(t_index *idx, int dir);
// void	move_forward_backward(t_index *idx, int dir);

#endif
