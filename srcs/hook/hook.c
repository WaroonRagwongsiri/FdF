/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:48:32 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 20:30:19 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_reset(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = (t_fdf *) param;
	map = fdf->map;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
	if (keydata.key == MLX_KEY_0 && keydata.action == MLX_PRESS)
	{
		map->z_scale = 0.5;
		map->x_rotate = 0;
		map->y_rotate = 0;
		map->z_rotate = 0;
		map->alpha = ISO_ALPHA;
		map->beta = ISO_BETA;
		ft_fit_to_window(map);
	}
}

void	hook_rotate(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = (t_fdf *) param;
	map = fdf->map;
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_REPEAT)
		map->x_rotate += ROT_STEP;
	if (keydata.key == MLX_KEY_Y && keydata.action == MLX_REPEAT)
		map->y_rotate += ROT_STEP;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_REPEAT)
		map->z_rotate += ROT_STEP;
}

void	hook_view(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = (t_fdf *) param;
	map = fdf->map;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		map->x_offset -= PAN_STEP;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		map->x_offset += PAN_STEP;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		map->y_offset -= PAN_STEP;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		map->y_offset += PAN_STEP;
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_REPEAT)
		map->zoom *= ZOOM_STEP;
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_REPEAT)
		map->zoom /= ZOOM_STEP;
}

void	hook_z_scale(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = (t_fdf *) param;
	map = fdf->map;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		map->z_scale += Z_SCALE_STEP;
		if (map->z_scale > 5.0)
			map->z_scale = 5.0;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		map->z_scale -= Z_SCALE_STEP;
		if (map->z_scale < 0.1)
			map->z_scale = 0.1;
	}
}

void	hook_projection(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = (t_fdf *) param;
	map = fdf->map;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		map->use_z_color = !map->use_z_color;
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		map->alpha = ISO_ALPHA;
		map->beta = ISO_BETA;
	}
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
	{
		map->alpha = DIM_ALPHA;
		map->beta = DIM_BETA;
	}
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
	{
		map->alpha = TRI_ALPHA;
		map->beta = TRI_BETA;
	}
}
