/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:40:11 by shogura           #+#    #+#             */
/*   Updated: 2022/05/20 12:33:21 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	main(void)
{
	t_vars	var;
	t_data	img;
	char	*relative_path = "img/collection/food.xpm";
	int		img_width = 50;
	int		img_height = 50;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 800, 800, "so_long");
	img.img = mlx_xpm_file_to_image(var.mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_loop(var.mlx);
}
