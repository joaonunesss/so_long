/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sl_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:51:15 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/22 15:16:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_rows(t_game *so_long, char *map_file)
{
	int		fd;
	char	*line;

	so_long->rows = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("Couldn't open requested file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		so_long->rows++;
	}
	close (fd);
}

void	read_map(t_game *so_long, char *map_file, int fd)
{
	int	i;
	char	*line;

	i = -1;
	while (++i < so_long->rows)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error("Couldn't read map.");
		so_long->map[i] = ft_strtrim(line, "\n");
		if (!so_long->map[i])
			exit_error("Couldn't read map.");
		free(line);
	}
}

void	create_map(t_game *so_long, char *map_file)
{
	int		fd;
	
	get_rows(so_long, map_file);
	so_long->map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!so_long->map)
	{
		free(so_long->map);
		exit_error("Couldn't create so_long->map.");
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("Couldn't open requested file.");
	read_map(so_long, map_file, fd);
	close (fd);
}