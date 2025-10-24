/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:44:46 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/25 00:02:35 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_offset(t_map *map)
{
	map->x_offset = (map->col - 1) * map->interval / 2;
	map->y_offset = (map->row - 1) * map->interval / 2;
}

double	convert_x(int col, t_map *map)
{
	return ((double)col * (map->interval) - map->x_offset);
}

double	convert_y(int row, t_map *map)
{
	return ((double)row * (map->interval) - map->y_offset);
}

int	convert_rgba(char *point, t_map	*map)
{
	int	i;
	int	rgba;

	i = 0;
	while (point[i] >= '0' && point[i] <= '9')
		i++;
	if (point[i] != ',')
		return (WHITE);
	if (ft_strncmp(&point[i], ",0x", 3) != 0
		&& ft_strncmp(&point[i], ",0X", 3) != 0)
		exit_error_map(map, -1, INVALID_MAP);
	i += 3;
	str_to_upper(&point[i]);
	rgba = ft_atoi_base(&point[i], "0123456789ABCDEF");
	return (rgba << 8 | 0xFF);
}
