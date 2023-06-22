/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:34:15 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/22 15:22:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    launch_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		exit_error("Failed to initialize mlx.");
	so_long->win = mlx_new_window(so_long->mlx, \
			so_long->cols * SIZE, so_long->rows * SIZE, "so_long");
	if (!so_long->win)
		exit_error("Failed to create window.");
}

void    load_sprites(t_game *so_long)
{
	so_long->sprites = malloc(SPRITES * sizeof(t_sprite));
	if (!so_long->sprites)
	{
		ft_printf("Failed to allocate memory on sprites.");
		quit_game(so_long);
	}
	so_long->sprites[W1].img = mlx_xpm_file_to_image(so_long->mlx, FW1, \
			&(so_long->sprites[W1].width), &(so_long->sprites[W1].height));
	so_long->sprites[S1].img = mlx_xpm_file_to_image(so_long->mlx, FS1, \
			&(so_long->sprites[S1].width), &(so_long->sprites[S1].height));
	so_long->sprites[C1].img = mlx_xpm_file_to_image(so_long->mlx, FC1, \
			&(so_long->sprites[C1].width), &(so_long->sprites[C1].height));
	so_long->sprites[E1].img = mlx_xpm_file_to_image(so_long->mlx, FE1, \
			&(so_long->sprites[E1].width), &(so_long->sprites[E1].height));
	so_long->sprites[P1].img = mlx_xpm_file_to_image(so_long->mlx, FP1, \
			&(so_long->sprites[P1].width), &(so_long->sprites[P1].height));
}

void    render_map(t_game *so_long)
{
    int  x;
    int  y;

    y = -1;
	while (++y < so_long->rows)
	{
		x = -1;
		while (++x < so_long->cols)
			render_positions(so_long, x, y);
	}
}

void    render_positions(t_game *so_long, int x, int y)
{
	t_sprite	sp;

	if (so_long->map[y][x] == WALL)
		sp = so_long->sprites[W1];
	else if (so_long->map[y][x] == COIN)
		sp = so_long->sprites[C1];
	else if (so_long->map[y][x] == EXIT)
		sp = so_long->sprites[E1];
	else if (so_long->map[y][x] == SPACE)
		sp = so_long->sprites[S1];
	else if (so_long->map[y][x] == PLAYER)
		sp = so_long->sprites[P1];
	mlx_put_image_to_window(so_long->mlx, so_long->win, \
		sp.img, sp.width * x, sp.height * y);
}