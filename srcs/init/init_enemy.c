/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:56:25 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 04:26:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_enemy(t_enemy *enemy)
{
	int	i;

	i = 0;
	enemy->pos_x = 0;
	enemy->pos_y = 0;
	enemy->is_start_pos = false;
	enemy->is_laser_enemy = false;
	enemy->height = 0;
	enemy->width = 0;
	enemy->moved = false;
	enemy->is_fighting_laser = false;
	enemy->is_alive = true;
	enemy->laser_x = 0;
	enemy->laser_y = 0;
	enemy->laser_dir = 0;
	enemy->laser_frame = 0;
	enemy->s_pos_x = 0;
	enemy->s_pos_y = 0;
	enemy->life = LIFE;
	while (i < 31)
	{
		enemy->sprite[i] = NULL;
		++i;
	}
}

int	init_enemy_img(t_data *data)
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
	init_enemy_img_laser(data);
	if (check_access_sprite_enemy(data->enemy) != 0)
		return (-1);
	return (0);
}

void	init_enemy_img_laser(t_data *data)
{
	data->enemy->img[16] = "img_file/laser_line.xpm";
	data->enemy->img[17] = "img_file/laser_start_r.xpm";
	data->enemy->img[18] = "img_file/laser_start_l.xpm";
	data->enemy->img[19] = "img_file/use_laser_l.xpm";
	data->enemy->img[20] = "img_file/use_laser_r.xpm";
	data->enemy->img[21] = "img_file/laser_row.xpm";
	data->enemy->img[22] = "img_file/laser_start_d.xpm";
	data->enemy->img[23] = "img_file/laser_start_t.xpm";
	data->enemy->img[24] = "img_file/use_laser_d.xpm";
	data->enemy->img[25] = "img_file/use_laser_t.xpm";
	data->enemy->img[26] = "img_file/destroy_wall.xpm";
	data->enemy->img[27] = "img_file/enemy_dead.xpm";
	data->enemy->img[28] = "img_file/destroy_enemy.xpm";
	data->enemy->img[29] = "img_file/life_green.xpm";
	data->enemy->img[30] = "img_file/life_red.xpm";
}
