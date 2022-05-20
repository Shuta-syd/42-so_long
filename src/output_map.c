/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:20:24 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 20:41:59 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	output_splites(t_data *data, int col, int row, int index)
{
	int	x;
	int	y;

	x = row * WINSIZE;
	y = col * WINSIZE;
	mlx_put_image_to_window(D.mlxdata.mlx, D.mlxdata.win, D.imgdata.empty.img, x, y);
	if (D.mapdata.map[index] == '1')
		mlx_put_image_to_window(D.mlxdata.mlx, D.mlxdata.win, D.imgdata.wall.img, x, y);
	else if (D.mapdata.map[index] == 'E')
		mlx_put_image_to_window(D.mlxdata.mlx, D.mlxdata.win, D.imgdata.exit.img, x, y);
	else if (D.mapdata.map[index] == 'P')
		mlx_put_image_to_window(D.mlxdata.mlx, D.mlxdata.win, D.imgdata.player.right.img, x, y);
	else if (D.mapdata.map[index] == 'C')
		mlx_put_image_to_window(D.mlxdata.mlx, D.mlxdata.win, D.imgdata.item.img, x, y);
}

//output map to the window
void	output_map(t_data *data)
{
	int	index;
	int	row;
	int	col;

	col = 0;
	index = 0;
	while (col < D.mapdata.col)
	{
		row = 0;
		while (row < D.mapdata.row)
		{
			output_splites(data, col, row, index);
			row++;
			index++;
		}
		col++;
		index++;
	}
}
