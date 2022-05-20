/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:08:28 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 12:21:13 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	D.mapdata.row = ft_strlen(map) - 1;
	while (1)
	{
		D.mapdata.col++;
		line = get_next_line(fd); // need to check error
		if (line == NULL)
			break;
		map = create_map(&map, &line);
	}
	return (map);
}

// Check if the map is walled off
int scan_wall(char *map, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < D.mapdata.row)
	{
		if (map[i++] != '1')
			return (1);
	}
	while (j++ < D.mapdata.col - 2)
	{
		i++;
		if (map[i] != '1' || map[i + D.mapdata.row - 1] != '1')
			return (2);
		i += D.mapdata.row;
	}
	i++;
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

//scan_map to check errors and read map
void	scan_map(char const *filepath, t_data *data)
{
	//error check
	//read map
	D.mapdata.map = read_map(filepath, data);
	if (scan_line(D.mapdata.map, &D))
		ft_putstr("ERROR MAP\n");
	printf("%s", D.mapdata.map);
}
