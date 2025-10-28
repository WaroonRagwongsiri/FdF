/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:19:07 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/29 00:15:32 by waragwon         ###   ########.fr       */
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
# include <math.h>

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

# define ISO_ALPHA 0.46373398	// ~26.57°
# define ISO_BETA 0.46373398	// ~26.57°
# define DIM_ALPHA 0.46373398	// ~26.57°
# define DIM_BETA 0.78539816	// ~45.00°
# define TRI_ALPHA 0.52359878	// ~30.00°
# define TRI_BETA 0.78539816	// ~45.00°

# define ROT_STEP 0.03		// rotation speed (radians per tick)
# define PAN_STEP 10.0		// pixels per tick
# define ZOOM_STEP 1.05		// zoom factor
# define Z_SCALE_STEP 0.05	// how much zscale changes per tick

# define FORMAT_ERR "Usage : ./fdf_linux <filename>.fdf"
# define FILE_ERR "File cannot openned"
# define MALLOC_ERR "Malloc Failed"
# define INVALID_MAP "Invalid Map"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point_3d
{
	double			x;
	double			y;
	double			z;
	unsigned int	map_color;
	unsigned int	z_color;
}	t_point_3d;

typedef struct s_point_2d
{
	double			x;
	double			y;
	unsigned int	rgba;
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
	double		x_rotate;
	double		y_rotate;
	double		z_rotate;
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
void			exit_error(char *err_msg);
bool			is_valid_file_name(char *filename);
bool			is_readable_file(char *filename);
void			exit_error_map(t_map *map, int fd, char *err_msg);
void			free_map(t_map *map);
void			free_map2d(t_point_2d **map2d, int n);
void			free_map3d(t_point_3d **map3d, int n);
void			free_str_arr(char ***arr);
void			update_map_low_high(t_map *map);
void			malloc_grid_and_update_interval(t_map *map);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			clear_gnl(int fd);
void			str_to_upper(char *str);

// Logs
void			logs(t_fdf *fdf);
void			logs_map_str(t_fdf *fdf);
void			logs_map3d(t_fdf *fdf);

// Fdf
t_fdf			*init_fdf(char *filename);
void			init_map(t_map *map);

// parse_dim
t_map			*parse_dim(char *filename);
void			map_dimension(t_map *map, int fd);
void			parse_map(t_map *map, char *filename);

// Maps
void			fill_map3d(t_map *map);
double			convert_x(int col, t_map *map);
double			convert_y(int row, t_map *map);
int				convert_rgba(char *point, t_map	*map);
void			ft_fit_to_window(t_map *map);

// Colors
unsigned int	ft_z_color(double z_raw, double low, double high);
void			set_z_color(t_map *map);
void			set_background(mlx_image_t *img);

// Draws
void			draw_menu(t_fdf *fdf);
void			project_point(t_map *map, int row, int col);
void			bresenham_step(t_point_2d *curr, t_point_2d a,\
								t_point_2d b, int *err);
void			bresenham(mlx_image_t *img, t_point_2d a, t_point_2d b);
void			draw_line(t_fdf *fdf, int row, int col);
void			draw_image(void *param);

// Draws Utils
void			rotate_x(double *y, double *z, double alpha);
void			rotate_y(double *x, double *z, double beta);
void			rotate_z(double *x, double *y, double gamma);

// Colors inter
int				interpolate_channel(int start, int end, double percent);
double			get_percent(int start, int end, int current);
int				get_channel(int color, int shift);
int				ft_get_color(t_point_2d cur, t_point_2d a, t_point_2d b);

// Hooks
void			hooks(mlx_key_data_t keydata, void *param);
void			hook_reset(mlx_key_data_t keydata, void *param);
void			hook_rotate(mlx_key_data_t keydata, void *param);
void			hook_view(mlx_key_data_t keydata, void *param);
void			hook_z_scale(mlx_key_data_t keydata, void *param);
void			hook_projection(mlx_key_data_t keydata, void *param);

#endif