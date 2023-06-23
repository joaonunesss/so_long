/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:30:18 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/23 13:37:36 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(t_game *so_long)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(so_long->map[0]);
	while (i < so_long->rows)
	{
		if (ft_strlen(so_long->map[i]) != row_len)
			return (1);
		i++;
	}
	so_long->cols = ft_strlen(so_long->map[0]);
	return (0);
}

int	check_walls(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < so_long->rows)
		if (so_long->map[i][0] != WALL || so_long->map[i][so_long->cols
			- 1] != WALL)
			return (1);
	i = -1;
	while (++i < so_long->cols)
		if (so_long->map[0][i] != WALL || so_long->map[so_long->rows
			- 1][i] != WALL)
			return (1);
	return (0);
}

int	check_sprites(t_game *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->rows)
	{
		j = -1;
		while (++j < so_long->cols)
		{
			if (so_long->map[i][j] == PLAYER)
			{
				so_long->player++;
				so_long->cur.x = j;
				so_long->cur.y = i;
			}
			else if (so_long->map[i][j] == EXIT)
				so_long->exit++;
			else if (so_long->map[i][j] == COIN)
				so_long->total_coins++;
			else if (!ft_strchr("01CEP", so_long->map[i][j]))
				return (4);
		}
	}
	return (return_msg(so_long));
}

int	check_paths(t_game *so_long)
{
	int		i;
	int		reach_exit;
	char	**test_map;

	i = -1;
	reach_exit = 0;
	test_map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!test_map)
		exit_error("Malloc failed.");
	while (++i < so_long->rows)
	{
		test_map[i] = ft_strdup(so_long->map[i]);
		{
			if (!test_map[i])
			{
				clean_test_map(test_map);
				exit_error("Malloc failed.");
			}
		}
	}
	reach_exit = flood_fill(so_long->total_coins, so_long->cur.y, \
			so_long->cur.x, test_map);
	clean_test_map(test_map);
	return (reach_exit);
}

void	check_map(t_game *so_long)
{
	int	i;

	if (!so_long->rows)
		exit_error("Map is empty.");
	if (check_format(so_long))
		exit_error("Map is not a rectangle.");
	if (check_walls(so_long))
		exit_error("Map is not surrounded by walls.");
	i = check_sprites(so_long);
	if (i == 1)
		exit_error("Map has invalid number of players.");
	else if (i == 2)
		exit_error("Map has invalid number of exits.");
	else if (i == 3)
		exit_error("Map has invalid number of coins.");
	else if (i == 4)
		exit_error("Map has invalid characters.");
	if (check_paths(so_long))
		exit_error("Map has invalid path.");
}
