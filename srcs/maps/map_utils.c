/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:44:46 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/28 23:43:11 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	convert_x(int c, t_map *map)
{
	int	offset;

	offset = (map->col - 1) * map->interval / 2;
	return ((double)c * (map->interval) - offset);
}

double	convert_y(int r, t_map *map)
{
	int	offset;

	offset = (map->row - 1) * map->interval / 2;
	return ((double)r * (map->interval) - offset);
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
