/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waragwon <waragwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:36:46 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/23 19:01:31 by waragwon         ###   ########.fr       */
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
	set_row(map, fd);
	close(fd);
	return (map);
}

void	set_row(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		map->row += 1;
		line = get_next_line(fd);
	}
}
