/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corlor_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:20:13 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 23:43:00 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	interpolate_channel(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

double	get_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_channel(int color, int shift)
{
	return ((color >> shift) & 0xFF);
}

int	ft_get_color(t_point_2d cur, t_point_2d a, t_point_2d b)
{
	double	percent;
	int		red;
	int		green;
	int		blue;

	if (a.rgba == b.rgba)
		return (a.rgba);
	if (fabs(b.x - a.x) > fabs(b.y - a.y))
		percent = get_percent(a.x, b.x, cur.x);
	else
		percent = get_percent(a.y, b.y, cur.y);
	red = interpolate_channel(get_channel(a.rgba, 24),
			get_channel(b.rgba, 24), percent);
	green = interpolate_channel(get_channel(a.rgba, 16),
			get_channel(b.rgba, 16), percent);
	blue = interpolate_channel(get_channel(a.rgba, 8),
			get_channel(b.rgba, 8), percent);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}
