/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_after_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:04:33 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 03:06:42 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_in_line_after_destroy(t_data *data, t_enemy *enemy)
{
	if (enemy->moved == RIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], (enemy->pos_x + 1) * 64,
			enemy->pos_y * 64);
		data->map[enemy->pos_y][enemy->pos_x + 1] = '0';
		move_enemy_right(data, enemy);
	}
	else if (enemy->moved == LEFT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], (enemy->pos_x - 1) * 64,
			enemy->pos_y * 64);
		data->map[enemy->pos_y][enemy->pos_x - 1] = '0';
		move_enemy_left(data, enemy);
	}
}

void	move_in_row_after_destroy(t_data *data, t_enemy *enemy)
{
	if (enemy->moved == DOWN)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], enemy->pos_x * 64,
			(enemy->pos_y + 1) * 64);
		data->map[enemy->pos_y + 1][enemy->pos_x] = '0';
		move_enemy_down(data, enemy);
	}
	else if (enemy->moved == UP)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], enemy->pos_x * 64,
			(enemy->pos_y - 1) * 64);
		data->map[enemy->pos_y - 1][enemy->pos_x] = '0';
		move_enemy_top(data, enemy);
	}
}
