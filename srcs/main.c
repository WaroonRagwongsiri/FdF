/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:24:14 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/29 11:00:31 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || !is_valid_file_name(argv[1]))
		exit_error(FORMAT_ERR);
	fdf = init_fdf(argv[1]);
	if (!fdf->screen || mlx_image_to_window(fdf->mlx, fdf->screen, 0, 0) < 0)
	{
		mlx_terminate(fdf->mlx);
		exit_error_map(fdf->map, -1, MLX_ERR);
	}
	draw_menu(fdf);
	mlx_loop_hook(fdf->mlx, draw_image, fdf);
	mlx_key_hook(fdf->mlx, hooks, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_map(fdf->map);
	return (0);
}
