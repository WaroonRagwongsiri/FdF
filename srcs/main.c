/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:24:14 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/22 19:01:47 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_esc(void *params)
{
	mlx_t		*mlx;
	mlx_ctx_t	*mlx_ctx;
	mlx_image_t	*img;

	mlx = params;
	mlx_ctx = mlx->context;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_B))
	{
		img = (mlx_image_t *) (mlx_ctx->images->content);
		memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		img = (mlx_image_t *) (mlx_ctx->images->content);
		memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	}
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (mlx_terminate(mlx), EXIT_FAILURE);
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_loop_hook(mlx, press_esc, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
