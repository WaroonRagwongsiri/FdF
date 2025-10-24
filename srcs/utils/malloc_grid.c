/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:33:56 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/24 21:46:53 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	malloc_grid_and_update_interval(t_map *map)
{
	int	i;

	map->map3d = ft_calloc(map->row, sizeof(t_point_3d *));
	map->map2d = ft_calloc(map->row, sizeof(t_point_2d *));
	if (!map->map3d || !map->map2d)
	{
		free_map(map);
		exit_error(MALLOC_ERR);
	}
	i = -1;
	while (++i < map->row)
	{
		map->map3d[i] = ft_calloc(map->col, sizeof(t_point_3d));
		map->map2d[i] = ft_calloc(map->col, sizeof(t_point_2d));
		if (!map->map3d[i] || !map->map2d[i])
		{
			free_map(map);
			exit_error(MALLOC_ERR);
		}
	}
	map->interval = ft_min(WIDTH / map->col, HEIGHT / map->row) / 2;
	map->interval = ft_max(2, map->interval);
}
