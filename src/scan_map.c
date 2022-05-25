/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:08:28 by shogura           #+#    #+#             */
/*   Updated: 2022/05/25 16:16:48 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_fail(int pattern)
{
	if (pattern == 1)
		ft_putstr("Failed to open file.");
	else if (pattern == 2)
		ft_putstr("Invalid Map.");
	else if (pattern == 3)
		ft_putstr("Malloc Error.");
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
		read_fail(1);
	map = get_next_line(fd);
	if (map == NULL)
		read_fail(2);
	data->mapdata.row = ft_strlen(map) - 1;
	while (1)
	{
		data->mapdata.col++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = create_map(&map, &line);
		if (map == NULL)
			read_fail(3);
	}
	data->mapdata.map_backup = ft_strdup(map);
	return (map);
}

void	search_monster(t_data *data)
{
	int		i;
	char	*map;

	i = 0;
	map = data->mapdata.map;
	while (map[i])
		if (map[i++] == 'M')
			break ;
	if (map[i] == '\0')
		data->m_index = -1;
	else
		data->m_index = i - 1;
	data->m_index_backup = data->m_index;
}

//scan_map to check errors and read map
void	scan_map(char const *filepath, t_data *data)
{
	data->mapdata.map = read_map(filepath, data);
	if (scan_line(data->mapdata.map, data))
	{
		free(data->mapdata.map);
		free(data->mapdata.map_backup);
		ft_putstr("Invalid Map!!\n");
	}
	search_monster(data);
}
