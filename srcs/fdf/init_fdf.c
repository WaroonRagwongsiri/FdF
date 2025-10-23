/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:00 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/23 16:34:15 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(char *filename)
{
	static t_fdf	fdf;

	init_map(fdf.map);
	return (&fdf);
}

void	init_map(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->high = INT_MIN;
	map->high = INT_MAX;
	map->use_z_color = false;
	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 2;
	map->alpha = ISO_ALPHA;
	map->beta = ISO_BETA;
	map->x_proj = 0;
	map->y_proj = 0;
	map->z_proj = 0;
	map->zoom = 1;
	map->z_scale = 1;
	map->map2d = NULL;
	map->map3d = NULL;
}
