/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/11 12:28:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	move_enemy(t_data *data, t_enemy *enemy)
{
	int	random;
	
	srand(time(NULL));
	random = rand() % 1000;
	ft_printf("random : %d\n", random);
	if (random > 750)
		move_enemy_top(data, enemy);
	else if (random > 500 )	
		move_enemy_right(data, enemy);
	else if (random > 250)
		move_enemy_down(data, enemy);
	else if (random > 0)
		move_enemy_left(data, enemy);
	return (0);
}

void	move_enemy_top(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y - 1][enemy->pos_x] == 'P')
	{
		if (data->player->dir_left == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
	}
	else if (data->map[enemy->pos_y - 1][enemy->pos_x] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->img_top, data->enemy->pos_x * 64,
			(data->enemy->pos_y - 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, data->enemy->pos_x * 64,
			data->enemy->pos_y * 64);
		--enemy->pos_y;
		data->map[enemy->pos_y][enemy->pos_x - 1] = 'B';
	}
}

void	move_enemy_down(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y + 1][enemy->pos_x] == 'P')
	{
		if (data->player->dir_left == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
	}
	else if (data->map[enemy->pos_y + 1][enemy->pos_x] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->img_down, data->enemy->pos_x * 64,
			(data->enemy->pos_y + 1) * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, data->enemy->pos_x * 64,
			data->enemy->pos_y * 64);
		++enemy->pos_y;
		data->map[enemy->pos_y][enemy->pos_x - 1] = 'B';
	}
}

void	move_enemy_right(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x + 1] == 'P')
	{
		if (data->player->dir_left == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
	}
	else if (data->map[enemy->pos_y][enemy->pos_x + 1] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->img_right, (data->enemy->pos_x + 1) * 64,
			data->enemy->pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, data->enemy->pos_x * 64,
			data->enemy->pos_y * 64);
		++enemy->pos_x;
		data->map[enemy->pos_y][enemy->pos_x - 1] = 'B';
	}
}

void	move_enemy_left(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->pos_y][enemy->pos_x - 1] == 'P')
	{
		if (data->player->dir_left == true)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_l, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->player->pl_dead_r, data->player->pos_x * 64,
				data->player->pos_y * 64);
		}
	}
	else if (data->map[enemy->pos_y][enemy->pos_x - 1] == '0')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->img_left, (data->enemy->pos_x - 1)* 64,
			data->enemy->pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, data->enemy->pos_x * 64,
			data->enemy->pos_y * 64);
		--enemy->pos_x;
		data->map[enemy->pos_y][enemy->pos_x - 1] = 'B';
	}
}
