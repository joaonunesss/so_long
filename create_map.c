/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:51:15 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/21 15:02:01 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*create_map(t_game *so_long)
{
	so_long->map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!so_long->map)
	{
		free(so_long->map);
		return (NULL);
	}
	return (so_long);
}

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

void	get_cols(t_game *so_long)
{
	so_long->cols = ft_strlen(so_long->map[0]);
}

void	read_map(t_game *so_long, char *map_file)
{
	int		fd;
	char	*line;
	int	i;

	i = -1;
	get_rows(so_long, map_file);

	so_long = create_map(so_long);
	if (!so_long->map)
		exit_error("Couldn't read map.");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_error("Couldn't open requested file.");
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
	close (fd);
}