/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:49:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 18:26:04 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_update(t_data *data)
{
	if (data->player->death == true && data->end == false && data->defeat == false)
	{
		++data->player->frames;
		if (data->player->frames >= END_FRAME)
			close_window(data);
		return (0);
	}
	if (data->end == true && data->defeat == false)
	{
		++data->spaceship->frame;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->trail_fire, data->player->pos_x * 64,
				data->player->pos_y * 64 - data->spaceship->frame / 100);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->exit_fire, data->player->pos_x * 64,
				data->player->pos_y * 64 - data->spaceship->frame / 50);
		if (data->spaceship->frame >= END_FRAME)
			close_window(data);
		return (0);
	}
	else if (data->end == false && data->defeat == true)
	{
		++data->spaceship->frame;
		if (data->player->dir_left == false)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);	
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->enemy->pos_x * 64,
				data->enemy->pos_y * 64);
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->trail_fire, data->enemy->pos_x * 64,
				data->enemy->pos_y * 64 - data->spaceship->frame / 100);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->exit_fire, data->enemy->pos_x * 64,
				data->enemy->pos_y * 64 - data->spaceship->frame / 50);
		if (data->spaceship->frame >= END_FRAME)
			close_window(data);
		return (0);
	}
	else if (data->enemy->is_start_pos == true && data->landing == false)
		return (move_enemy(data));
	else
		landing_spaceship(data);
	return (0);
}

void	landing_spaceship(t_data *data)
{
	++data->player->frames;
		if (data->player->frames >= LANDING_FRAME)
		{
			data->player->frames = 0;
			if (data->spaceship->final_y <= data->spaceship->pos_y)
			{
				if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y - 1][data->spaceship->pos_x] == '1')
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->wall, data->spaceship->pos_x * 64,
						(data->spaceship->final_y - 1)* 64);	
				}
				else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y - 1][data->spaceship->pos_x] == '0')
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->floor, data->spaceship->pos_x * 64,
						(data->spaceship->final_y - 1)* 64);
				}
				else if (data->spaceship->final_y >= 1 && data->map[data->spaceship->final_y - 1][data->spaceship->pos_x] == 'C')
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->object, data->spaceship->pos_x * 64,
						(data->spaceship->final_y - 1)* 64);
				}
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->landing_spaceship, data->spaceship->pos_x * 64,
				data->spaceship->final_y * 64);	
			}
			else
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->spaceship_close, data->spaceship->pos_x * 64,
				data->spaceship->pos_y * 64);	
				data->landing = false;
			}
			++data->spaceship->final_y;
		}
}
