/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_old_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 05:27:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 05:35:12 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_old_position_enemy(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x] == 'Z')
		is_spaceship_at_pos(data, enemy);
	else
	{
		if (data->map[enemy->pos_y][enemy->pos_x] == 'B')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->floor, enemy->pos_x * 64, (enemy->pos_y) * 64);
			data->map[enemy->pos_y][enemy->pos_x] = '0';
		}
		else if (data->map[enemy->pos_y][enemy->pos_x] == 'C')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->object, enemy->pos_x * 64, (enemy->pos_y) * 64);
		}
	}
}

void	is_spaceship_at_pos(t_data *data, t_enemy *enemy)
{
	if (data->spaceship->spaceship_close == true)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->spaceship_close, enemy->pos_x * 64, (enemy->pos_y) * 64);
		data->map[enemy->pos_y][enemy->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->spaceship_open, enemy->pos_x * 64, (enemy->pos_y) * 64);
		data->map[enemy->pos_y][enemy->pos_x] = 'E';
	}
}
