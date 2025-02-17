/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:54:55 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 03:08:07 by samaouch         ###   ########lyon.fr   */
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
