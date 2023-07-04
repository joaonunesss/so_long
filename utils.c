/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:56:37 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/28 15:29:17 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_msg(t_game *so_long)
{
	if (so_long->player != 1)
		return (11);
	else if (so_long->exit != 1)
		return (22);
	else if (so_long->total_coins < 1)
		return (33);
	return (EXIT_SUCCESS);
}

int	flood_fill(int total_coins, int cur_y, int cur_x, char **test_map)
{
	static int	coins;
	static int	exit;

	if (test_map[cur_y][cur_x] == WALL)
		return (0);
	else if (test_map[cur_y][cur_x] == COIN)
		coins++;
	else if (test_map[cur_y][cur_x] == EXIT)
		exit++;
	test_map[cur_y][cur_x] = WALL;
	flood_fill(total_coins, cur_y, cur_x + 1, test_map);
	flood_fill(total_coins, cur_y, cur_x - 1, test_map);
	flood_fill(total_coins, cur_y + 1, cur_x, test_map);
	flood_fill(total_coins, cur_y - 1, cur_x, test_map);
	if (coins == total_coins && exit == 1)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
