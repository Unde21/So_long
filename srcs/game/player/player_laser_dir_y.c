/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_laser_dir_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:32:56 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/14 19:40:51 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	laser_down_player(t_data *data, t_player *player)
{
	player->laser_dir = DOWN;
	if (data->map[player->laser_y + 1][player->laser_x] == 'L')
	{
		player->is_laser_player = false;
		return ;
	}
	else if (data->map[player->laser_y + 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) < data->nb_line - 2)
	{
		handle_laser_down(data, player);
		++player->laser_y;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	// else if (data->map[player->laser_y + 1][player->laser_x] == 'P')
	// {
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 		data->img->explosion_d, player->laser_x * 64, (player->laser_y + 1)
	// 		* 64);
	// 	data->player->death = true;
	// }
}

void	handle_laser_down(t_data *data, t_player *player)
{
	if (player->laser_y == player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->use_laser_d, (player->laser_x) * 64, (player->laser_y)
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_start_d, (player->laser_x) * 64, (player->laser_y
				+ 1) * 64);
	}
	else if ((size_t)(player->laser_y) == data->nb_line - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64, (player->laser_y + 1)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_row, player->laser_x * 64, (player->laser_y + 1)
			* 64);
	}
}

void	laser_top_player(t_data *data, t_player *player)
{
	player->laser_dir = UP;
	if (data->map[player->laser_y - 1][player->laser_x] == 'L')
	{
		player->is_laser_player = false;
		return ;
	}
	else if (data->map[player->laser_y - 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) >= 2)
	{
		handle_laser_top(data, player);
		--player->laser_y;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	// else if (data->map[player->laser_y - 1][player->laser_x] == 'P')
	// {
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 		data->img->explosion_d, player->laser_x * 64, (player->laser_y - 1)
	// 		* 64);
	// 	data->player->death = true;
	// }
}

void	handle_laser_top(t_data *data, t_player *player)
{
	if (player->laser_y == player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->use_laser_d, (player->laser_x) * 64, (player->laser_y)
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_start_d, (player->laser_x) * 64, (player->laser_y
				- 1) * 64);
	}
	else if (player->laser_y == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64, (player->laser_y - 1)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_row, player->laser_x * 64, (player->laser_y - 1)
			* 64);
	}
}
