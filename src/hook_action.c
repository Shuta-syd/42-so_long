/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:47 by shogura           #+#    #+#             */
/*   Updated: 2022/05/25 16:28:49 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_exit(t_data *data)
{
	if (ft_strchr(data->mapdata.map, 'C') == NULL)
	{
		data->exit = true;
		return (true);
	}
	return (false);
}

void	switch_dir(int keycode, t_data *data)
{
	if (keycode == W)
		data->dir = TOP;
	else if (keycode == A)
		data->dir = LEFT;
	else if (keycode == S)
		data->dir = DOWN;
	else if (keycode == D)
		data->dir = RIGHT;
}

//壁に貫通しないための関数
bool	check_wall_exit_monster(int keycode, t_data *data)
{
	int	step;

	step = 0;
	if (keycode == W)
		step = -(data->mapdata.row + 1);
	else if (keycode == A)
		step = -1;
	else if (keycode == S)
		step = data->mapdata.row + 1;
	else if (keycode == D)
		step = 1;
	if (data->mapdata.map[data->index + step] == '1')
		return (false);
	else if (data->mapdata.map[data->index + step] == 'M')
		return (lose_game(data));
	else if (data->mapdata.map[data->index + step] == 'E')
		if (!check_exit(data))
			return (false);
	data->mapdata.map[data->index] = '0';
	return (true);
}

/*
	WASDキーが押されたときに情報を書き換えて画像を出力するための関数
	data->mapdata.mapを書き換えてマップを再出力する
*/
bool	move_player(int keycode, t_data *data)
{
	switch_dir(keycode, data);
	if (!check_wall_exit_monster(keycode, data))
		return (false);
	if (keycode == W)
		data->mapdata.map[data->index - (data->mapdata.row + 1)] = 'P';
	else if (keycode == A)
		data->mapdata.map[data->index - 1] = 'P';
	else if (keycode == S)
		data->mapdata.map[data->index + (data->mapdata.row + 1)] = 'P';
	else if (keycode == D)
		data->mapdata.map[data->index + 1] = 'P';
	return (true);
}

int	action(int keycode, t_data *data)
{
	if ((keycode == A || keycode == W || keycode == S || keycode == D)
		&& (!data->exit && !data->lose))
	{
		if (!move_player(keycode, data))
			return (1);
		output_map(data);
		data->step++;
		output_step(data);
	}
	else if (keycode == R && (data->exit || data->lose))
		replay_game(data);
	else if (keycode == ESC)
		destroy_window(data);
	if (data->exit == true)
		clear_game(data);
	return (0);
}

/*
               13            26             39              52            65
	01234567890123 4567890123456  7890123456789   0123456789012  3456789012345
	1111111111111| 10010000000C1| 1000011111001| 1P0011E000001| 1111111111111

	横->13（0 ~ 12）縦->5(0 ~ 4)
				W						A					S					D
	P->43 上->29(-14) 左->X(-1) 下->X(+14) 右->44(+1)
*/
