/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:49:19 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/25 00:04:15 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*parse_dim(char *filename)
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
	map_dimension(map, fd);
	if (map->row == 0 || map->col == 0)
		exit_error_map(map, fd, INVALID_MAP);
	close(fd);
	return (map);
}

void	map_dimension(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	map->col = count_word_split(line, ' ');
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (count_word_split(line, ' ') == 0)
			;
		else if (map->col != (int) count_word_split(line, ' '))
		{
			free(line);
			exit_error_map(map, fd, INVALID_MAP);
		}
		free(line);
		line = get_next_line(fd);
		map->row++;
	}
}
