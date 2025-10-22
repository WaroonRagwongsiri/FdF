/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:24:14 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/22 19:29:29 by waragwon         ###   ########.fr       */
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
	img = (mlx_image_t *)(mlx_ctx->images->next->content);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_B && keydata.action == MLX_RELEASE)
		memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		img->enabled = !img->enabled;
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img1;
	mlx_image_t	*img2;

	mlx = mlx_init(WIDTH, HEIGHT, "Fdf", false);
	if (!mlx)
		return (EXIT_FAILURE);
	img1 = mlx_new_image(mlx, 256, 256);
	img2 = mlx_new_image(mlx, 256, 256);
	if (!img1 || !img2 || (mlx_image_to_window(mlx, img1, 0, 0) < 0) || \
		(mlx_image_to_window(mlx, img2, 256, 256) < 0))
		return (mlx_terminate(mlx), EXIT_FAILURE);
	memset(img1->pixels, 255, img1->width * img1->height * sizeof(int32_t));
	memset(img2->pixels, 255, img1->width * img1->height * sizeof(int32_t));
	mlx_key_hook(mlx, &my_keyhook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
