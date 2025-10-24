/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:40:29 by waragwon          #+#    #+#             */
/*   Updated: 2025/10/25 00:04:48 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_valid_file_name(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (ft_strncmp(&filename[len - 4], ".fdf", 5) != 0)
		return (false);
	return (true);
}

bool	is_readable_file(char *filename)
{
	if (access(filename, F_OK | R_OK) == -1)
		return (false);
	return (true);
}
