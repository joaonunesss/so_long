/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:56:37 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/22 17:16:30 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(int total_coins, int cur_y, int cur_x, char **test_map)
{
	static int	coins = 0;
	static int	exit = 0;

	if (test_map[cur_y][cur_x] == WALL)
		return(1);
	else if (test_map[cur_y][cur_x] == COIN)
		coins++;
	else if (test_map[cur_y][cur_x] == EXIT)
		exit++;
	test_map[cur_y][cur_x] = WALL;
	flood_fill(total_coins, cur_y, cur_x + 1, test_map);
	flood_fill(total_coins, cur_y, cur_x - 1, test_map);
	flood_fill(total_coins, cur_y + 1, cur_x, test_map);
	flood_fill(total_coins, cur_y - 1, cur_x, test_map);
	if(coins == total_coins && exit == 1)
		return(0);
	else
		return(1);
}

void	move_player(t_game *so_long)
{
	static int flag = 0;
	if(flag)
	{
		so_long->map[so_long->cur.y][so_long->cur.x] = PLAYER;
		so_long->map[so_long->prev.y][so_long->prev.x] = EXIT;
		flag = 0;
	}
	else if(so_long->map[so_long->cur.y][so_long->cur.x] == EXIT)
	{
		so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;
		flag = 1;
	}
	else
		so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;  
	so_long->map[so_long->cur.y][so_long->cur.x] = PLAYER;
	render_positions(so_long, so_long->prev.x, so_long->prev.y);
	render_positions(so_long, so_long->cur.x, so_long->cur.y);
}

int check_key(int key, t_game *so_long)
{
	so_long->prev.y = so_long->cur.y;
	so_long->prev.x = so_long->cur.x;
    if (key == ESC)
		quit_game(so_long);
	else if (key == W || key == UP)
		so_long->cur.y--;
	else if (key == S || key == DOWN)
		so_long->cur.y++;
	else if (key == A || key == LEFT)
		so_long->cur.x--;
	else if (key == D || key == RIGHT)
		so_long->cur.x++;
	if(so_long->map[so_long->cur.y][so_long->cur.x] != WALL)
	{	
		if (key == W || key == A || key == D || key == S \
			|| key == UP || key == DOWN || key == LEFT || key == RIGHT)
			ft_printf("Moves: %i\n", ++so_long->moves);
		if (so_long->map[so_long->cur.y][so_long->cur.x] == COIN)
			so_long->coins++;
		else if (so_long->map[so_long->cur.y][so_long->cur.x] == EXIT \
					&& so_long->coins == so_long->total_coins)
		{
				ft_printf("Good job!\n");
				quit_game(so_long);
		}
		move_player(so_long);
	}
	else
	{
		so_long->cur.y = so_long->prev.y;
		so_long->cur.x = so_long->prev.x;
	}
	return (key);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	if (!so_long->sprites)
		exit(1);
	else
		exit(0);
}

int	exit_error(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit (1);
}