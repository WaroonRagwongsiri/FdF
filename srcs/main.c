/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:24:14 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/24 21:15:03 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || !is_valid_file_name(argv[1]))
		exit_error(FORMAT_ERR);
	fdf = init_fdf(argv[1]);
	printf("row: %d\ncol: %d\n", fdf->map->row, fdf->map->row);
	free_map(fdf->map);
	return (0);
}
