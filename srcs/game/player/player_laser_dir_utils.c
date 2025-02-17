/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_laser_dir_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:47:11 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 02:39:51 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_laser_touch(t_data *data, int next_x, int next_y)
{
	if (data->map[next_y][next_x] == 'B')
	{
		--data->enemy->life;
		if (data->enemy->life == 0)
		{
			disp_explosion(data, next_x, next_y);
			data->map[next_y][next_x] = '0';
			data->enemy->pos_x = next_x;
			data->enemy->pos_y = next_y;
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->destroy_wall, next_x * 64, next_y * 64);
		}
	}
}

void	disp_explosion(t_data *data, int next_x, int next_y)
{
	if (data->player->laser_dir == DOWN)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, next_x * 64, next_y * 64);
	}
	else if (data->player->laser_dir == RIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, next_x * 64, next_y * 64);
	}
	else if (data->player->laser_dir == LEFT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, next_x * 64, next_y * 64);
	}
	else if (data->player->laser_dir == UP)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_t, next_x * 64, next_y * 64);
	}
}
