/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:53:22 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 16:56:32 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fit_to_window(t_map *map)
{
	double	span_x;
	double	span_y;
	double	zoom_x;
	double	zoom_y;

	span_x = map->col * map->interval;
	span_y = map->row * map->interval;
	zoom_x = (WIDTH * 0.5) / span_x;
	zoom_y = (HEIGHT * 0.5) / span_y;
	if (zoom_x < zoom_y)
		map->zoom = zoom_x;
	else
		map->zoom = zoom_y;
	if (map->zoom < 0.1)
		map->zoom = 0.1;
}
