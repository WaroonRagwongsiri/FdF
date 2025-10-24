/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:28:23 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/24 22:31:17 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	logs(t_fdf *fdf)
{
	int		row;
	int		col;

	printf("row: %d\ncol: %d\n", fdf->map->row, fdf->map->row);
	printf("high: %d\nlow: %d\n", fdf->map->high, fdf->map->low);
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
