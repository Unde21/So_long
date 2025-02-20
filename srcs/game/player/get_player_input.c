/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:32:36 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 01:27:04 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keysym, t_data *data)
{
	if (data->player->death == true || data->end == true
		|| data->landing == true)
		return (0);
	input_action(keysym, data);
	if (data->nb_obj == 0 && data->spaceship->spaceship_close == true)
		open_spaceship(data, data->spaceship);
	check_end(data, data->player);
	return (0);
}

void	input_action(int keysym, t_data *data)
{
	if (data->player->final_laser == true)
		return ;
	if (keysym == KEY_CLOSE)
		close_window(data);
	else if (keysym == UP && data->player->is_laser_player == false
		&& data->map[data->player->pos_y - 1][data->player->pos_x] != '1')
		move_up(data, data->player, data->img);
	else if (keysym == RIGHT && data->player->is_laser_player == false
		&& data->map[data->player->pos_y][data->player->pos_x + 1] != '1')
		move_right(data, data->player, data->img);
	else if (keysym == LEFT && data->player->is_laser_player == false
		&& data->map[data->player->pos_y][data->player->pos_x - 1] != '1')
		move_left(data, data->player, data->img);
	else if (keysym == DOWN && data->player->is_laser_player == false
		&& data->map[data->player->pos_y + 1][data->player->pos_x] != '1')
		move_down(data, data->player, data->img);
	else if (keysym == FIRE && data->enemy->is_alive == true)
	{
		attack_player(data, data->player);
		++data->count_key;
		display_count_move(data);
	}
}
