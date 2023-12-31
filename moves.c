/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:16:26 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/23 13:38:05 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *so_long)
{
	static int	flag;

	if (flag)
	{
		so_long->map[so_long->cur.y][so_long->cur.x] = PLAYER;
		so_long->map[so_long->prev.y][so_long->prev.x] = EXIT;
		flag = 0;
	}
	else if (so_long->map[so_long->cur.y][so_long->cur.x] == EXIT)
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

void	check_move(t_game *so_long, int key)
{
	if (so_long->map[so_long->cur.y][so_long->cur.x] != WALL)
	{
		if (key == W || key == A || key == D || key == S || key == UP
			|| key == DOWN || key == LEFT || key == RIGHT)
			ft_printf("Moves: %i\n", ++so_long->moves);
		if (so_long->map[so_long->cur.y][so_long->cur.x] == COIN)
			so_long->coins++;
		else if (so_long->map[so_long->cur.y][so_long->cur.x] == EXIT
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
}

int	check_key(int key, t_game *so_long)
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
	check_move(so_long, key);
	return (key);
}
