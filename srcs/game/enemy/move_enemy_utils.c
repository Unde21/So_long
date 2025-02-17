/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:36:18 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 05:30:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_new_position_r_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_r_exit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_r_opexit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, enemy->img_right,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
	}
}

void	handle_new_position_l_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_l_exit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_l_opexit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else if (data->map[enemy->pos_y][enemy->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, enemy->img_left,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
	}
}

void	handle_new_position_d_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_d_exit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_d_opexit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else if (data->map[enemy->pos_y][enemy->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, enemy->img_down,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
	}
}

void	handle_new_position_t_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_t_exit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->img_t_opexit, enemy->pos_x * 64, enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else if (data->map[enemy->pos_y][enemy->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, enemy->img_top,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
	}
}
