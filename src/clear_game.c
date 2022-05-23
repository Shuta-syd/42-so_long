/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:13:05 by shogura           #+#    #+#             */
/*   Updated: 2022/05/23 22:27:38 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//put clear window
void	clear_game(t_data *data)
{
	mlx_clear_window(data->mlxdata.mlx, data->mlxdata.win);
	mlx_string_put(data->mlxdata.mlx, data->mlxdata.win,
			data->mapdata.row / 2 * WINSIZE, data->mapdata.col / 2 * WINSIZE,
			0xFFFF00, "CLEAR!!");
	mlx_string_put(data->mlxdata.mlx, data->mlxdata.win,
			data->mapdata.row / 2 * WINSIZE - 75, data->mapdata.col / 2 * WINSIZE + 25,
			0xFFFF00, "PRESS R TO PLAY AGAIN!!");
}
		// reset game as keypress R
void	replay_game(t_data *data)
{
	data->exit = false;
	data->dir = RIGHT;
	free(data->mapdata.map);
	data->mapdata.map = ft_strdup(data->mapdata.map_backup);
	output_map(data);
	return;
}
