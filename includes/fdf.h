/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:19:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/23 17:20:06 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include "../get_next_line/get_next_line.h"
# include <string.h>
# include <limits.h>
# include <fcntl.h>

# define FORMAT_ERR "Usage : ./fdf_linux <filename>.fdf"
# define FILE_ERR "File cannot openned"
# define MALLOC_ERR "Malloc Failed"

# define WIDTH 1920
# define HEIGHT 1080

# define ISO_ALPHA 0.615479
# define ISO_BETA  0.785398

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

// Fdf
t_fdf	*init_fdf(char *filename);
void	init_map(t_map *map);

// Parser
t_map	*parser(char *filename);

#endif