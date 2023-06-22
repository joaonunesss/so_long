/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:30:18 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/21 15:26:36 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(t_game *so_long)
{
	int	i;
	int	fst_row_len;

	i = 0;
	fst_row_len = ft_strlen(so_long->map[0]);
	while (i < so_long->rows)
	{
		if (ft_strlen(so_long->map[i]) != fst_row_len)
			return (0);
        i++;
	}
	get_cols(so_long);
	return (1);
}

int	check_walls(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < so_long->rows)
		if (so_long->map[i][0] != WALL || so_long->map[i][so_long->cols - 1] != WALL)
			return (0);
	i = -1;
	while (++i < so_long->cols)
		if (so_long->map[0][i] != WALL || so_long->map[so_long->rows - 1][i] != WALL)
			return (0);
	return (1);
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
				so_long->cur = (t_position){j, i};
				so_long->next = so_long->cur;
			}
			else if (so_long->map[i][j] == EXIT)
				so_long->exit++;
			else if (so_long->map[i][j] == COIN)
				so_long->total_coins++;
			else if (!ft_strchr("01CEP", so_long->map[i][j]))
				return (0);
		}
	}
	return (so_long->player == 1 && so_long->exit == 1 && so_long->total_coins >= 1);
}

int	check_paths(t_game *so_long)
{
	int	i;
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
	reach_exit = flood_fill(so_long->total_coins, so_long->cur.y, so_long->cur.x, test_map);
	clean_test_map(test_map);
	return (reach_exit);
}

void    check_map(t_game *so_long)
{
	if (!so_long->rows)
		exit_error("Map is empty.");
	if (!check_format(so_long))
		exit_error("Map is not a rectangle.");
	if (!check_walls(so_long))
		exit_error("Map is not surrounded by walls.");
	if (!check_sprites(so_long))
		exit_error("Map has invalid sprites.");
	if (!check_paths(so_long))
		exit_error("Map has invalid path.");
}