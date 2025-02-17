/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:07:50 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 03:11:25 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	touch_enemy(t_data *data, int next_x, int next_y)
{
	if ((data->map[next_y][next_x] == 'B' || data->map[next_y][next_x] == 'Z'
			|| data->map[next_y][next_x] == 'L')
		&& data->player->dir_left == false)
	{
		if (data->map[next_y][next_x] == 'Z' && data->spaceship->pos_x == next_x
			&& data->spaceship->pos_y == next_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r_exit, next_x * 64, next_y * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, data->player->pos_x * 64, data->player->pos_y
				* 64);
			data->defeat = true;
		}
		else
		{
			display_attack_enemy(data, data->enemy);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		data->player->death = true;
		return (1);
	}
	return (touch_enemy_left(data, next_x, next_y));
}

int	touch_enemy_left(t_data *data, int next_x, int next_y)
{
	if ((data->map[next_y][next_x] == 'B' || data->map[next_y][next_x] == 'Z'
			|| data->map[next_y][next_x] == 'L')
		&& data->player->dir_left == true)
	{
		if (data->map[next_y][next_x] == 'Z' && data->spaceship->pos_x == next_x
			&& data->spaceship->pos_y == next_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l_exit, next_x * 64, next_y * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, data->player->pos_x * 64, data->player->pos_y
				* 64);
			data->defeat = true;
		}
		else
		{
			display_attack_enemy(data, data->enemy);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		data->player->death = true;
		return (1);
	}
	return (0);
}

int	touch_player(t_data *data, int next_x, int next_y)
{
	if ((data->map[next_y][next_x] == 'S' || data->map[next_y][next_x] == 'P')
		&& data->player->dir_left == false)
	{
		if (data->map[next_y][next_x] == 'S')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r_exit, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		display_attack_enemy(data, data->enemy);
		data->player->death = true;
		return (1);
	}
	return (touch_player_left(data, next_x, next_y));
}

int	touch_player_left(t_data *data, int next_x, int next_y)
{
	if ((data->map[next_y][next_x] == 'S' || data->map[next_y][next_x] == 'P')
		&& data->player->dir_left == true)
	{
		if (data->map[next_y][next_x] == 'S')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l_exit, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		display_attack_enemy(data, data->enemy);
		data->player->death = true;
		return (1);
	}
	return (0);
}
