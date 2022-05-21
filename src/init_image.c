/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:30:27 by shogura           #+#    #+#             */
/*   Updated: 2022/05/21 17:08:35 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_all_images(t_imgdata *img, void *mlx, char *filepath)
{
	img->img = mlx_xpm_file_to_image(mlx, filepath, &img->cie.x, &img->cie.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

// initialize images
void	init_image(t_data *data)
{
	init_all_images(&DB.imgdata.wall, DB.mlxdata.mlx, WALL_PATH);
	init_all_images(&DB.imgdata.empty, DB.mlxdata.mlx, EMPTY_PATH);
	init_all_images(&DB.imgdata.item, DB.mlxdata.mlx, ITEM_PATH);
	init_all_images(&DB.imgdata.exit, DB.mlxdata.mlx, EXIT_PATH);
	init_all_images(&DB.imgdata.player.top, DB.mlxdata.mlx, PLAYER_TOP_PATH);
	init_all_images(&DB.imgdata.player.down, DB.mlxdata.mlx, PLAYER_BACK_PATH);
	init_all_images(&DB.imgdata.player.left, DB.mlxdata.mlx, PLAYER_LEFT_PATH);
	init_all_images(&DB.imgdata.player.right, DB.mlxdata.mlx, PLAYER_RIGHT_PATH);
}
