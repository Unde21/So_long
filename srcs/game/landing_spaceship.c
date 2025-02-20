/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landing_spaceship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:38:03 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 02:58:39 by samaouch         ###   ########lyon.fr   */
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
				data->spaceship->sprite[LANDING_EXIT], data->spaceship->pos_x
				* 64, data->spaceship->final_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->spaceship->sprite[EXIT_CLOSE], data->spaceship->pos_x
				* 64, data->spaceship->pos_y * 64);
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
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[WALL], data->spaceship->pos_x * 64,
			(data->spaceship->final_y - 1) * 64);
	}
	else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], data->spaceship->pos_x * 64,
			(data->spaceship->final_y - 1) * 64);
	}
	else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT], data->spaceship->pos_x * 64,
			(data->spaceship->final_y - 1) * 64);
	}
	else
		landing_spaceship_display(data);
}

void	landing_spaceship_display(t_data *data)
{
	if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->sprite[PLAYER_R], data->player->pos_x * 64,
			data->player->pos_y * 64);
	}
	else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y
			- 1][data->spaceship->pos_x] == 'B')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[ENEMY_R], data->spaceship->pos_x * 64,
			(data->spaceship->final_y - 1) * 64);
	}
}
