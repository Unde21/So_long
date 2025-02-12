/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 11:22:01 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int	move_enemy(t_data *data)
{
	struct timeval current_time;
	long	elapsed_time;
	
	if (data->end == true || data->player->death == true || data->end == true)
		return (0);
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - data->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - data->last_time.tv_usec) / 1000;  // modifier la division par une multiplication
	if (elapsed_time > 500)
	{
		if (data->player->pos_y < data->enemy->pos_y)
				move_enemy_top(data, data->enemy);
		else if (data->player->pos_x > data->enemy->pos_x)	
				move_enemy_right(data, data->enemy);
		else if (data->player->pos_y > data->enemy->pos_y)
				move_enemy_down(data, data->enemy);
		else if (data->player->pos_x < data->enemy->pos_x)
				move_enemy_left(data, data->enemy);	
		data->last_time = current_time;
	}
	
	return (0);
}

void	move_enemy_top(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x, enemy->pos_y - 1) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	--enemy->pos_y;
	handle_new_position_t_enemy(data, enemy);
}

void	move_enemy_down(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x, enemy->pos_y + 1) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	++enemy->pos_y;
	handle_new_position_d_enemy(data, enemy);
}

void	move_enemy_right(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x + 1, enemy->pos_y) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	++enemy->pos_x;
	handle_new_position_r_enemy(data, enemy);
}

void	move_enemy_left(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x - 1, enemy->pos_y) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	--enemy->pos_x;
	handle_new_position_l_enemy(data, enemy);
}
