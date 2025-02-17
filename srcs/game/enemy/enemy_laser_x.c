/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_laser_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:48:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 05:00:16 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	laser_right(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = RIGHT;
	if (data->map[enemy->laser_y][enemy->laser_x + 1] == 'L'
		|| data->player->is_fighting_laser == true)
	{
		enemy->is_fighting_laser = true;
		return ;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x + 1] != 'P'
		&& (size_t)(enemy->laser_x) < data->nb_row - 2)
		handle_laser_right_enemy(data, enemy);
	else if (data->map[enemy->laser_y][enemy->laser_x + 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (enemy->laser_x + 1) * 64, (enemy->laser_y)
			* 64);
		data->player->death = true;
	}
}

void	handle_laser_right_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_x == enemy->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->use_laser_r, (enemy->laser_x) * 64, (enemy->laser_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->laser_start_r, (enemy->laser_x + 1) * 64, (enemy->laser_y)
			* 64);
	}
	else if ((size_t)(enemy->laser_x) == data->nb_row - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (enemy->laser_x + 1) * 64, (enemy->laser_y)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, enemy->laser_line,
			(enemy->laser_x + 1) * 64, enemy->laser_y * 64);
	}
	++enemy->laser_x;
	if (data->map[enemy->laser_y][enemy->laser_x] == '1'
		|| data->map[enemy->laser_y][enemy->laser_x] == '0')
		data->map[enemy->laser_y][enemy->laser_x] = 'L';
}

void	laser_left(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = LEFT;
	if (data->map[enemy->laser_y][enemy->laser_x - 1] == 'L'
		|| data->player->is_fighting_laser == true)
	{
		enemy->is_fighting_laser = true;
		return ;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x - 1] != 'P'
		&& enemy->laser_x >= 2)
		handle_laser_left_enemy(data, enemy);
	else if (data->map[enemy->laser_y][enemy->laser_x - 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, (enemy->laser_x - 1) * 64, (enemy->laser_y)
			* 64);
		data->player->death = true;
	}
}

void	handle_laser_left_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_x == enemy->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->use_laser_l, (enemy->laser_x) * 64, (enemy->laser_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->laser_start_l, (enemy->laser_x - 1) * 64, (enemy->laser_y)
			* 64);
	}
	else if (enemy->laser_x == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, (enemy->laser_x - 1) * 64, (enemy->laser_y)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, enemy->laser_line,
			(enemy->laser_x - 1) * 64, enemy->laser_y * 64);
	}
	--enemy->laser_x;
	if (data->map[enemy->laser_y][enemy->laser_x] == '1'
		|| data->map[enemy->laser_y][enemy->laser_x] == '0')
		data->map[enemy->laser_y][enemy->laser_x] = 'L';
}
