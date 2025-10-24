/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:35:31 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/25 00:01:23 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map3d(t_map *map)
{
	int			row;
	int			col;
	t_point_3d	*point;

	set_offset(map);
	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
		{
			point = &(map->map3d[row][col]);
			point->x = convert_x(col, map);
			point->y = convert_y(row, map);
			point->z = ft_atoi(map->map_str[row][col]) * (map->interval);
			point->map_color = convert_rgba(map->map_str[row][col], map);
		}
	}
}
