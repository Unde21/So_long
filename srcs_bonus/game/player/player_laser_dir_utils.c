/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_laser_dir_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:47:11 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 20:12:41 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <unistd.h>

int	is_laser_touch(t_data *data, int next_x, int next_y)
{
	if (data->map[next_y][next_x] == 'B'
		|| data->map[next_y][next_x] == ENEMY_OBJECT)
	{
		--data->enemy->life;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[LIFE_RED],
			(data->nb_row - data->enemy->life - 1) * 64, data->nb_line * 64);
		if (data->enemy->life == 0)
		{
			disp_explosion(data, next_x, next_y);
			data->enemy->pos_x = next_x;
			data->enemy->pos_y = next_y;
			reset_laser_pos(data, data->player);
			data->player->final_laser = true;
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->sprite[SHIELD], next_x * 64, next_y * 64);
		}
		return (1);
	}
	return (0);
}

void	disp_explosion(t_data *data, int next_x, int next_y)
{
	if (data->player->laser_dir == DOWN)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_D], next_x * 64, (next_y - 1) * 64);
	}
	else if (data->player->laser_dir == RIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_R], (next_x - 1) * 64, next_y * 64);
	}
	else if (data->player->laser_dir == LEFT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_L], (next_x + 1) * 64, next_y * 64);
	}
	else if (data->player->laser_dir == UP)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_T], next_x * 64, (next_y + 1) * 64);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->enemy->sprite[ENEMY_DEATH],
		(data->nb_row - LIFE - 1) * 64, data->nb_line * 64);
}
