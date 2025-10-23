/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:03:53 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/23 18:09:01 by waragwon         ###   ########.fr       */
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
	free(map);
}

void	free_map2d(t_point_2d **map2d, int n)
{
	int	i;

	i = -1;
	while (++i < n && map2d[i])
		free(map2d[i]);
	free(map2d);
}

void	free_map3d(t_point_3d **map3d, int n)
{
	int	i;

	i = -1;
	while (++i < n && map3d[i])
		free(map3d[i]);
	free(map3d);
}
