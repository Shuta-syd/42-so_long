/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:24:09 by shogura           #+#    #+#             */
/*   Updated: 2022/05/25 16:13:57 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	moveup_monster(t_data *data)
{
	int		m_row;
	char	*map;
	int		step;

	step = data->mapdata.row + 1;
	map = data->mapdata.map;
	m_row = data->m_index / data->mapdata.row;
	if ((m_row > 0 || m_row < data->mapdata.row)
		&& map[data->m_index - step] != '1')
	{
		map[data->m_index - step] = 'M';
		map[data->m_index] = '0';
		data->m_index -= step;
	}
	 return (0);
}

int	movedown_monster(t_data *data)
{
	int		m_row;
	char	*map;
	int		step;

	step = data->mapdata.row + 1;
	map = data->mapdata.map;
	m_row = data->m_index / data->mapdata.row;
	if ((m_row > 0 || m_row < data->mapdata.row)
		&& map[data->m_index + step] != '1')
	{
		map[data->m_index + step] = 'M';
		map[data->m_index] = '0';
		data->m_index += step;
	}
	return (0);
}

int	move_monster(t_data *data)
{
	int	fl_index;
	int	fl_index_end;
	int	el_index;

	fl_index = data->mapdata.row + 1;
	fl_index_end = data->mapdata.row * 2 - 2;
	el_index = data->mapdata.row * (data->mapdata.col - 2) + 2;
	if (!(fl_index <= data->m_index_backup
			&& data->m_index_backup <= fl_index_end))
	{
		moveup_monster(data);
		if (fl_index <= data->m_index && data->m_index <= fl_index_end)
			data->m_index_backup = data->m_index;
	}
	else
	{
		movedown_monster(data);
		if (el_index <= data->m_index)
			data->m_index_backup = data->m_index;
	}
	return (0);
}
