/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:41:42 by shogura           #+#    #+#             */
/*   Updated: 2022/05/26 17:46:58 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Check if the map is walled off
int	scan_wall(char *map, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->mapdata.row)
	{
		if (map[i++] != '1')
			return (1);
	}
	while (j++ < data->mapdata.col - 2)
	{
		i++;
		if (map[i] != '1' || map[i + data->mapdata.row - 1] != '1')
			return (2);
		i += data->mapdata.row;
	}
	i += 1;
	while (map[i] != '\n' && map[i] != '\0')
	{
		if (map[i++] != '1')
			return (3);
	}
	return (0);
}

bool	check_extra(char *map, char sign)
{
	int	count;

	count = 0;
	while (*map)
	{
		if (*map == sign)
			count++;
		map++;
	}
	if (count > 1 || count == 0)
		return (false);
	return (true);
}

bool	check_extra_params(char *map, char *vars)
{
	bool	ret;
	int		i;

	while (*map)
	{
		ret = false;
		i = 0;
		while (vars[i])
		{
			if (*map == vars[i++])
				ret = true;
		}
		if (ret == false)
			return (false);
		map++;
	}
	return (true);
}

// scan_line() to check valid map or not
int	scan_line(char *map, t_data *data)
{
	if (scan_wall(map, data))
		return (1);
	else if (ft_strchr(map, 'E') == NULL)
		return (2);
	else if (ft_strchr(map, 'C') == NULL)
		return (3);
	else if (!check_extra(map, 'P'))
		return (4);
	else if (!check_extra_params(map, "01MPCE\n"))
		return (5);
	return (0);
}
