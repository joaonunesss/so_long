/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:46:01 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/28 16:00:55 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"

# define SIZE		32
# define SPRITES	5

# define FW1		"sprites/wall2.xpm"
# define FS1		"sprites/background2.xpm"
# define FC1		"sprites/colectible2.xpm"
# define FE1		"sprites/exit2.xpm"
# define FP1		"sprites/player2.xpm"

# define SPACE		'0'
# define WALL		'1'
# define COIN		'C'
# define EXIT		'E'
# define PLAYER		'P'

# define ON_KEYPRESS 2
# define ON_CLOSE 17

# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

# define W1 0
# define S1 1
# define C1 2
# define E1 3
# define P1 4

typedef enum e_mask
{
	KEYPRESS_MASK	= (1L << 0),
	CLOSE_MASK		= (1L << 17)
}	t_mask;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

typedef struct s_game
{
	t_sprite	*sprites;
	t_position	prev;
	t_position	cur;
	void		*mlx;
	void		*win;
	char		**map;
	int			rows;
	int			cols;
	int			moves;
	int			player;
	int			total_coins;
	int			coins;
	int			exit;
}	t_game;

//moves.c
int		check_key(int key, t_game *so_long);
//create_map.c
void	create_map(t_game *so_long, char *map_file);
//libx.c
void	launch_mlx(t_game *so_long);
void	load_sprites(t_game *so_long);
void	render_map(t_game *solong);
void	render_positions(t_game *so_long, int x, int y);
//utils.c
int		return_msg(t_game *so_long);
int		flood_fill(int total_coins, int cur_y, int cur_x, char **test_map);
int		quit_game(t_game *so_long);
int		exit_error(t_game *so_long, char *msg);
//check_errors.c
void	check_map(t_game *so_long);
//clean_and_exit.c
void	clean_test_map(char **test_map);
void	clean_game(t_game *so_long);
#endif