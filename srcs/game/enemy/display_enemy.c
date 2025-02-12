/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:54:55 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 16:26:49 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_enemy(t_data *data)
{
	if (data->enemy->is_start_pos == true)
	{
		if (data->player->pos_x < data->enemy->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->img_left, data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->player, data->player->pos_x * 64, data->player->pos_y
				* 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->img_right, data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->player_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
	}
}

int	touch_enemy(t_data *data, int next_x, int next_y)
{
	if ((data->map[next_y][next_x] == 'B' || data->map[next_y][next_x] == 'Z') && data->player->dir_left == false)
	{
		if (data->map[next_y][next_x] == 'Z' && data->spaceship->pos_x == next_x && data->spaceship->pos_y == next_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r_exit, next_x * 64,
				next_y * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, data->player->pos_x * 64,
				data->player->pos_y * 64);
				data->defeat = true;
			ft_printf("touch_enemy\n");

		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);	
		}
		data->player->death = true;
		return (1);
	}
	else if ((data->map[next_y][next_x] == 'B' || data->map[next_y][next_x] == 'Z') && data->player->dir_left == true)
	{
		if (data->map[next_y][next_x] == 'Z' && data->spaceship->pos_x == next_x && data->spaceship->pos_y == next_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l_exit, next_x * 64,
				next_y * 64);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, data->player->pos_x * 64,
				data->player->pos_y * 64);
				data->defeat = true;
		}
		else
		{
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
	if ((data->map[next_y][next_x] == 'S' || data->map[next_y][next_x] == 'P') && data->player->dir_left == false)
	{
		if (data->map[next_y][next_x] == 'S')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r_exit, data->player->pos_x * 64,
				data->player->pos_y * 64);
			// data->defeat = true;
			ft_printf("touch_player\n");
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);	
		}
		data->player->death = true;
		return (1);
	}
	else if ((data->map[next_y][next_x] == 'S' || data->map[next_y][next_x] == 'P') && data->player->dir_left == true)
	{
		if (data->map[next_y][next_x] == 'S')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l_exit, data->player->pos_x * 64,
				data->player->pos_y * 64);
			// data->defeat = true;
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);	
		}
		data->player->death = true;
		return (1);
	}
	return (0);
}
