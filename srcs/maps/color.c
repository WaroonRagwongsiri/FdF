/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:48:13 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 23:40:21 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_z_color(double z_raw, double low, double high)
{
	double	norm;

	if (high <= low)
		return (WHITE);
	norm = (z_raw - low) / (high - low);
	if (norm < 0.1)
		return (BLUE);
	if (norm < 0.2)
		return (CYAN_BLUE);
	if (norm < 0.3)
		return (CYAN);
	if (norm < 0.4)
		return (AQUA_GREEN);
	if (norm < 0.5)
		return (GREEN);
	if (norm < 0.6)
		return (YELLOW_GREEN);
	if (norm < 0.7)
		return (YELLOW);
	if (norm < 0.8)
		return (ORANGE);
	if (norm < 0.9)
		return (RED);
	return (PURPLE);
}

void	set_z_color(t_map *map)
{
	int			col;
	int			row;
	double		z_raw;
	t_point_3d	*point;

	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
		{
			point = &(map->map3d[row][col]);
			z_raw = point->z / map->interval;
			point->z_color = ft_z_color(z_raw, map->low, map->high);
		}
	}
}

void	set_background(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	while ((uint32_t)x < img->width)
	{
		y = 0;
		while ((uint32_t)y < img->height)
		{
			mlx_put_pixel(img, x, y, BACKGROUND);
			y++;
		}
		x++;
	}
}
