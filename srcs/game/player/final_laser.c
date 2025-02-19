/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_laser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 03:28:22 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 00:34:40 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	disp_final_laser(t_data *data, t_player *player)
{
	struct timeval	current_time;
	long			elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - player->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - player->last_time.tv_usec) / 1000;
	if (elapsed_time >= LASER_MVE_FRAME)
	{
		if ((size_t)(player->laser_x) == (data->nb_row)
			|| (size_t)(player->laser_y) == data->nb_line
			|| (player->laser_y == 0 || player->laser_x == 0))
		{
			remove_final_laser(data, data->player);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->sprite[DESTROY_ENEMY], data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);
			return ;
		}
			
		if (player->pos_x != data->enemy->pos_x)
			final_laser_x(data, player);
		else if (player->pos_y != data->enemy->pos_y)
			final_laser_y(data, player);
		player->last_time = current_time;
	}
}

void	reset_laser_pos(t_data *data, t_player *player)
{
	if (player->pos_x < data->enemy->pos_x)
		data->player->laser_x = data->player->pos_x + 1;
	if (player->pos_x > data->enemy->pos_x)
		data->player->laser_x = data->player->pos_x - 1;
	if (player->pos_y < data->enemy->pos_y)
		data->player->laser_y = data->player->pos_y + 1;
	if (player->pos_y > data->enemy->pos_y)
		data->player->laser_y = data->player->pos_y - 1;
}

void	final_laser_y(t_data *data, t_player *player)
{
	if (player->laser_dir == DOWN && player->laser_y >= 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_D], (player->pos_x) * 64,
			(player->pos_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_ROW], (player->laser_x) * 64,
			(player->laser_y) * 64);
		if (player->laser_y == player->pos_y + 1 && (size_t)(player->laser_x) < data->nb_row - 2 && player->laser_x > 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				player->sprite[FINAL_STARTD_L], (player->laser_x - 1) * 64,
				(player->laser_y - 1) * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					player->sprite[FINAL_STARTD_R], (player->laser_x + 1) * 64,
					(player->laser_y) * 64);
		}
		if (player->laser_x > 1 && (size_t)(player->laser_x) < data->nb_row - 2)
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
	if (player->laser_dir == UP && (size_t)(player->laser_y) <= data->nb_line)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_EVO_T], (player->pos_x) * 64,
			(player->pos_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_ROW], (player->laser_x) * 64,
			(player->laser_y) * 64);
		if (player->laser_y == player->pos_y - 1 && (size_t)(player->laser_x) < data->nb_row - 2 && player->laser_x > 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				player->sprite[FINAL_STARTT_L], (player->laser_x - 1) * 64,
				(player->laser_y) * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					player->sprite[FINAL_STARTT_R], (player->laser_x + 1) * 64,
					(player->laser_y) * 64);
		}
		else if (player->laser_x > 1 && (size_t)(player->laser_x) < data->nb_row - 2)
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
}

void	final_laser_x(t_data *data, t_player *player)
{
	if (player->laser_dir == RIGHT && (size_t)(player->laser_x) <= data->nb_row)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_EVO_R], (player->pos_x) * 64,
			(player->pos_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_LINE], (player->laser_x) * 64,
			(player->laser_y) * 64);
		if (player->laser_x == player->pos_x + 1 && (size_t)(player->laser_y) < data->nb_line - 2 && player->laser_y > 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				player->sprite[FINAL_STARTR_D], (player->laser_x) * 64,
				(player->laser_y - 1) * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					player->sprite[FINAL_STARTR_T], (player->laser_x) * 64,
					(player->laser_y + 1) * 64);
		}
		else if (player->laser_y > 1 && (size_t)(player->laser_y) < data->nb_line - 2)
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
	if (player->laser_dir == LEFT && player->laser_x >= 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_EVO_L], (player->pos_x) * 64,
			(player->pos_y) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[FINAL_LINE], (player->laser_x) * 64,
			(player->laser_y) * 64);
		if (player->laser_x == player->pos_x - 1 && (size_t)(player->laser_y) < data->nb_line - 2 && player->laser_y > 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				player->sprite[FINAL_START_T], (player->laser_x) * 64,
				(player->laser_y - 1) * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					player->sprite[FINAL_START_D], (player->laser_x) * 64,
					(player->laser_y + 1) * 64);
		}
		else if (player->laser_y > 1 && (size_t)(player->laser_y) < data->nb_line - 2)
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
}
