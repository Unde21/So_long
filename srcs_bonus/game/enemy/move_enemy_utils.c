/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:36:18 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 06:16:22 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_new_position_r_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_EXIT_R], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_OEXIT_R], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ENEMY_R], enemy->pos_x * 64, enemy->pos_y * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
		else
			data->map[enemy->pos_y][enemy->pos_x] = ENEMY_OBJECT;
	}
}

void	handle_new_position_l_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_EXIT_L], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_OEXIT_L], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else if (data->map[enemy->pos_y][enemy->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ENEMY_L], enemy->pos_x * 64, enemy->pos_y * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
		else
			data->map[enemy->pos_y][enemy->pos_x] = ENEMY_OBJECT;
	}
}

void	handle_new_position_d_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_EXIT_D], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_OEXIT_D], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else if (data->map[enemy->pos_y][enemy->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ENEMY_D], enemy->pos_x * 64, enemy->pos_y * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
		else
			data->map[enemy->pos_y][enemy->pos_x] = ENEMY_OBJECT;
	}
}

void	handle_new_position_t_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'E')
	{
		if (data->spaceship->spaceship_close == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_EXIT_T], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->sprite[ENEM_OEXIT_T], enemy->pos_x * 64,
				enemy->pos_y * 64);
		}
		data->map[enemy->pos_y][enemy->pos_x] = 'Z';
	}
	else if (data->map[enemy->pos_y][enemy->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ENEMY_T], enemy->pos_x * 64, enemy->pos_y * 64);
		if (data->map[enemy->pos_y][enemy->pos_x] != 'C')
			data->map[enemy->pos_y][enemy->pos_x] = 'B';
		else
			data->map[enemy->pos_y][enemy->pos_x] = ENEMY_OBJECT;
	}
}
