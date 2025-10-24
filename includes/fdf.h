/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:19:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/24 22:30:38 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include "get_next_line.h"
# include <string.h>
# include <limits.h>
# include <fcntl.h>

# define BACKGROUND 0x101018FF

# define BLUE 0x0000FFFF
# define CYAN_BLUE 0x0080FFFF
# define CYAN 0x00FFFFFF
# define AQUA_GREEN 0x00FF80FF
# define GREEN 0x00FF00FF
# define YELLOW_GREEN 0x80FF00FF
# define YELLOW 0xFFFF00FF
# define ORANGE 0xFF8000FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define PURPLE 0x800080FF

# define FORMAT_ERR "Usage : ./fdf_linux <filename>.fdf"
# define FILE_ERR "File cannot openned"
# define MALLOC_ERR "Malloc Failed"
# define INVALID_MAP "Invalid Map"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point_3d
{
	double	x;
	double	y;
	double	z;
	int		map_color;
	int		z_color;
}	t_point_3d;

typedef struct s_point_2d
{
	int	x;
	int	y;
	int	z;
	int	rgba;
}	t_point_2d;

typedef struct s_map
{
	int			row;
	int			col;
	int			high;
	int			low;
	bool		use_z_color;
	double		x_offset;
	double		y_offset;
	double		interval;
	double		alpha;
	double		beta;
	double		x_proj;
	double		y_proj;
	double		z_proj;
	double		zoom;
	double		z_scale;
	t_point_2d	**map2d;
	t_point_3d	**map3d;
	char		***map_str;
}	t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_map		*map;
}	t_fdf;

// Utils
void	exit_error(char *err_msg);
bool	is_valid_file_name(char *filename);
bool	is_readable_file(char *filename);
void	exit_error_map(t_map *map, int fd, char *err_msg);
void	free_map(t_map *map);
void	free_map2d(t_point_2d **map2d, int n);
void	free_map3d(t_point_3d **map3d, int n);
void	free_str_arr(char ***arr);
void	update_map_low_high(t_map *map);
void	malloc_grid_and_update_interval(t_map *map);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	clear_gnl(int fd);
void	logs(t_fdf *fdf);

// Fdf
t_fdf	*init_fdf(char *filename);
void	init_map(t_map *map);

// parse_dim
t_map	*parse_dim(char *filename);
void	map_dimension(t_map *map, int fd);
void	parse_map(t_map *map, char *filename);

#endif