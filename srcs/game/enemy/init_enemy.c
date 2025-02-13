/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:56:25 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/13 11:05:02 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_enemy(t_enemy *enemy)
{
	enemy->img_top = NULL;
	enemy->img_down = NULL;
	enemy->img_left = NULL;
	enemy->img_right = NULL;
	enemy->img_t_exit = NULL;
	enemy->img_d_exit = NULL;
	enemy->img_l_exit = NULL;
	enemy->img_r_exit = NULL;
	enemy->img_t_opexit = NULL;
	enemy->img_d_opexit = NULL;
	enemy->img_l_opexit = NULL;
	enemy->img_r_opexit = NULL;
	enemy->pos_x = 0;
	enemy->pos_y = 0;
	enemy->is_start_pos = false;
	enemy->is_laser_enemy = false;
	enemy->height = 0;
	enemy->width = 0;
	enemy->moved = false;
	enemy->laser_x = 0;
	enemy->laser_y = 0;
	enemy->laser_frame = 0;
}

void	init_enemy_img(t_data *data)
{
	data->enemy->img[0] = "img_file/enemy_l_floor.xpm";
	data->enemy->img[1] = "img_file/enemy_d_floor.xpm";
	data->enemy->img[2] = "img_file/enemy_t_floor.xpm";
	data->enemy->img[3] = "img_file/enemy_r_floor.xpm";
	data->enemy->img[4] = "img_file/enemy_l_exit.xpm";
	data->enemy->img[5] = "img_file/enemy_d_exit.xpm";
	data->enemy->img[6] = "img_file/enemy_t_exit.xpm";
	data->enemy->img[7] = "img_file/enemy_r_exit.xpm";
	data->enemy->img[8] = "img_file/enemy_l_opexit.xpm";
	data->enemy->img[9] = "img_file/enemy_d_opexit.xpm";
	data->enemy->img[10] = "img_file/enemy_t_opexit.xpm";
	data->enemy->img[11] = "img_file/enemy_r_opexit.xpm";
	data->enemy->img[12] = "img_file/enemy_l_attack.xpm";
	data->enemy->img[13] = "img_file/enemy_d_attack.xpm";
	data->enemy->img[14] = "img_file/enemy_t_attack.xpm";
	data->enemy->img[15] = "img_file/enemy_r_attack.xpm";
}
