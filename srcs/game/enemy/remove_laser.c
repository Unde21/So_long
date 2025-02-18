/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_laser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:03:54 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 04:44:17 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	remove_basic_laser_right(t_data *data, t_enemy *enemy)
{
	while (enemy->laser_x != enemy->pos_x)
	{
		if (data->map[enemy->laser_y][enemy->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR], enemy->laser_x * 64, enemy->laser_y
				* 64);
			data->map[enemy->laser_y][enemy->laser_x] = '0';
		}
		remove_display_laser_enemy(data, enemy);
		--enemy->laser_x;
	}
	return (1);
}

int	remove_basic_laser_left(t_data *data, t_enemy *enemy)
{
	while (enemy->laser_x != enemy->pos_x)
	{
		if (data->map[enemy->laser_y][enemy->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR], enemy->laser_x * 64, enemy->laser_y
				* 64);
			data->map[enemy->laser_y][enemy->laser_x] = '0';
		}
		remove_display_laser_enemy(data, enemy);
		++enemy->laser_x;
	}
	return (1);
}

int	remove_basic_laser_down(t_data *data, t_enemy *enemy)
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
	return (1);
}

int	remove_basic_laser_top(t_data *data, t_enemy *enemy)
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
	return (1);
}

void	remove_basic_display_laser_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->laser_y][enemy->laser_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT], enemy->laser_x * 64, enemy->laser_y
			* 64);
	}
	else if (data->map[enemy->laser_y][enemy->laser_x] == 'E')
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
	}
}
