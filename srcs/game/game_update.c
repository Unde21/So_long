/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:49:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 03:48:59 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_update(t_data *data)
{
	if (death_status(data) == 1)
		return (0);
	else if (enemy_run_with_spaceship(data) == 1)
	{
		if (data->spaceship->frame >= END_FRAME)
			close_window(data);
		return (1);
	}
	else if (data->enemy->life == 0 && data->enemy->is_alive == true)
	{
		// TODO sprite enemy dead
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR],
			data->enemy->pos_x * 64, data->enemy->pos_y * 64);
		data->enemy->is_alive = false;
	}
	else if (data->enemy->is_start_pos == true && data->landing == false)
	{
		if (data->player->is_laser_player == true)
			attack_player(data, data->player);
		return (move_enemy(data));
	}
	else
		landing_spaceship(data);
	return (0);
}

int	death_status(t_data *data)
{
	if (data->player->death == true && data->end == false
		&& data->defeat == false)
	{
		++data->player->frames;
		if (data->player->frames >= END_FRAME)
			close_window(data);
		return (1);
	}
	if (data->end == true && data->defeat == false)
	{
		++data->spaceship->frame;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[TRAIL_FIRE], data->player->pos_x * 64,
			data->player->pos_y * 64 - data->spaceship->frame / 100);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_FIRE], data->player->pos_x * 64,
			data->player->pos_y * 64 - data->spaceship->frame / 50);
		if (data->spaceship->frame >= END_FRAME)
			close_window(data);
		return (1);
	}
	return (0);
}

int	enemy_run_with_spaceship(t_data *data)
{
	if (data->end == false && data->defeat == true)
	{
		++data->spaceship->frame;
		if (data->player->dir_left == false)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->sprite[P_DEATH_R], data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->sprite[P_DEATH_L], data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[TRAIL_FIRE], data->enemy->pos_x * 64,
			data->enemy->pos_y * 64 - data->spaceship->frame / 100);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_FIRE], data->enemy->pos_x * 64,
			data->enemy->pos_y * 64 - data->spaceship->frame / 50);
		return (1);
	}
	return (0);
}
