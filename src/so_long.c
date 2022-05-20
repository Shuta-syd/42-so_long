/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:10:54 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 16:20:03 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//check error in args
void	scan_args(int argc, char const *argv[])
{
	if (argc > 2 || argc == 1) // too many arguments pattern
	{
		ft_putstr("argument error\nUsage ./so_long [map name].ber");
		exit(1);
	}
	else if (ft_strstr(argv[1], ".ber") == NULL) // mapname is not .ber
	{
		ft_putstr("map name is invalid\nUsage ./so_long [map name].ber");
		exit(1);
	}
}

//initialize status
void	init_data(t_data *data)
{
	D = (t_data){};
	D.mlxdata = (t_mlx){};
	D.imgdata.wall = (t_imgdata){};
	D.imgdata.empty = (t_imgdata){};
	D.imgdata.exit = (t_imgdata){};
	D.imgdata.item = (t_imgdata){};
	D.imgdata.player.top = (t_imgdata){};
	D.imgdata.player.back = (t_imgdata){};
	D.imgdata.player.left = (t_imgdata){};
	D.imgdata.player.right = (t_imgdata){};
	D.mapdata = (t_mapdata){};
}

int main(int argc, char const *argv[])
{
	t_data	data;

	scan_args(argc, argv);
	init_data(&data);
	scan_map(argv[1], &data);
	init_window(&data);
	init_image(&data);
	output_map(&data);
	mlx_loop(data.mlxdata.mlx);
	// system("leaks so_long");
	return (0);
}
