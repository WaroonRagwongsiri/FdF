/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:36:46 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/23 17:24:28 by waragwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*parser(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(FILE_ERR);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		exit_error(MALLOC_ERR);
	}
	init_map(map);
	return (map);
}

void	set_dimension(t_map *map, int fd)
{
	int	line;
	int	line_split;

	line = get_next_line(fd);
	line_split = ft_split(line, ' ');
}
