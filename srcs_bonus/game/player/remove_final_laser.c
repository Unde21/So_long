/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_final_laser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:36:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:03:43 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_final_laser(t_data *data, t_player *player)
{
	if (player->laser_x == 0 || player->laser_y == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT], (player->laser_x) * 64, player->laser_y
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT], (player->laser_x) * 64, (player->laser_y
				+ 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT], (player->laser_x) * 64, (player->laser_y
				- 1) * 64);
	}
	if (player->laser_dir == LEFT)
		remove_final_laser_left(data, player);
	else if (player->laser_dir == RIGHT)
		remove_final_laser_right(data, player);
	else if (player->laser_dir == DOWN)
		remove_final_laser_down(data, player);
	else if (player->laser_dir == UP)
		remove_final_laser_up(data, player);
}

void	remove_final_laser_left(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_x != player->pos_x)
	{
		remove_final_laser_line(data, player);
		++player->laser_x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_L], player->pos_x * 64, player->pos_y * 64);
}

void	remove_final_laser_right(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_x != player->pos_x)
	{
		remove_final_laser_line(data, player);
		--player->laser_x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_R], player->pos_x * 64, player->pos_y * 64);
}

void	remove_final_laser_down(t_data *data, t_player *player)
{
	player->final_laser = false;
	--player->laser_y;
	while (player->laser_y != player->pos_y)
	{
		remove_final_laser_row(data, player);
		--player->laser_y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_D], player->pos_x * 64, player->pos_y * 64);
}

void	remove_final_laser_up(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_y != player->pos_y)
	{
		remove_final_laser_row(data, player);
		++player->laser_y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_T], player->pos_x * 64, player->pos_y * 64);
}
