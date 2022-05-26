/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:30:27 by shogura           #+#    #+#             */
/*   Updated: 2022/05/26 17:39:05 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	fail_init_image(t_data *data)
{
	ft_putstr("Error\nFailed to init image!!\n");
	free(data->mapdata.map);
	free(data->mapdata.map_backup);
	exit(1);
}

void	init_all_images(t_data *data, t_imgdata *img, void *mlx, char *filepath)
{
	img->img = mlx_xpm_file_to_image(mlx, filepath, &img->cie.x, &img->cie.y);
	if (img->img == NULL)
		fail_init_image(data);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
		fail_init_image(data);
}

// initialize images
void	init_image(t_data *data)
{
	init_all_images(data, &data->imgdata.wall, data->mlxdata.mlx, WALL_PATH);
	init_all_images(data, &data->imgdata.empty, data->mlxdata.mlx, EMPTY_PATH);
	init_all_images(data, &data->imgdata.item, data->mlxdata.mlx, ITEM_PATH);
	init_all_images(data, &data->imgdata.exit, data->mlxdata.mlx, EXIT_PATH);
	init_all_images(data, &data->imgdata.player.top, data->mlxdata.mlx,
		PLAYER_TOP_PATH);
	init_all_images(data, &data->imgdata.player.down, data->mlxdata.mlx,
		PLAYER_DOWN_PATH);
	init_all_images(data, &data->imgdata.player.left, data->mlxdata.mlx,
		PLAYER_LEFT_PATH);
	init_all_images(data, &data->imgdata.player.right, data->mlxdata.mlx,
		PLAYER_RIGHT_PATH);
	init_all_images(data, &data->imgdata.monster, data->mlxdata.mlx,
		MONSTER_PATH);
}
