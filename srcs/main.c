/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:24:14 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/22 20:00:53 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_keyhook(mlx_key_data_t keydata, void *params)
{
	mlx_t		*mlx;
	mlx_ctx_t	*mlx_ctx;
	mlx_image_t	*img;

	mlx = params;
	mlx_ctx = mlx->context;
	img = (mlx_image_t *)(mlx_ctx->images->content);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		img->instances->y -= 5;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		img->instances->y += 5;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		img->instances->x -= 5;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		img->instances->x += 5;
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, 100, 100);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (mlx_terminate(mlx), EXIT_FAILURE);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
