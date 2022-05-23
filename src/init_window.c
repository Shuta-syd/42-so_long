/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:22:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/23 21:30:37 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//initialize the window
void	init_window(t_data *data)
{
	data->mlxdata.mlx = mlx_init();
	data->mlxdata.win = mlx_new_window(data->mlxdata.mlx, WINSIZE * data->mapdata.row,
			WINSIZE * data->mapdata.col, "so_long");
}
