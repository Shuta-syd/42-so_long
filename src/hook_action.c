/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:47 by shogura           #+#    #+#             */
/*   Updated: 2022/05/24 17:16:42 by shogura          ###   ########.fr       */
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

//壁に貫通しないための関数 集めたアイテムのカウント
bool	check_wall_exit(int keycode, t_data *data)
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
void	move_player(int keycode, t_data *data)
{
	switch_dir(keycode, data);
	if (!check_wall_exit(keycode, data))
		return ;
	if (keycode == WJ)
		data->mapdata.map[data->index - (data->mapdata.row + 1)] = 'P';
	else if (keycode == AJ)
		data->mapdata.map[data->index - 1] = 'P';
	else if (keycode == SJ)
		data->mapdata.map[data->index + (data->mapdata.row + 1)] = 'P';
	else if (keycode == DJ)
		data->mapdata.map[data->index + 1] = 'P';
}

int	action(int keycode, t_data *data)
{
	if (keycode == AJ || keycode == WJ || keycode == SJ || keycode == DJ)
	{
		move_player(keycode, data);
		output_map(data);
		data->step++;
	}
	else if (keycode == RJ && data->exit == true)
		replay_game(data);
	else if (keycode == ESCJ)
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
