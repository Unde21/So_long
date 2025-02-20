/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_laser_fight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:11:31 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:04:29 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	remove_enemy_laser_right(t_data *data, t_enemy *enemy)
{
	while (enemy->laser_x != enemy->pos_x)
	{
		if (data->map[enemy->laser_y][enemy->laser_x] == LASER_CHAR)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR], enemy->laser_x * 64, enemy->laser_y
				* 64);
			data->map[enemy->laser_y][enemy->laser_x] = '0';
		}
		remove_display_laser_enemy(data, enemy);
		--enemy->laser_x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		enemy->sprite[ENEMY_R], enemy->pos_x * 64, enemy->pos_y * 64);
	enemy->laser_frame = 0;
	return (1);
}

int	remove_enemy_laser_left(t_data *data, t_enemy *enemy)
{
	while (enemy->laser_x != enemy->pos_x)
	{
		if (data->map[enemy->laser_y][enemy->laser_x] == LASER_CHAR)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR], enemy->laser_x * 64, enemy->laser_y
				* 64);
			data->map[enemy->laser_y][enemy->laser_x] = '0';
		}
		remove_display_laser_enemy(data, enemy);
		++enemy->laser_x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		enemy->sprite[ENEMY_L], enemy->pos_x * 64, enemy->pos_y * 64);
	enemy->laser_frame = 0;
	return (1);
}

int	remove_enemy_laser_down(t_data *data, t_enemy *enemy)
{
	while (enemy->laser_y != enemy->pos_y)
	{
		if (data->map[enemy->laser_y][enemy->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR], enemy->laser_x * 64, enemy->laser_y
				* 64);
			data->map[enemy->laser_y][enemy->laser_x] = '0';
		}
		remove_display_laser_enemy(data, enemy);
		--enemy->laser_y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		enemy->sprite[ENEMY_D], enemy->pos_x * 64, enemy->pos_y * 64);
	enemy->laser_frame = 0;
	return (1);
}

int	remove_enemy_laser_up(t_data *data, t_enemy *enemy)
{
	while (enemy->laser_y != enemy->pos_y)
	{
		if (data->map[enemy->laser_y][enemy->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR], enemy->laser_x * 64, enemy->laser_y
				* 64);
			data->map[enemy->laser_y][enemy->laser_x] = '0';
		}
		remove_display_laser_enemy(data, enemy);
		++enemy->laser_y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		enemy->sprite[ENEMY_T], enemy->pos_x * 64, enemy->pos_y * 64);
	enemy->laser_frame = 0;
	return (1);
}

void	remove_display_laser_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->laser_y][enemy->laser_x] == DEAD_OBJECT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT], enemy->laser_x * 64, enemy->laser_y
			* 64);
		data->map[enemy->laser_y][enemy->laser_x] = 'C';
	}
	else if (data->map[enemy->laser_y][enemy->laser_x] == DEAD_EXIT)
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->spaceship->sprite[EXIT_CLOSE], enemy->laser_x * 64,
				enemy->laser_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->spaceship->sprite[EXIT_OPEN], enemy->laser_x * 64,
				enemy->laser_y * 64);
		}
		data->map[enemy->laser_y][enemy->laser_x] = 'E';
	}
}
