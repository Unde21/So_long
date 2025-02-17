/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_laser_dir_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:21:23 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 02:40:44 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	laser_left_player(t_data *data, t_player *player)
{
	player->laser_dir = LEFT;
	if (data->map[player->laser_y][player->laser_x - 1] == 'L')
	{
		player->is_fighting_laser = true;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->laser_fight_x, (player->laser_x - 1) * 64,
			player->laser_y * 64);
		data->enemy->is_laser_enemy = false;
		return ;
	}
	else if (data->map[player->laser_y][player->laser_x - 1] == 'B')
	{
		is_laser_touch(data, player->laser_x - 1, player->laser_y);
		remove_player_laser_left(data, player);
		data->player->is_laser_player = false;
	}
	else if (data->map[player->laser_y][player->laser_x - 1] != 'B'
		&& player->laser_x >= 2)
	{
		handle_laser_left(data, player);
		--player->laser_x;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
}

void	handle_laser_left(t_data *data, t_player *player)
{
	if (player->laser_x == player->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->use_laser_l, (player->laser_x) * 64, (player->laser_y)
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_start_l, (player->laser_x - 1) * 64,
			(player->laser_y) * 64);
	}
	else if (player->laser_x == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, (player->laser_x - 1) * 64, (player->laser_y)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_line, (player->laser_x - 1) * 64, player->laser_y
			* 64);
	}
}

void	laser_right_player(t_data *data, t_player *player)
{
	player->laser_dir = RIGHT;
	if (data->map[player->laser_y][player->laser_x + 1] == 'L')
	{
		player->is_fighting_laser = true;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->laser_fight_x, (player->laser_x + 1) * 64,
			player->laser_y * 64);
		data->enemy->is_laser_enemy = false;
		return ;
	}
	else if (data->map[player->laser_y][player->laser_x + 1] == 'B')
	{
		is_laser_touch(data, player->laser_x + 1, player->laser_y);
		remove_player_laser_right(data, player);
		data->player->is_laser_player = false;
	}
	else if (data->map[player->laser_y][player->laser_x + 1] != 'B'
		&& (size_t)(player->laser_x) < data->nb_row - 2)
	{
		handle_laser_right(data, player);
		++player->laser_x;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
}

void	handle_laser_right(t_data *data, t_player *player)
{
	if (player->laser_x == player->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->use_laser_r, (player->laser_x) * 64, (player->laser_y)
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_start_r, (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
	}
	else if ((size_t)(player->laser_x) == data->nb_row - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_line, (player->laser_x + 1) * 64, player->laser_y
			* 64);
	}
}
