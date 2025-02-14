/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:36:58 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/14 17:47:01 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_spaceship(t_data *data, t_img *img)
{
	img->spaceship_open = mlx_xpm_file_to_image(data->mlx_ptr, img->img[5],
			&img->width, &img->height);
	if (!img->spaceship_open)
		return ;
	if (data->enemy->pos_x == data->spaceship->pos_x
		&& data->enemy->pos_y == data->spaceship->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->img_d_opexit, data->spaceship->pos_x * 64,
			data->spaceship->pos_y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->spaceship_open, data->spaceship->pos_x * 64,
			data->spaceship->pos_y * 64);
	}
	data->spaceship->spaceship_close = false;
}
