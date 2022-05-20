/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:10:55 by shogura           #+#    #+#             */
/*   Updated: 2022/05/16 20:56:12 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	show_mouse_event()
{
	printf("%s", "Hello World");
	return (0);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 500, "Window 1");
	mlx_mouse_show(vars.mlx, vars.win);
	/*
	int x;
	int y;
	while (1)
	{
		mlx_mouse_get_pos(vars.mlx, vars.win, &x, &y);
		printf("x->%d y->%d\n", x, y);
	}
	*/
	mlx_loop(vars.mlx);
}
