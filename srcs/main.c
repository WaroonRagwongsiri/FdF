/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:24:14 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/23 19:01:12 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2 || !is_valid_file_name(argv[1]))
		exit_error(FORMAT_ERR);
	fdf = init_fdf(argv[1]);
	free_map(fdf->map);
	return (0);
}
