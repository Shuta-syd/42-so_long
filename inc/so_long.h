/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:14:44 by shogura           #+#    #+#             */
/*   Updated: 2022/06/06 16:23:50 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../src/libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define WINSIZE 50
# define TOP	1
# define DOWN 2
# define LEFT	3
# define RIGHT	4

//USキー keymap
# define W 13
# define A 0
# define S 1
# define D 2
# define R 15
# define ESC 53
//JSキー keymap
# define WJ 119
# define AJ 97
# define SJ 115
# define DJ 100
# define RJ 114
# define ESCJ 65307

# define WALL_PATH "img/wall/wall1.xpm"
# define EMPTY_PATH "img/empty/empty1.xpm"
# define ITEM_PATH "img/item/item1.xpm"
# define PLAYER_TOP_PATH "img/player/player1_top.xpm"
# define EXIT_PATH "img/exit/exit1.xpm"
# define PLAYER_DOWN_PATH "img/player/player1_down.xpm"
# define PLAYER_LEFT_PATH "img/player/player1_left.xpm"
# define PLAYER_RIGHT_PATH "img/player/player1_right.xpm"
# define MONSTER_PATH "img/monster/monster1.xpm"

typedef struct s_mlx //x window data
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_cie
{
	int	x;
	int	y;
}	t_cie;

typedef struct s_imgdata //imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_cie	cie;
}	t_imgdata;

typedef struct s_player //player imgdata
{
	t_imgdata	top;
	t_imgdata	down;
	t_imgdata	left;
	t_imgdata	right;
}	t_player;

typedef struct s_img // all imgdata
{
	t_imgdata	wall;
	t_imgdata	empty;
	t_imgdata	exit;
	t_imgdata	item;
	t_imgdata	monster;
	t_player	player;
}	t_img;

typedef struct s_mapdata //map data is here
{
	char	*map;
	char	*map_backup;
	int		row;
	int		col;
}	t_mapdata;

typedef struct s_data // all game data
{
	t_mlx		mlxdata;
	t_img		imgdata;
	t_mapdata	mapdata;
	t_cie		cie;
	int		dir;
	unsigned long frame;
	int	index;
	int		step;
	int		del;
	bool	monster;
	bool	exit;
	bool		lose;
}	t_data;

char	*get_next_line(int fd);
void	scan_map(char const *filepath, t_data *data);
void	init_window(t_data *data);
void	init_image(t_data *data);
void	output_map(t_data *data);
int		action(int keycode, t_data *data);
int		scan_wall(char *map, t_data *data);
int		scan_line(char *map, t_data *data);
int		destroy_window(t_data *data);
void	clear_game(t_data *data);
void	replay_game(t_data *data);
void	output_step(t_data *data);
bool	lose_game(t_data *data);
int		move_monster(t_data *data);
#endif
