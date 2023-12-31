/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:20:30 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/28 15:06:44 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(char *map_file)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game));
	create_map(&so_long, map_file);
	check_map(&so_long);
	launch_mlx(&so_long);
	load_sprites(&so_long);
	render_map(&so_long);
	mlx_hook(so_long.win, ON_KEYPRESS, KEYPRESS_MASK, check_key, &so_long);
	mlx_hook(so_long.win, ON_CLOSE, CLOSE_MASK, quit_game, &so_long);
	mlx_loop(so_long.mlx);
}

int	check_filename(char *str)
{
	if (ft_strnstr(str + ft_strlen(str) - 4, ".ber", 4))
		return (EXIT_SUCCESS);
	else
	{
		ft_printf("Error!\nInvalid file extension. Try <map_name>.ber");
		return (EXIT_FAILURE);
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		if (!check_filename(av[1]))
			launch_game(av[1]);
		else
			return (EXIT_FAILURE);
	}
	else
	{
		ft_printf("Error!\nInvalid number of arguments. ");
		ft_printf("Try <./so_long> <maps/map_name.ber>");
		return (EXIT_FAILURE);
	}
}
