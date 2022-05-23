/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:10:54 by shogura           #+#    #+#             */
/*   Updated: 2022/05/23 21:10:36 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//delete window by esc or x button
int	destroy_window(t_data *data)
{
	mlx_destroy_window((*data).mlxdata.mlx, (*data).mlxdata.win);
	ft_putstr("[EXIT]");
	free((*data).mapdata.map);
	exit(1);
}

//check error in args
void	scan_args(int argc, char const *argv[])
{
	if (argc > 2 || argc == 1)
	{
		ft_putstr("argument error\nUsage ./so_long [map name].ber");
		exit(1);
	}
	else if (ft_strstr(argv[1], ".ber") == NULL)
	{
		ft_putstr("map name is invalid\nUsage ./so_long [map name].ber");
		exit(1);
	}
}

//initialize status
void	init_data(t_data *data)
{
	(*data) = (t_data){};
	(*data).cie = (t_cie){};
	(*data).mlxdata = (t_mlx){};
	(*data).imgdata.wall = (t_imgdata){};
	(*data).imgdata.empty = (t_imgdata){};
	(*data).imgdata.exit = (t_imgdata){};
	(*data).imgdata.item = (t_imgdata){};
	(*data).imgdata.player.top = (t_imgdata){};
	(*data).imgdata.player.down = (t_imgdata){};
	(*data).imgdata.player.left = (t_imgdata){};
	(*data).imgdata.player.right = (t_imgdata){};
	(*data).mapdata = (t_mapdata){};
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	scan_args(argc, argv);
	init_data(&data);
	scan_map(argv[1], &data);
	init_window(&data);
	init_image(&data);
	data.dir = RIGHT;
	output_map(&data);
	mlx_hook(data.mlxdata.win, 2, 1L << 0, action, &data);
	mlx_hook(data.mlxdata.win, 17, 1L << 2, destroy_window, &data);
	mlx_do_key_autorepeaton(data.mlxdata.mlx);
	mlx_loop(data.mlxdata.mlx);
	return (0);
}
