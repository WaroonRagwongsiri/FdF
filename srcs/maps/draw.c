/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:13:10 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 19:13:14 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_point(t_map *map, int row, int col)
{
	t_point_3d	*ori;
	t_point_3d	p;
	t_point_2d	*new;

	ori = &(map->map3d[row][col]);
	new = &(map->map2d[row][col]);
	p.x = ori->x;
	p.y = ori->y;
	p.z = ori->z;
	rotate_x(&p.y, &p.z, map->x_rotate);
	rotate_y(&p.x, &p.z, map->y_rotate);
	rotate_z(&p.x, &p.y, map->z_rotate);
	new->x = (int)((p.x - p.y) * cos(map->alpha) * map->zoom + map->x_offset);
	new->y = (int)(((p.x + p.y) * sin(map->beta) - p.z) * map->zoom + map->y_offset);
	if (map->use_z_color)
		new->rgba = ori->z_color;
	else
		new->rgba = ori->map_color;
}

void	bresenham_step(t_point_2d *curr, t_point_2d a, t_point_2d b, int *err)
{
	err[1] = 2 * err[0];
	if (err[1] > -fabs(b.y - a.y))
	{
		err[0] -= fabs(b.y - a.y);
		curr->x += (a.x < b.x);
		curr->x -= (b.x < a.x);
	}
	if (err[1] < fabs(b.x - a.x))
	{
		err[0] += fabs(b.x - a.x);
		curr->y += (a.y < b.y);
		curr->y -= (b.y < a.y);
	}
}

void	bresenham(mlx_image_t *img, t_point_2d a, t_point_2d b)
{
	t_point_2d	curr;
	int			err[2];

	curr.x = a.x;
	curr.y = a.y;
	err[0] = fabs(b.x - a.x) - fabs(b.y - a.y);
	while (1)
	{
		if (curr.x >= 0 && curr.y >= 0)
		{
			if (curr.x < img->width && curr.y < img->height)
				mlx_put_pixel(img, curr.x, curr.y, ft_get_color(curr, a, b));
		}
		if (curr.x == b.x && curr.y == b.y)
			break ;
		bresenham_step(&curr, a, b, err);
	}
}

void	draw_line(t_fdf *fdf, int row, int col)
{
	t_map		*map;
	mlx_image_t	*img;

	map = fdf->map;
	img = fdf->screen;
	if (row == 0 && col == 0)
		project_point(map, row, col);
	if (row + 1 < map->row)
	{
		project_point(map, row + 1, col);
		bresenham(img, map->map2d[row][col], map->map2d[row + 1][col]);
	}
	if (col + 1 < map->col)
	{
		project_point(map, row, col + 1);
		bresenham(img, map->map2d[row][col], map->map2d[row][col + 1]);
	}
}

void	draw_image(void *param)
{
	int		row;
	int		col;
	t_fdf	*fdf;

	fdf = (t_fdf *) param;
	set_background(fdf->screen);
	row = -1;
	while (++row < fdf->map->row)
	{
		col = -1;
		while (++col < fdf->map->col)
			draw_line(fdf, row, col);
	}
}
