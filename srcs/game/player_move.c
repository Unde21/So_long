/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 06:58:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 12:04:00 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	move_up(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x, player->pos_y - 1, 1) != 0)
		return ;
	handle_old_position(data, player, img);
	--player->pos_y;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_t(data, player, img);
	++data->count_key;
	player->last_move = KEY_UP;
	display_count_move(data);
}

void	move_right(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x + 1, player->pos_y, 0) != 0)
		return ;
	handle_old_position(data, player, img);
	++player->pos_x;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_r(data, player, img);
	player->dir_left = false;
	++data->count_key;
	player->last_move = KEY_RIGHT;
	display_count_move(data);
}

void	move_left(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x - 1, player->pos_y, 1) != 0)
		return ;
	handle_old_position(data, player, img);
	--player->pos_x;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_l(data, player, img);
	player->dir_left = true;
	++data->count_key;
	player->last_move = KEY_LEFT;
	display_count_move(data);
}

void	move_down(t_data *data, t_player *player, t_img *img)
{
	if (touch_enemy(data, player->pos_x, player->pos_y + 1, 0) != 0)
		return ;
	handle_old_position(data, player, img);
	++player->pos_y;
	if (data->map[player->pos_y][player->pos_x] == 'C')
		--data->nb_obj;
	handle_new_position_d(data, player, img);
	++data->count_key;
	player->last_move = KEY_DOWN;
	display_count_move(data);
}

int	keypress(int keysym, t_data *data)
{
	if (data->player->death == true || data->end == true)
		return (0);
	if (keysym == KEY_CLOSE)
	{
		close_window(data);
	}
	else if (keysym == KEY_UP
		&& data->map[data->player->pos_y - 1][data->player->pos_x] != '1')
		move_up(data, data->player, data->img);
	else if (keysym == KEY_RIGHT
		&& data->map[data->player->pos_y][data->player->pos_x + 1] != '1')
		move_right(data, data->player, data->img);
	else if (keysym == KEY_LEFT
		&& data->map[data->player->pos_y][data->player->pos_x - 1] != '1')
		move_left(data, data->player, data->img);
	else if (keysym == KEY_DOWN
		&& data->map[data->player->pos_y + 1][data->player->pos_x] != '1')
		move_down(data, data->player, data->img);
	if (data->nb_obj == 0 && data->spaceship->spaceship_close == true)
		open_spaceship(data, data->img);
	check_end(data, data->player);
	return (0);
}
