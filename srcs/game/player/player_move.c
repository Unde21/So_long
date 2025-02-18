/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:58:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 02:34:09 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	move_up(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x, player->pos_y - 1) != 0)
		return ;
	handle_old_position(data, player, img);
	--player->pos_y;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_t(data, player);
	++data->count_key;
	player->last_move = UP;
	display_count_move(data);
}

void	move_right(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x + 1, player->pos_y) != 0)
		return ;
	handle_old_position(data, player, img);
	++player->pos_x;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_r(data, player);
	player->dir_left = false;
	++data->count_key;
	player->last_move = RIGHT;
	display_count_move(data);
}

void	move_left(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x - 1, player->pos_y) != 0)
		return ;
	handle_old_position(data, player, img);
	--player->pos_x;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_l(data, player);
	player->dir_left = true;
	++data->count_key;
	player->last_move = LEFT;
	display_count_move(data);
}

void	move_down(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x, player->pos_y + 1) != 0)
		return ;
	handle_old_position(data, player, img);
	++player->pos_y;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_d(data, player);
	++data->count_key;
	player->last_move = DOWN;
	display_count_move(data);
}
