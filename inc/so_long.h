/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:14:44 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 20:29:55 by shogura          ###   ########.fr       */
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
# define D (*data)
# define WINSIZE 50
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
	int	x;
	int	y;
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
	t_imgdata	back;
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
	char *map; // Map information for one-dimensional arrays
	int		row;
	int		col;
} t_mapdata;

typedef struct s_data // all game data
{
	t_mlx	mlxdata;
	t_img	imgdata;
	t_mapdata	mapdata;
} t_data;

char	*get_next_line(int fd);
void	scan_map(char const *filepath, t_data *data);
void	init_window(t_data *data);
void	init_image(t_data *data);
void	output_map(t_data *data);
#endif
