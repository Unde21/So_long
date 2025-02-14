/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_spaceship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:38:03 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/14 17:45:41 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	landing_spaceship(t_data *data)
{
	++data->player->frames;
	if (data->player->frames >= LANDING_FRAME)
	{
		data->player->frames = 0;
		if (data->spaceship->final_y <= data->spaceship->pos_y)
		{
			landing_spaceship_utils(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->landing_spaceship, data->spaceship->pos_x * 64,
				data->spaceship->final_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->spaceship_close, data->spaceship->pos_x * 64,
				data->spaceship->pos_y * 64);
			data->landing = false;
		}
		++data->spaceship->final_y;
	}
}

void	landing_spaceship_utils(t_data *data)
{
	if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->wall,
			data->spaceship->pos_x * 64, (data->spaceship->final_y - 1) * 64);
	}
	else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			data->spaceship->pos_x * 64, (data->spaceship->final_y - 1) * 64);
	}
	else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->object,
			data->spaceship->pos_x * 64, (data->spaceship->final_y - 1) * 64);
	}
	else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->player, data->player->pos_x * 64,
			data->player->pos_y * 64);
	}
}
