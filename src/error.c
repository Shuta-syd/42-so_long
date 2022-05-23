/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:41:42 by shogura           #+#    #+#             */
/*   Updated: 2022/05/23 19:50:29 by shogura          ###   ########.fr       */
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
	while (i < DB.mapdata.row)
	{
		if (map[i++] != '1')
			return (1);
	}
	while (j++ < DB.mapdata.col - 2)
	{
		i++;
		if (map[i] != '1' || map[i + DB.mapdata.row - 1] != '1')
			return (2);
		i += DB.mapdata.row;
	}
	i += 1;
	while (map[i] != '\n' && map[i] != '\0')
	{
		if (map[i++] != '1')
			return (3);
	}
	return (0);
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
	else if (ft_strchr(map, 'P') == NULL)
		return (4);
	return (0);
}
