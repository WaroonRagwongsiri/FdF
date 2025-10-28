/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:15:19 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/28 19:17:43 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double *y, double *z, double alpha)
{
	double	new_y;
	double	new_z;

	new_y = (*y) * cos(alpha) - (*z) * sin(alpha);
	new_z = (*y) * sin(alpha) + (*z) * cos(alpha);
	*y = new_y;
	*z = new_z;
}

void	rotate_y(double *x, double *z, double beta)
{
	double	new_x;
	double	new_z;

	new_x = (*x) * cos(beta) - (*z) * sin(beta);
	new_z = (*x) * sin(beta) + (*z) * cos(beta);
	*x = new_x;
	*z = new_z;
}

void	rotate_z(double *x, double *y, double gamma)
{
	double	new_x;
	double	new_y;

	new_x = (*x) * cos(gamma) - (*y) * sin(gamma);
	new_y = (*x) * sin(gamma) + (*y) * cos(gamma);
	*x = new_x;
	*y = new_y;
}
