/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:14:44 by shogura           #+#    #+#             */
/*   Updated: 2022/05/21 21:41:22 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../src/libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define DB (*data)
# define WINSIZE 50
# define TOP	1
# define DOWN 2
# define LEFT	3
# define RIGHT	4
# define A 0
# define W 13
# define S 1
# define D 2
# define ESC 53
# define WALL_PATH "img/wall/Rock2.xpm"
# define EMPTY_PATH "img/empty/empty1.xpm"
# define ITEM_PATH "img/item/item1.xpm"
# define EXIT_PATH "img/exit/exit1.xpm"
# define PLAYER_TOP_PATH "img/player/top1.xpm"
# define PLAYER_BACK_PATH "img/player/back1.xpm"
# define PLAYER_LEFT_PATH "img/player/left1.xpm"
# define PLAYER_RIGHT_PATH "img/player/right1.xpm"

typedef struct s_mlx //x window data
{
	void *mlx;
	void *win;
} t_mlx;

typedef struct s_cie
{
	unsigned int x;
	unsigned int y;
} t_cie;

typedef struct s_imgdata //imgdata
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	t_cie	cie;
} t_imgdata;

typedef struct s_player //player imgdata
{
	t_imgdata	top;
	t_imgdata	down;
	t_imgdata	left;
	t_imgdata	right;
} t_player;

typedef struct s_img // all imgdata
{
	t_imgdata	wall;
	t_imgdata	empty;
	t_imgdata	exit;
	t_imgdata	item;
	t_player	player;
} t_img;

typedef struct s_mapdata //map data is here
{
	char	*map; // Map information for one-dimensional arrays
	unsigned int	row;
	unsigned int	col;
	unsigned int	item;
} t_mapdata;

typedef struct s_data // all game data
{
	t_mlx	mlxdata;
	t_img	imgdata;
	t_mapdata	mapdata;
	t_cie	cie;
	unsigned int	dir;
	unsigned int	index;
	unsigned int	c_item;
	unsigned int	step;
	bool	exit;
} t_data;

char	*get_next_line(int fd);
void	scan_map(char const *filepath, t_data *data);
void	init_window(t_data *data);
void	init_image(t_data *data);
void	output_map(t_data *data);
int		action(int keycode, t_data *data);
int		scan_wall(char *map, t_data *data);
int		scan_line(char *map, t_data *data);
void	clear_window(int keycode, t_data *data);
#endif
