/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:00 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/23 18:26:44 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Initial Fdf
t_fdf	*init_fdf(char *filename)
{
	static t_fdf	fdf;

	fdf.map = parser(filename);
	return (&fdf);
}

// Initial map
// row = 0;
// col = 0;
// high = INT_MIN;
// low = INT_MAX;
// use_z_color = false;
// x_offset = WIDTH / 2;
// y_offset = HEIGHT / 2;
// interval = 0;
// alpha = ISO_ALPHA;
// beta = ISO_BETA;
// x_proj = 0;
// y_proj = 0;
// z_proj = 0;
// zoom = 1;
// z_scale = 1;
// map2d = NULL;
// map3d = NULL;
void	init_map(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->high = INT_MIN;
	map->low = INT_MAX;
	map->use_z_color = false;
	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 2;
	map->interval = 0;
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
