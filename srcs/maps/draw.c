/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:03:03 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 17:03:14 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "FdF Controls", 10, 10);
	mlx_put_string(fdf->mlx, "ESC    : Quit", 10, 40);
	mlx_put_string(fdf->mlx, "0      : Reset", 10, 60);
	mlx_put_string(fdf->mlx, "Arrows : Pan", 10, 80);
	mlx_put_string(fdf->mlx, "+/-    : Zoom", 10, 100);
	mlx_put_string(fdf->mlx, "X/Y/Z  : Rotate", 10, 120);
	mlx_put_string(fdf->mlx, "1/2/3  : Iso/dimetric/trimetric", 10, 140);
	mlx_put_string(fdf->mlx, "C      : Toggle colors", 10, 160);
	mlx_put_string(fdf->mlx, "S/A    : Increase/decrease z_scale", 10, 180);
}
