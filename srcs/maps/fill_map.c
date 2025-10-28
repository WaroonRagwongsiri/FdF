/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:35:31 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/28 20:34:28 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map3d(t_map *map)
{
	int			row;
	int			col;
	t_point_3d	*point;

	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
		{
			point = &(map->map3d[row][col]);
			point->x = convert_x(col, map);
			point->y = convert_y(row, map);
			point->z = (double)ft_atoi(map->map_str[row][col]) * (map->interval);
			point->map_color = convert_rgba(map->map_str[row][col], map);
		}
	}
}
