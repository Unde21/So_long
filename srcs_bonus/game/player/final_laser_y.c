/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_laser_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:26:13 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:03:10 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	final_laser_y(t_data *data, t_player *player)
{
	if (player->laser_dir == DOWN && player->laser_y >= 0)
		final_laser_down(data, player);
	if (player->laser_dir == UP && (size_t)(player->laser_y) <= data->nb_line)
		final_laser_up(data, player);
}

void	final_laser_down(t_data *data, t_player *player)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_EVO_D], player->pos_x * 64, player->pos_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[FINAL_ROW], player->laser_x * 64, player->laser_y * 64);
	if (player->laser_y == player->pos_y + 1
		&& (size_t)(player->laser_x) < data->nb_row - 2 && player->laser_x > 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_STARTD_L], (player->laser_x - 1) * 64,
			(player->laser_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_STARTD_R], (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
	}
	else if (player->laser_x > 1
		&& (size_t)(player->laser_x) < data->nb_row - 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_ROW_L], (player->laser_x - 1) * 64,
			(player->laser_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_ROW_R], (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
	}
	++player->laser_y;
}

void	final_laser_up(t_data *data, t_player *player)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_EVO_T], player->pos_x * 64, player->pos_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[FINAL_ROW], player->laser_x * 64, player->laser_y * 64);
	if (player->laser_y == player->pos_y - 1
		&& (size_t)(player->laser_x) < data->nb_row - 2 && player->laser_x > 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_STARTT_L], (player->laser_x - 1) * 64,
			(player->laser_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_STARTT_R], (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
	}
	else if (player->laser_x > 1
		&& (size_t)(player->laser_x) < data->nb_row - 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_ROW_L], (player->laser_x - 1) * 64,
			(player->laser_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_ROW_R], (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
	}
	--player->laser_y;
}
