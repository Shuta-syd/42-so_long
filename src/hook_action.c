/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:47 by shogura           #+#    #+#             */
/*   Updated: 2022/05/23 19:52:13 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	check_exit(t_data *data)
{
	if (ft_strchr(DB.mapdata.map, 'C') == NULL)
	{
		DB.exit = true;
		return (true);
	}
	return (false);
}

void	switch_dir(int keycode, t_data *data)
{
	if (keycode == W)
		DB.dir = TOP;
	else if (keycode == A)
		DB.dir = LEFT;
	else if (keycode == S)
		DB.dir = DOWN;
	else if (keycode == D)
		DB.dir = RIGHT;
}

//壁に貫通しないための関数 集めたアイテムのカウント
bool	check_wall_exit(int keycode, t_data *data)
{
	int	step;

	step = 0;
	if (keycode == W)
		step = -(DB.mapdata.row + 1);
	else if (keycode == A)
		step = -1;
	else if (keycode == S)
		step = DB.mapdata.row + 1;
	else if (keycode == D)
		step = 1;
	if (DB.mapdata.map[DB.index + step] == '1')
		return (false);
	else if (DB.mapdata.map[DB.index + step] == 'E')
		if (!check_exit(data))
			return (false);
	DB.mapdata.map[DB.index] = '0';
	return (true);
}

/*
	WASDキーが押されたときに情報を書き換えて画像を出力するための関数
	DB.mapdata.mapを書き換えてマップを再出力する
*/
void	move_player(int keycode, t_data *data)
{
	switch_dir(keycode, data);
	if (!check_wall_exit(keycode, data))
		return ;
	if (keycode == W)
		DB.mapdata.map[DB.index - (DB.mapdata.row + 1)] = 'P';
	else if (keycode == A)
		DB.mapdata.map[DB.index - 1] = 'P';
	else if (keycode == S)
		DB.mapdata.map[DB.index + (DB.mapdata.row + 1)] = 'P';
	else if (keycode == D)
		DB.mapdata.map[DB.index + 1] = 'P';
}

int	action(int keycode, t_data *data)
{
	if (keycode == A || keycode == W || keycode == S || keycode == D)
	{
		move_player(keycode, data);
		output_map(data);
		DB.step++;
	}
	else if (DB.exit == true)
	{
		//clear画面
	}
	else
		destroy_window(data);
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
