/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_laser_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:48:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 05:39:52 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	laser_right(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = RIGHT;
	ft_printf("%c\n", data->map[enemy->laser_y][enemy->laser_x + 1]);
	if (data->map[enemy->laser_y][enemy->laser_x + 1] == LASER_CHAR
		|| data->player->is_fighting_laser == true)
	{
		enemy->is_fighting_laser = true;
		return ;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x + 1] == 'P'
		|| (data->map[enemy->laser_y][enemy->laser_x + 1] == 'E'
		&& data->player->pos_x == data->spaceship->pos_x
		&& data->player->pos_y == data->spaceship->pos_y))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_R], (enemy->laser_x + 1) * 64,
			enemy->laser_y * 64);
		data->player->death = true;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x + 1] != 'P'
		&& (size_t)(enemy->laser_x) < data->nb_row - 2)
		handle_laser_right_enemy(data, enemy);
}

void	handle_laser_right_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_x == enemy->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[USE_LASER_R], enemy->laser_x * 64,
			enemy->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_START_R], (enemy->laser_x + 1) * 64,
			enemy->laser_y * 64);
	}
	else if ((size_t)(enemy->laser_x) == data->nb_row - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_R], (enemy->laser_x + 1) * 64,
			enemy->laser_y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_LINE], (enemy->laser_x + 1) * 64,
			enemy->laser_y * 64);
	}
	++enemy->laser_x;
	save_exit_and_object(data, enemy->laser_x, enemy->laser_y);
}

void	laser_left(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = LEFT;
	if (data->map[enemy->laser_y][enemy->laser_x - 1] == LASER_CHAR
		|| data->player->is_fighting_laser == true)
	{
		enemy->is_fighting_laser = true;
		return ;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x - 1] == 'P'
		|| (data->map[enemy->laser_y][enemy->laser_x + 1] == 'E'
		&& data->player->pos_x == data->spaceship->pos_x
		&& data->player->pos_y == data->spaceship->pos_y))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_L], (enemy->laser_x - 1) * 64,
			enemy->laser_y * 64);
		data->player->death = true;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x - 1] != 'P'
		&& enemy->laser_x >= 2)
		handle_laser_left_enemy(data, enemy);
}

void	handle_laser_left_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_x == enemy->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[USE_LASER_L], (enemy->laser_x) * 64,
			enemy->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_START_L], (enemy->laser_x - 1) * 64,
			enemy->laser_y * 64);
	}
	else if (enemy->laser_x == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_L], (enemy->laser_x - 1) * 64,
			enemy->laser_y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LASER_LINE], (enemy->laser_x - 1) * 64,
			enemy->laser_y * 64);
	}
	--enemy->laser_x;
	save_exit_and_object(data, enemy->laser_x, enemy->laser_y);
}

void	save_exit_and_object(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
		data->map[y][x] = DEAD_OBJECT;
	else if (data->map[y][x] == 'E')
		data->map[y][x] = DEAD_EXIT;
	else if (data->map[y][x] == '1' || data->map[y][x] == '0')
		data->map[y][x] = LASER_CHAR;
}
