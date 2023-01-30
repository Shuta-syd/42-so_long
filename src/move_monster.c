/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:24:09 by shogura           #+#    #+#             */
/*   Updated: 2022/06/06 17:29:02 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool check_wall_exit_player(t_data *data, int step)
{
	if (data->mapdata.map[step] == 'M')
		return (false);
	else if (data->mapdata.map[step] == '1')
		return (false);
	else if (data->mapdata.map[step] == 'E')
		return (false);
	else if (data->mapdata.map[step] == 'C')
		return (false);
	return (true);
}

void moveup_monster(t_data *data)
{
	int		i;
	char	*map;

	i = 0;
	map = data->mapdata.map;
	while (map[i])
	{
		if (map[i] == 'M' && check_wall_exit_player(data, i - (data->mapdata.row + 1)))
		{
			map[i] = '0';
			map[i - (data->mapdata.row + 1)] = 'M';
		}
		i++;
	}
}

void	movedown_monster(t_data *data)
{
	int i;
	char *map;

	i = 0;
	map = data->mapdata.map;
	while (map[i])
	{
		if (map[i] == 'M' && check_wall_exit_player(data, i + (data->mapdata.row + 1)))
		{
			map[i] = '0';
			map[i + (data->mapdata.row + 1)] = 'M';
		}
		i++;
	}
}

void moveleft_monster(t_data *data)
{
	int i;
	char *map;

	i = 0;
	map = data->mapdata.map;
	while (map[i] && check_wall_exit_player(data, i - 1))
	{
		if (map[i] == 'M')
		{
			map[i] = '0';
			map[i - 1] = 'M';
		}
		i++;
	}
}

void	moveright_monster(t_data *data)
{
	int i;
	char *map;

	i = 0;
	map = data->mapdata.map;
	while (map[i])
	{
		if (map[i] == 'M' && check_wall_exit_player(data, i + 1))
		{
			map[i] = '0';
			map[i + 1] = 'M';
		}
		i++;
	}
}

int move_monster(t_data * data)
{
	data->frame++;
	if (data->frame % 10000 == 0)
	{
		if (data->step % 7 == 0)
			moveup_monster(data);
		else if (data->step % 5 == 0)
			movedown_monster(data);
		else if (data->step % 3 == 0)
			moveleft_monster(data);
		else if (data->step % 2 == 0)
			moveright_monster(data);
	}
	return (0);
}
