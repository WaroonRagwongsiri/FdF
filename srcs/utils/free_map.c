/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:03:53 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/24 22:12:32 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map2d)
		free_map2d(map->map2d, map->row);
	if (map->map3d)
		free_map3d(map->map3d, map->row);
	if (map->map_str)
		free_str_arr(map->map_str);
	free(map);
}

void	free_map2d(t_point_2d **map2d, int n)
{
	int	i;

	if (!map2d)
		return ;
	i = -1;
	while (++i < n && map2d[i])
		free(map2d[i]);
	free(map2d);
}

void	free_map3d(t_point_3d **map3d, int n)
{
	int	i;

	if (!map3d)
		return ;
	i = -1;
	while (++i < n && map3d[i])
		free(map3d[i]);
	free(map3d);
}

void	free_str_arr(char ***arr)
{
	int	row;
	int	col;

	if (!arr)
		return ;
	row = 0;
	while (arr[row])
	{
		col = 0;
		while (arr[row][col])
		{
			free(arr[row][col]);
			col++;
		}
		free(arr[row]);
		row++;
	}
	free(arr);
}
