/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:49:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 02:38:25 by samaouch         ###   ########lyon.fr   */
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
		death_enemy(data, data->enemy);
	else if (data->player->final_laser == true)
		disp_final_laser(data, data->player);
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

void	death_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'C')
		--data->nb_obj;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		enemy->sprite[ENEMY_DEATH],
		enemy->pos_x * 64, enemy->pos_y * 64);
	enemy->is_alive = false;
}

void	display_life(t_data *data, t_enemy *enemy)
{
	int	i;

	i = 0;
	while (i < enemy->life)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[LIFE_GREEN], (data->nb_row - i - 1) * 64,
			data->nb_line * 64);
		++i;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		enemy->sprite[ENEMY_R], (data->nb_row - i - 1) * 64,
		data->nb_line * 64);
}
