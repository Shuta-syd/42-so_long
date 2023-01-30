/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:47 by shogura           #+#    #+#             */
/*   Updated: 2022/06/05 15:23:05 by shogura          ###   ########.fr       */
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
	if (keycode == WJ)
		data->dir = TOP;
	else if (keycode == AJ)
		data->dir = LEFT;
	else if (keycode == SJ)
		data->dir = DOWN;
	else if (keycode == DJ)
		data->dir = RIGHT;
}

//壁に貫通しないための関数
bool	check_wall_exit_monster(int keycode, t_data *data)
{
	int	step;

	step = 0;
	if (keycode == WJ)
		step = -(data->mapdata.row + 1);
	else if (keycode == AJ)
		step = -1;
	else if (keycode == SJ)
		step = data->mapdata.row + 1;
	else if (keycode == DJ)
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
	if (keycode == WJ)
		data->mapdata.map[data->index - (data->mapdata.row + 1)] = 'P';
	else if (keycode == AJ)
		data->mapdata.map[data->index - 1] = 'P';
	else if (keycode == SJ)
		data->mapdata.map[data->index + (data->mapdata.row + 1)] = 'P';
	else if (keycode == DJ)
		data->mapdata.map[data->index + 1] = 'P';
	return (true);
}

int	action(int keycode, t_data *data)
{
	if ((keycode == AJ || keycode == WJ || keycode == SJ || keycode == DJ)
		&& (!data->exit && !data->lose))
	{
		if (!move_player(keycode, data))
			return (1);
		output_map(data);
		data->step++;
		output_step(data);
	}
	else if (keycode == RJ && (data->exit || data->lose))
		replay_game(data);
	else if (keycode == ESCJ)
		destroy_window(data);
	if (data->exit == true)
		clear_game(data);
	return (0);
}
