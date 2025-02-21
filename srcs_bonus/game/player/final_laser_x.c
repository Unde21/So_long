/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_laser_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:20:03 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 20:13:03 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	final_laser_x(t_data *data, t_player *player)
{
	if (player->laser_dir == RIGHT && (size_t)(player->laser_x) <= data->nb_row)
		final_laser_right(data, player);
	if (player->laser_dir == LEFT && player->laser_x >= 0)
		final_laser_left(data, player);
	else
	{
		if (player->pos_x < data->enemy->pos_x)
			player->laser_dir = RIGHT;
		else
			player->laser_dir = LEFT;
	}
}

void	final_laser_left(t_data *data, t_player *player)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_EVO_L], player->pos_x * 64, player->pos_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[FINAL_LINE], player->laser_x * 64, player->laser_y * 64);
	if (player->laser_x == player->pos_x - 1
		&& (size_t)(player->laser_y) < data->nb_line - 2 && player->laser_y > 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_START_T], (player->laser_x) * 64,
			(player->laser_y - 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_START_D], (player->laser_x) * 64,
			(player->laser_y + 1) * 64);
	}
	else if (player->laser_y > 1 && player->laser_x != player->pos_x
		&& (size_t)(player->laser_y) < data->nb_line - 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_LINE_T], (player->laser_x) * 64,
			(player->laser_y - 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_LINE_D], (player->laser_x) * 64,
			(player->laser_y + 1) * 64);
	}
	--player->laser_x;
}

void	final_laser_right(t_data *data, t_player *player)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_EVO_R], player->pos_x * 64, player->pos_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[FINAL_LINE], player->laser_x * 64, player->laser_y * 64);
	if (player->laser_x == player->pos_x + 1
		&& (size_t)(player->laser_y) < data->nb_line - 2 && player->laser_y > 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_STARTR_D], (player->laser_x) * 64,
			(player->laser_y - 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_STARTR_T], (player->laser_x) * 64,
			(player->laser_y + 1) * 64);
	}
	else if (player->laser_y > 1 && player->laser_x != player->pos_x
		&& (size_t)(player->laser_y) < data->nb_line - 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_LINE_T], (player->laser_x) * 64,
			(player->laser_y - 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_LINE_D], (player->laser_x) * 64,
			(player->laser_y + 1) * 64);
	}
	++player->laser_x;
}
