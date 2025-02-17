/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 04:46:23 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	move_enemy(t_data *data)
{
	struct timeval	current_time;
	long			elapsed_time;

	if (data->end == true || data->player->death == true || data->end == true
		|| data->landing == true || data->enemy->is_alive == false)
		return (0);
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - data->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - data->last_time.tv_usec) / 1000;
	// modifier la division par une multiplication
	data->enemy->laser_frame += elapsed_time;
	check_enemy_laser_status(data, current_time, elapsed_time);
	check_enemy_move_status(data, current_time, elapsed_time);
	return (0);
}

void	check_enemy_laser_status(t_data *data, struct timeval current_time,
		long elapsed_time)
{
	if (data->enemy->laser_frame > LASER_FRAME)
	{
		if (data->enemy->is_laser_enemy == false)
			save_last_position_player(data);
	}
	if (elapsed_time > LASER_MVE_FRAME && data->enemy->is_laser_enemy == true)
	{
		if (enemy_laser(data, data->enemy) == 1)
		{
			data->enemy->is_laser_enemy = false;
			data->enemy->laser_dir = 0;
		}
		data->enemy->laser_frame = 0;
		data->last_time = current_time;
	}
}

void	check_enemy_move_status(t_data *data, struct timeval current_time,
		long elapsed_time)
{
	if (elapsed_time > MOVE_ENEMY_FRAME && data->enemy->moved == 0
		&& data->enemy->is_laser_enemy == false)
	{
		handle_enemy_move(data, data->enemy);
		data->last_time = current_time;
	}
	else if (elapsed_time > MOVE_ENEMY_FRAME && data->enemy->moved != 0
		&& data->enemy->is_laser_enemy == false)
	{
		move_in_line_after_destroy(data, data->enemy);
		move_in_row_after_destroy(data, data->enemy);
		data->last_time = current_time;
		data->enemy->moved = false;
	}
}

void	save_last_position_player(t_data *data)
{
	data->player->s_pos_x = data->player->pos_x;
	data->player->s_pos_y = data->player->pos_y;
	data->enemy->laser_x = data->enemy->pos_x;
	data->enemy->laser_y = data->enemy->pos_y;
	data->enemy->is_laser_enemy = true;
}

void	handle_enemy_move(t_data *data, t_enemy *enemy)
{
	if (data->player->pos_y < enemy->pos_y && data->map[enemy->pos_y
			- 1][enemy->pos_x] != '1' && enemy->moved == 0)
		move_enemy_top(data, enemy);
	else if (data->player->pos_x > enemy->pos_x
		&& data->map[enemy->pos_y][enemy->pos_x + 1] != '1'
		&& enemy->moved == 0)
		move_enemy_right(data, enemy);
	else if (data->player->pos_y > enemy->pos_y && data->map[enemy->pos_y
			+ 1][enemy->pos_x] != '1' && enemy->moved == 0)
		move_enemy_down(data, enemy);
	else if (data->player->pos_x < enemy->pos_x
		&& data->map[enemy->pos_y][enemy->pos_x - 1] != '1'
		&& enemy->moved == 0)
		move_enemy_left(data, enemy);
	else
		enemy_destroy_wall(data, enemy);
}
