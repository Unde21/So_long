/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_laser_dir_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:32:56 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 19:44:26 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	laser_down_player(t_data *data, t_player *player)
{
	player->laser_dir = DOWN;
	if (data->map[player->laser_y + 1][player->laser_x] == LASER_CHAR
		|| data->map[player->laser_y + 1][player->laser_x] == DEAD_OBJECT)
	{
		player->is_fighting_laser = true;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[LASER_FIGHT_Y], player->laser_x * 64,
			(player->laser_y + 1) * 64);
		data->enemy->is_laser_enemy = false;
	}
	else if (data->map[player->laser_y + 1][player->laser_x] == 'B'
		|| data->map[player->laser_y + 1][player->laser_x] == ENEMY_OBJECT)
	{
		if (is_laser_touch(data, player->laser_x, player->laser_y + 1) != 0)
			remove_player_laser_down(data, player);
		data->player->is_laser_player = false;
	}
	else if (data->map[player->laser_y + 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) < data->nb_line - 2)
	{
		handle_laser_down(data, player);
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = LASER_CHAR;
	}
}

void	handle_laser_down(t_data *data, t_player *player)
{
	if (player->laser_y == player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_LASER_D], player->laser_x * 64,
			player->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[LASER_START_D], player->laser_x * 64,
			(player->laser_y + 1) * 64);
	}
	else if ((size_t)(player->laser_y) == data->nb_line - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_D], player->laser_x * 64,
			(player->laser_y + 1) * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[LASER_ROW], player->laser_x * 64,
			(player->laser_y + 1) * 64);
	}
	++player->laser_y;
}

void	laser_top_player(t_data *data, t_player *player)
{
	player->laser_dir = UP;
	if (data->map[player->laser_y - 1][player->laser_x] == LASER_CHAR
		|| data->map[player->laser_y - 1][player->laser_x] == DEAD_OBJECT)
	{
		player->is_fighting_laser = true;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[LASER_FIGHT_Y], player->laser_x * 64,
			(player->laser_y - 1) * 64);
		data->enemy->is_laser_enemy = false;
	}
	else if (data->map[player->laser_y - 1][player->laser_x] == 'B'
		|| data->map[player->laser_y - 1][player->laser_x] == ENEMY_OBJECT)
	{
		if (is_laser_touch(data, player->laser_x, player->laser_y - 1) != 0)
			remove_player_laser_up(data, player);
		data->player->is_laser_player = false;
	}
	else if (data->map[player->laser_y - 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) >= 2)
	{
		handle_laser_top(data, player);
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = LASER_CHAR;
	}
}

void	handle_laser_top(t_data *data, t_player *player)
{
	if (player->laser_y == player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_LASER_T], player->laser_x * 64,
			player->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[LASER_START_T], player->laser_x * 64,
			(player->laser_y - 1) * 64);
	}
	else if (player->laser_y == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[EXPLOSION_T], player->laser_x * 64,
			(player->laser_y - 1) * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[LASER_ROW], player->laser_x * 64,
			(player->laser_y - 1) * 64);
	}
	--player->laser_y;
}
