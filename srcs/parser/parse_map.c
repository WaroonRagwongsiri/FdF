/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:49:01 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/10/24 22:20:38 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		row;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error_map(map, fd, FILE_ERR);
	map->map_str = ft_calloc(map->row + 1, sizeof(char **));
	if (!map->map_str)
		exit_error_map(map, fd, MALLOC_ERR);
	row = -1;
	while (++row < map->row)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error_map(map, fd, MALLOC_ERR);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->map_str[row] = ft_split(line, ' ');
		if (!map->map_str[row])
			exit_error_map(map, fd, MALLOC_ERR);
		free(line);
	}
	clear_gnl(fd);
	update_map_low_high(map);
}

void	update_map_low_high(t_map *map)
{
	int	row;
	int	col;
	int	altitude;

	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
		{
			altitude = ft_atoi(map->map_str[row][col]);
			map->low = ft_min(map->low, altitude);
			map->high = ft_max(map->high, altitude);
		}
	}
}
