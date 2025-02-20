/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_laser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:14:16 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:03:46 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	remove_player_laser_right(t_data *data, t_player *player)
{
	while (player->laser_x != player->pos_x)
	{
		if (data->map[player->laser_y][player->laser_x] == LASER_CHAR)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR],
				player->laser_x * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		--player->laser_x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_R],
		player->pos_x * 64, player->pos_y * 64);
	player->laser_dir = 0;
	player->fire_frame = 0;
	return (1);
}

int	remove_player_laser_left(t_data *data, t_player *player)
{
	while (player->laser_x != player->pos_x)
	{
		if (data->map[player->laser_y][player->laser_x] == LASER_CHAR)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR],
				player->laser_x * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		++player->laser_x;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_L],
		player->pos_x * 64, player->pos_y * 64);
	player->fire_frame = 0;
	player->laser_dir = 0;
	return (1);
}

int	remove_player_laser_down(t_data *data, t_player *player)
{
	while (player->laser_y != player->pos_y)
	{
		if (data->map[player->laser_y][player->laser_x] == LASER_CHAR)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR],
				(player->laser_x) * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		--player->laser_y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_D],
		player->pos_x * 64, player->pos_y * 64);
	player->fire_frame = 0;
	player->laser_dir = 0;
	return (1);
}

int	remove_player_laser_up(t_data *data, t_player *player)
{
	while (player->laser_y != player->pos_y)
	{
		if (data->map[player->laser_y][player->laser_x] == LASER_CHAR)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->sprite[FLOOR],
				(player->laser_x) * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		++player->laser_y;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		player->sprite[PLAYER_T],
		player->pos_x * 64, player->pos_y * 64);
	player->laser_dir = 0;
	player->fire_frame = 0;
	return (1);
}

void	remove_display_laser_p(t_data *data, t_player *player)
{
	if (data->map[player->laser_y][player->laser_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[OBJECT],
			player->laser_x * 64, player->laser_y * 64);
	}
	else if (data->map[player->laser_y][player->laser_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->spaceship->sprite[EXIT_CLOSE], player->laser_x * 64,
				player->laser_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->spaceship->sprite[EXIT_OPEN], player->laser_x * 64,
				player->laser_y * 64);
		}
	}
}
