/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:14:24 by shogura           #+#    #+#             */
/*   Updated: 2022/05/18 14:35:07 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int close_window(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		printf("keycode->[%d]\n", keycode);
	return (0);
}

int main(void)
{
	t_vars	var;
	t_data	img;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 500, 500, "hello world");
	img.img = mlx_new_image(var.mlx, 500, 500);
	img.line_length = 100;
	img.bits_per_pixel = 100;
	img.endian = 100;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			my_mlx_pixel_put(&img, j, i, 0x7192ff);
		}
	}
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_string_put(var.mlx, var.win, 50, 50, 0x000000, "Hello");
	mlx_key_hook(var.win, close_window, &var);
	mlx_loop(var.mlx);
	return 0;
}
