/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:19:07 by shogura           #+#    #+#             */
/*   Updated: 2022/05/18 13:39:26 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// int handler(t_vars *vars)
// {

// }

int main(void)
{
	t_data data;
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 500, "hello world");
	data.img = mlx_new_image(vars.mlx, 500, 500);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	for (int i = 0; i < 500; i++)
	{
		my_mlx_pixel_put(&data, i, i, 0x00ff0000);
		my_mlx_pixel_put(&data, 5, i, 0x00ff0000);
		my_mlx_pixel_put(&data, i, 5, 0x00ff0000);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	// mlx_loop_hook(vars.mlx, handler, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
