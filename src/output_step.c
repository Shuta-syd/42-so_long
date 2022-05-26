/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:16:32 by shogura           #+#    #+#             */
/*   Updated: 2022/05/25 16:14:11 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	output_step(t_data *data)
{
	char	*step;

	step = ft_itoa(data->step);
	if (step == NULL)
		destroy_window(data);
	mlx_string_put(data->mlxdata.mlx, data->mlxdata.win,
		WINSIZE / 3, WINSIZE / 3, 0xFF0000, "CURRENT STEP:");
	mlx_string_put(data->mlxdata.mlx, data->mlxdata.win,
		WINSIZE * 3, WINSIZE / 3, 0xFF0000, step);
	free(step);
}
