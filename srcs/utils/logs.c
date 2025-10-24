/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:28:23 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/25 00:04:25 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	logs(t_fdf *fdf)
{
	printf("row: %d\ncol: %d\n", fdf->map->row, fdf->map->row);
	printf("high: %d\nlow: %d\n", fdf->map->high, fdf->map->low);
	logs_map_str(fdf);
	logs_map3d(fdf);
}

void	logs_map_str(t_fdf *fdf)
{
	int		row;
	int		col;

	row = -1;
	while (++row < fdf->map->row)
	{
		col = -1;
		while (++col < fdf->map->col)
		{
			printf("%s ", fdf->map->map_str[row][col]);
		}
		printf("\n");
	}
}

void	logs_map3d(t_fdf *fdf)
{
	int		row;
	int		col;

	row = -1;
	while (++row < fdf->map->row)
	{
		col = -1;
		while (++col < fdf->map->col)
		{
			printf("x:%f", fdf->map->map3d[row][col].x);
			printf("y:%f", fdf->map->map3d[row][col].y);
			printf("z:%f", fdf->map->map3d[row][col].z);
			printf("map_color:%u ", fdf->map->map3d[row][col].map_color);
		}
		printf("\n");
	}
}
