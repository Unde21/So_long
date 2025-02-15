/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_laser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:14:16 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/15 10:35:17 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	remove_player_laser_right(t_data *data, t_player *player)
{
	while (player->laser_x != player->pos_x)
	{
		if (data->map[player->laser_y][player->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, player->laser_x * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		--player->laser_x;
	}
	player->fire_frame = 0; //BUG a voir 
	return (1);
}

int	remove_player_laser_left(t_data *data, t_player *player)
{
	while (player->laser_x != player->pos_x)
	{
		if (data->map[player->laser_y][player->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, (player->laser_x) * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		ft_printf("map:%s\n", data->map[player->laser_y]);
		++player->laser_x;
	}
	player->fire_frame = 0; //BUG a voir 
	return (1);
}

int	remove_player_laser_down(t_data *data, t_player *player)
{
	while (player->laser_y != player->pos_y)
	{
		if (data->map[player->laser_y][player->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, (player->laser_x) * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		--player->laser_y;
	}
	player->fire_frame = 0; //BUG a voir 
	return (1);
}

int	remove_player_laser_up(t_data *data, t_player *player)
{
	while (player->laser_y != player->pos_y)
	{
		if (data->map[player->laser_y][player->laser_x] == 'L')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, (player->laser_x) * 64, player->laser_y * 64);
			data->map[player->laser_y][player->laser_x] = '0';
		}
		remove_display_laser_p(data, player);
		++player->laser_y;
	}
	player->fire_frame = 0; //BUG a voir 

	return (1);
}

void	remove_display_laser_p(t_data *data, t_player *player)
{
	if (data->map[player->laser_y][player->laser_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->object,
			player->laser_x * 64, player->laser_y * 64);
	}
	else if (data->map[player->laser_y][player->laser_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->spaceship_close, (player->laser_x) * 64,
				player->laser_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->spaceship_open, (player->laser_x) * 64,
				player->laser_y * 64);
		}
	}
}
