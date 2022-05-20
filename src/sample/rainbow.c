/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:57:41 by shogura           #+#    #+#             */
/*   Updated: 2022/05/16 22:19:35 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	handler(t_vars *vars)
{
	static int i = 0;
	int colors[3] = {0xff0000, 0x00ff00, 0x0000ff};

	for (int y = 0; y < 500; y++)
	{
		for (int x = 0; x < 500; x++)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, colors[i]);
		}
	}
	usleep(600 * 100);
	i++;
	if (i == 4)
		i = 0;
	return (0);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 500, "hello world");
	mlx_loop_hook(vars.mlx, handler, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
