/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:08:28 by shogura           #+#    #+#             */
/*   Updated: 2022/05/22 13:55:03 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	count_item(char *line, t_data *data)
{
	while (*line++)
	{
		if (*line == 'C')
			DB.mapdata.item++;
	}
}

char *create_map(char **line1, char **line2)
{
	char		*map;
	size_t	len;

	len = ft_strlen(*line1) + ft_strlen(*line2);
	map = ft_calloc(len + 1, sizeof(char));
	if (map == NULL)
		return (NULL);
	ft_strcat(map, *line1);
	ft_strcat(map, *line2);
	free(*line1);
	free(*line2);
	return (map);
}

//read map from filepath || need to free all
char *read_map(char const *filepath, t_data *data)
{
	int		fd;
	char *line;
	char	*map;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{ /* //need to check error */ }
	map = get_next_line(fd); // need to check error
	if (map == NULL)
	{ /* need to check error */ }
	DB.mapdata.row = ft_strlen(map) - 1;
	while (1)
	{
		DB.mapdata.col++;
		line = get_next_line(fd); // need to check error
		if (line == NULL)
			break;
		count_item(line, data);
		map = create_map(&map, &line);
	}
	return (map);
}

//scan_map to check errors and read map
void	scan_map(char const *filepath, t_data *data)
{
	//error check
	//read map
	DB.mapdata.map = read_map(filepath, data);
	if (scan_line(DB.mapdata.map, data))
		ft_putstr("ERROR MAP\n");
	printf("%s", DB.mapdata.map);
}
