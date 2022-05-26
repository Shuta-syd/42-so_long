/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:20:24 by shogura           #+#    #+#             */
/*   Updated: 2022/05/25 12:57:51 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	output_player(t_data *data, int x, int y, int index)
{
	data->cie.x = x;
	data->cie.y = y;
	data->index = index;
	if (data->dir == TOP)
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.player.top.img, x, y);
	else if (data->dir == DOWN)
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.player.down.img, x, y);
	else if (data->dir == LEFT)
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.player.left.img, x, y);
	else if (data->dir == RIGHT)
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.player.right.img, x, y);
}

void	output_splites(t_data *data, int col, int row, int index)
{
	int	x;
	int	y;

	x = row * WINSIZE;
	y = col * WINSIZE;
	(void)index;
	mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
		data->imgdata.empty.img, x, y);
	if (data->mapdata.map[index] == '1')
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.wall.img, x, y);
	else if (data->mapdata.map[index] == 'E')
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.exit.img, x, y);
	else if (data->mapdata.map[index] == 'P')
		output_player(data, x, y, index);
	else if (data->mapdata.map[index] == 'C')
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.item.img, x, y);
	else if (data->mapdata.map[index] == 'M')
		mlx_put_image_to_window(data->mlxdata.mlx, data->mlxdata.win,
			data->imgdata.monster.img, x, y);
}

//output map to the window
void	output_map(t_data *data)
{
	int	row;
	int	col;
	int	index;

	col = 0;
	index = 0;
	while (col < data->mapdata.col)
	{
		row = 0;
		while (row < data->mapdata.row)
		{
			output_splites(data, col, row, index);
			row++;
			index++;
		}
		col++;
		index++;
	}
}
