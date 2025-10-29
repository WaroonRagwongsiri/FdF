/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:00 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/29 10:59:25 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Initial Fdf
t_fdf	*init_fdf(char *filename)
{
	static t_fdf	fdf;

	fdf.map = parse_dim(filename);
	parse_map(fdf.map, filename);
	malloc_grid_and_update_interval(fdf.map);
	fill_map3d(fdf.map);
	set_z_color(fdf.map);
	ft_fit_to_window(fdf.map);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf.mlx)
		exit_error_map(fdf.map, -1, MLX_ERR);
	fdf.screen = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	return (&fdf);
}

// Initial map
// row = 0;
// col = 0;
// high = INT_MIN;
// low = INT_MAX;
// use_z_color = false;
// x_offset = WIDTH / 2;
// y_offset = HEIGHT / 2;
// interval = 0;
// alpha = ISO_ALPHA;
// beta = ISO_BETA;
// x_rotate = 0;
// y_rotate = 0;
// z_rotate = 0;
// zoom = 1;
// z_scale = 0.5;
// map2d = NULL;
// map3d = NULL;
void	init_map(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->high = INT_MIN;
	map->low = INT_MAX;
	map->use_z_color = false;
	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 2;
	map->interval = 0;
	map->alpha = ISO_ALPHA;
	map->beta = ISO_BETA;
	map->x_rotate = 0;
	map->y_rotate = 0;
	map->z_rotate = 0;
	map->zoom = 1;
	map->z_scale = 0.5;
	map->map2d = NULL;
	map->map3d = NULL;
	map->map_str = NULL;
}
