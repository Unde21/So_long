/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:17:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 03:17:22 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_top(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x, enemy->pos_y - 1) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->defeat == false)
		--enemy->pos_y;
	handle_new_position_t_enemy(data, enemy);
	data->enemy->moved = 1;
}

void	move_enemy_down(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x, enemy->pos_y + 1) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->defeat == false)
		++enemy->pos_y;
	handle_new_position_d_enemy(data, enemy);
	data->enemy->moved = 1;
}

void	move_enemy_right(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x + 1, enemy->pos_y) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->defeat == false)
		++enemy->pos_x;
	handle_new_position_r_enemy(data, enemy);
	data->enemy->moved = 1;
}

void	move_enemy_left(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x - 1, enemy->pos_y) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->end == false)
		--enemy->pos_x;
	handle_new_position_l_enemy(data, enemy);
	data->enemy->moved = 1;
}
