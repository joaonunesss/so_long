/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:56:37 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/21 17:04:24 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(int total_coins, int cur_y, int cur_x, char **test_map)
{
	static int	coins = 0;
	static int	exit = 0;

	if (test_map[cur_y][cur_x] == WALL)
		return (0);
	else if (test_map[cur_y][cur_x] == COIN)
		coins++;
	else if (test_map[cur_y][cur_x] == EXIT)
		exit = 1;
	test_map[cur_y][cur_x] = WALL;
	flood_fill(total_coins, cur_y, cur_x + 1, test_map);
	flood_fill(total_coins, cur_y, cur_x - 1, test_map);
	flood_fill(total_coins, cur_y + 1, cur_x, test_map);
	flood_fill(total_coins, cur_y - 1, cur_x, test_map);
	return (coins == total_coins && exit == 1);
}

void	move_player(t_game *so_long)
{
	so_long->prev.y = so_long->cur.y;
	so_long->prev.x = so_long->cur.x;
	so_long->cur.y = so_long->next.y;
	so_long->cur.x = so_long->next.x;
	so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;  
	so_long->map[so_long->cur.y][so_long->cur.x] = PLAYER;
	render_positions(so_long, so_long->prev.x, so_long->prev.y);
	render_positions(so_long, so_long->cur.x, so_long->cur.y);
}

int check_keypress(int key, t_game *so_long)
{
	int pos_y;
	int pos_x;

	pos_y = so_long->next.y;
	pos_x = so_long->next.x;
    if (key == ESC)
		quit_game(so_long);
	else if (key == W)
		so_long->next.y--;
	else if (key == S)
		so_long->next.y++;
	else if (key == A)
		so_long->next.x--;
	else if (key == D)
		so_long->next.x++;
	if(so_long->map[so_long->next.y][so_long->next.x] != WALL)
	{	
		if (key == W || key == A || key == D || key == S)
			ft_printf("Moves: %i\n", ++so_long->moves);
		if (so_long->map[so_long->next.y][so_long->next.x] == COIN)
			so_long->coins++;
		else if (so_long->map[so_long->next.y][so_long->next.x] == EXIT \
					&& so_long->coins == so_long->total_coins)
				quit_game(so_long);
		move_player(so_long);
	}
	else
	{
		so_long->next.y = pos_y;
		so_long->next.x = pos_x;
	}
	return (key);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(0);
}

int	exit_error(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit (EXIT_FAILURE);
}