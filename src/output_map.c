/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:20:24 by shogura           #+#    #+#             */
/*   Updated: 2022/05/21 18:21:10 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	output_player(t_data *data, int x, int y, int index)
{
	// printf("x->%d y->%d\n", x, y);
	DB.cie.x = x;
	DB.cie.y = y;
	DB.index = index;
	if (DB.dir == TOP)
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.player.top.img, x, y);
	else if (DB.dir == DOWN)
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.player.down.img, x, y);
	else if (DB.dir == LEFT)
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.player.left.img, x, y);
	else if (DB.dir == RIGHT)
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.player.right.img, x, y);
}

void	output_splites(t_data *data, int col, int row, int index)
{
	int	x;
	int	y;

	x = row * WINSIZE;
	y = col * WINSIZE;
	mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.empty.img, x, y);
	if (DB.mapdata.map[index] == '1')
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.wall.img, x, y);
	else if (DB.mapdata.map[index] == 'E')
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.exit.img, x, y);
	else if (DB.mapdata.map[index] == 'P')
		output_player(data, x, y, index);
	else if (DB.mapdata.map[index] == 'C')
		mlx_put_image_to_window(DB.mlxdata.mlx, DB.mlxdata.win, DB.imgdata.item.img, x, y);
}

//output map to the window
void	output_map(t_data *data)
{
	int	index;
	int	row;
	int	col;

	col = 0;
	index = 0;
	while (col < DB.mapdata.col)
	{
		row = 0;
		while (row < DB.mapdata.row)
		{
			output_splites(data, col, row, index);
			row++;
			index++;
		}
		col++;
		index++;
	}
}
