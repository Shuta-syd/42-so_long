/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:30:27 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 16:16:22 by shogura          ###   ########.fr       */
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
	init_all_images(&D.imgdata.wall, D.mlxdata.mlx, WALL_PATH);
	init_all_images(&D.imgdata.empty, D.mlxdata.mlx, EMPTY_PATH);
	init_all_images(&D.imgdata.item, D.mlxdata.mlx, ITEM_PATH);
	init_all_images(&D.imgdata.exit, D.mlxdata.mlx, EXIT_PATH);
	init_all_images(&D.imgdata.player.top, D.mlxdata.mlx, PLAYER_TOP_PATH);
	init_all_images(&D.imgdata.player.back, D.mlxdata.mlx, PLAYER_BACK_PATH);
	init_all_images(&D.imgdata.player.left, D.mlxdata.mlx, PLAYER_LEFT_PATH);
	init_all_images(&D.imgdata.player.right, D.mlxdata.mlx, PLAYER_RIGHT_PATH);
}
