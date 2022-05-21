/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:22:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/21 17:07:06 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//initialize the window
void	init_window(t_data *data)
{
	DB.mlxdata.mlx = mlx_init();
	DB.mlxdata.win = mlx_new_window(DB.mlxdata.mlx, WINSIZE * DB.mapdata.row, WINSIZE * DB.mapdata.col, "so_long");
}
