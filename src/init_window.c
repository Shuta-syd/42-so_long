/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:22:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/26 17:30:39 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	fail_init_window(t_data *data)
{
	ft_putstr("Error\nFailed to create window!!\n");
	free(data->mapdata.map);
	free(data->mapdata.map_backup);
	exit(1);
}

//initialize the window
void	init_window(t_data *data)
{
	data->mlxdata.mlx = mlx_init();
	if (data->mlxdata.mlx == NULL)
		fail_init_window(data);
	data->mlxdata.win = mlx_new_window(data->mlxdata.mlx,
			WINSIZE * data->mapdata.row,
			WINSIZE * data->mapdata.col, "so_long");
	if (data->mlxdata.win == NULL)
		fail_init_window(data);
}
