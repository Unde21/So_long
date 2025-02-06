/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:36:58 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/04 03:56:03 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_spaceship(t_data *data, t_img *img) // check retour error
{
	mlx_destroy_image(data->mlx_ptr, img->spaceship_close);
	img->spaceship_close = NULL;
	img->spaceship_open = mlx_xpm_file_to_image(data->mlx_ptr, img->img[5],
			&img->width, &img->height);
	if (!img->spaceship_open)
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->spaceship_open,
		data->spaceship->pos_x * 64, data->spaceship->pos_y * 64);
	data->spaceship->spaceship_close = false;
}
