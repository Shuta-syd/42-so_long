/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:22:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 16:16:07 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//initialize the window
void	init_window(t_data *data)
{
	D.mlxdata.mlx = mlx_init();
	D.mlxdata.win = mlx_new_window(D.mlxdata.mlx, WINSIZE * D.mapdata.row, WINSIZE * D.mapdata.col, "so_long");
}
