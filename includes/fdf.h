/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:19:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/23 15:45:14 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include <string.h>

# define FORMAT_ERR "Usage : ./fdf_linux <filename>.fdf"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point_3d
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	z_color;
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
int		valid_file_name(char *filename);

// Fdf
t_fdf	*init_fdf(char *filename);

#endif