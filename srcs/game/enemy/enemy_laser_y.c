/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_laser_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:56:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 05:39:43 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	laser_down(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = DOWN;
	if (data->map[enemy->laser_y + 1][enemy->laser_x] == 'L'
		|| data->player->is_fighting_laser == true)
	{
		enemy->is_fighting_laser = true;
		return ;
	}
	else if (data->map[enemy->laser_y + 1][enemy->laser_x] == 'P'
		|| (data->map[enemy->laser_y][enemy->laser_x + 1] == 'E'
		&& data->player->pos_x == data->spaceship->pos_x
		&& data->player->pos_y == data->spaceship->pos_y))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_D], enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
		data->player->death = true;
	}
	else if (data->map[enemy->laser_y + 1][enemy->laser_x] != 'P'
		&& (size_t)(enemy->laser_y) < data->nb_line - 2)
		handle_laser_down_enemy(data, enemy);
}

void	handle_laser_down_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_y == enemy->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[USE_LASER_D], enemy->laser_x * 64,
			enemy->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_START_D], enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
	}
	else if ((size_t)(enemy->laser_y) == data->nb_line - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_D], enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_ROW], enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
	}
	++enemy->laser_y;
	save_exit_and_object(data, enemy->laser_x, enemy->laser_y);
}

void	laser_top(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = UP;
	if (data->map[enemy->laser_y - 1][enemy->laser_x] == 'L'
		|| data->enemy->is_fighting_laser == true)
	{
		enemy->is_fighting_laser = true;
		return ;
	}
	else if (data->map[enemy->laser_y - 1][enemy->laser_x] == 'P'
		|| (data->map[enemy->laser_y][enemy->laser_x + 1] == 'E'
		&& data->player->pos_x == data->spaceship->pos_x
		&& data->player->pos_y == data->spaceship->pos_y))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_T], enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
		data->player->death = true;
	}
	else if (data->map[enemy->laser_y - 1][enemy->laser_x] != 'P'
		&& enemy->laser_y >= 2)
		handle_laser_top_enemy(data, enemy);
}

void	handle_laser_top_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_y == enemy->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[USE_LASER_T], enemy->laser_x * 64,
			enemy->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_START_T], enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
	}
	else if (enemy->laser_y == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_T], enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_ROW], enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
	}
	--enemy->laser_y;
	save_exit_and_object(data, enemy->laser_x, enemy->laser_y);
}
