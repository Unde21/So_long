/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_player_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:26:04 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:03:01 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_laser_status(t_data *data, t_player *player)
{
	if (check_dir_laser(data, player) == 1)
		return ;
	if (player->is_fighting_laser == true && player->laser_dir == DOWN)
	{
		remove_player_laser_down(data, player);
		player->is_laser_player = false;
		player->is_fighting_laser = false;
		player->laser_dir = 0;
		remove_enemy_laser_up(data, data->enemy);
	}
	else if (player->is_fighting_laser == true && player->laser_dir == UP)
	{
		remove_player_laser_up(data, player);
		player->is_laser_player = false;
		player->is_fighting_laser = false;
		player->laser_dir = 0;
		remove_enemy_laser_down(data, data->enemy);
	}
	else if (player_laser(data, player) == 1)
		player->is_laser_player = false;
}

int	check_dir_laser(t_data *data, t_player *player)
{
	if (player->is_fighting_laser == true && player->laser_dir == LEFT)
	{
		remove_player_laser_left(data, player);
		player->is_laser_player = false;
		player->is_fighting_laser = false;
		player->laser_dir = 0;
		remove_enemy_laser_right(data, data->enemy);
		return (1);
	}
	else if (player->is_fighting_laser == true && player->laser_dir == RIGHT)
	{
		remove_player_laser_right(data, player);
		player->is_laser_player = false;
		player->is_fighting_laser = false;
		player->laser_dir = 0;
		remove_enemy_laser_left(data, data->enemy);
		return (1);
	}
	return (0);
}
