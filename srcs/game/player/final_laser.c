/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_laser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 03:28:22 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 02:29:17 by samaouch         ###   ########lyon.fr   */
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
