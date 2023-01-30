/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:08:28 by shogura           #+#    #+#             */
/*   Updated: 2022/06/06 15:31:20 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_fail(int pattern, t_data *data)
{
	if (pattern == 1)
		ft_putstr("Error\nFailed to open file.\n");
	else if (pattern == 2)
		ft_putstr("Error\nInvalid Map!!\n");
	else if (pattern == 3)
		ft_putstr("Error\nMalloc Error!!\n");
	else if (pattern == 4)
	{
		ft_putstr("Error\nMalloc Error!!\n");
		free(data->mapdata.map_backup);
	}
	else if (pattern == 5)
	{
		ft_putstr("Error\nInvalid Map!!\n");
		free(data->mapdata.map);
		free(data->mapdata.map_backup);
	}
	exit(1);
}

char	*create_map(char **line1, char **line2)
{
	char		*map;
	size_t		len;

	len = ft_strlen(*line1) + ft_strlen(*line2);
	map = ft_calloc(len + 1, sizeof(char));
	if (map == NULL)
	{
		free(*line1);
		free(*line2);
		return (NULL);
	}
	ft_strcat(map, *line1);
	ft_strcat(map, *line2);
	free(*line1);
	free(*line2);
	return (map);
}

//read map from filepath || need to free all
char	*read_map(char const *filepath, t_data *data)
{
	int		fd;
	char	*line;
	char	*map;

	map = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		read_fail(1, data);
	map = get_next_line(fd);
	if (map == NULL)
		read_fail(2, data);
	data->mapdata.row = ft_strlen(map) - 1;
	while (1)
	{
		data->mapdata.col++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = create_map(&map, &line);
		if (map == NULL)
			read_fail(3, data);
	}
	data->mapdata.map_backup = ft_strdup(map);
	return (map);
}

//scan_map to check errors and read map
void	scan_map(char const *filepath, t_data *data)
{
	data->mapdata.map = read_map(filepath, data);
	if (data->mapdata.map_backup == NULL)
		read_fail(4, data);
	else if (scan_line(data->mapdata.map, data))
		read_fail(5, data);
	if (ft_strchr(data->mapdata.map, 'M'))
		data->monster = true;
	else
		data->monster = false;
}
