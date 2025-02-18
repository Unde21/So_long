/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:36:58 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 02:20:04 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_spaceship(t_data *data, t_spaceship *spaceship)
{
	if (data->enemy->pos_x == data->spaceship->pos_x
		&& data->enemy->pos_y == data->spaceship->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[ENEM_OEXIT_D], data->spaceship->pos_x * 64,
			data->spaceship->pos_y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			spaceship->sprite[EXIT_OPEN], data->spaceship->pos_x * 64,
			data->spaceship->pos_y * 64);
	}
	data->spaceship->spaceship_close = false;
}
