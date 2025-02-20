/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:35:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 02:18:06 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_data *data)
{
	data->img->img[0] = "img_file/floor.xpm";
	data->img->img[1] = "img_file/wall.xpm";
	data->img->img[2] = "img_file/object.xpm";
	data->img->img[3] = "img_file/explosion.xpm";
	data->img->img[4] = "img_file/explosion_r.xpm";
	data->img->img[5] = "img_file/explosion_d.xpm";
	data->img->img[6] = "img_file/explosion_t.xpm";
	data->img->img[7] = "img_file/laser_fight_x.xpm";
	data->img->img[8] = "img_file/laser_fight_y.xpm";
	data->img->img[9] = "img_file/floor_destroyed.xpm";
	init_img_player(data);
	init_img_spaceship(data);
	init_move_count(data);
}

void	init_move_count(t_data *data)
{
	data->img->move[0] = "img_file/nb_zero.xpm";
	data->img->move[1] = "img_file/nb_one.xpm";
	data->img->move[2] = "img_file/nb_two.xpm";
	data->img->move[3] = "img_file/nb_three.xpm";
	data->img->move[4] = "img_file/nb_four.xpm";
	data->img->move[5] = "img_file/nb_five.xpm";
	data->img->move[6] = "img_file/nb_six.xpm";
	data->img->move[7] = "img_file/nb_seven.xpm";
	data->img->move[8] = "img_file/nb_eight.xpm";
	data->img->move[9] = "img_file/nb_nine.xpm";
}

void	init_img_player(t_data *data)
{
	data->player->img[0] = "img_file/player_death_right.xpm";
	data->player->img[1] = "img_file/player_death_left.xpm";
	data->player->img[2] = "img_file/pl_dead_r_exit.xpm";
	data->player->img[3] = "img_file/pl_dead_l_exit.xpm";
	data->player->img[4] = "img_file/player_in_exit.xpm";
	data->player->img[5] = "img_file/player_left_exit.xpm";
	data->player->img[6] = "img_file/player_left.xpm";
	data->player->img[7] = "img_file/player_down.xpm";
	data->player->img[8] = "img_file/player_d_exit.xpm";
	data->player->img[9] = "img_file/player_top.xpm";
	data->player->img[10] = "img_file/player_top_exit.xpm";
	data->player->img[11] = "img_file/player.xpm";
	data->player->img[12] = "img_file/player_laser_r.xpm";
	data->player->img[13] = "img_file/player_laser_l.xpm";
	data->player->img[14] = "img_file/player_laser_d.xpm";
	data->player->img[15] = "img_file/player_laser_t.xpm";
	data->player->img[16] = "img_file/player_evo_r.xpm";
	data->player->img[17] = "img_file/player_evo_l.xpm";
	data->player->img[18] = "img_file/player_evo_d.xpm";
	data->player->img[19] = "img_file/player_evo_t.xpm";
	init_img_laser_player(data);
}

void	init_img_laser_player(t_data *data)
{
	data->player->img[20] = "img_file/final_line.xpm";
	data->player->img[21] = "img_file/final_line_d.xpm";
	data->player->img[22] = "img_file/final_line_t.xpm";
	data->player->img[23] = "img_file/final_start_t.xpm";
	data->player->img[24] = "img_file/final_start_d.xpm";
	data->player->img[25] = "img_file/final_startr_d.xpm";
	data->player->img[26] = "img_file/final_startr_t.xpm";
	data->player->img[27] = "img_file/final_row.xpm";
	data->player->img[28] = "img_file/final_row_r.xpm";
	data->player->img[29] = "img_file/final_row_l.xpm";
	data->player->img[30] = "img_file/final_startd_r.xpm";
	data->player->img[31] = "img_file/final_startd_l.xpm";
	data->player->img[32] = "img_file/final_startt_r.xpm";
	data->player->img[33] = "img_file/final_startt_l.xpm";
	data->player->img[34] = "img_file/player_r_destroy.xpm";
	data->player->img[35] = "img_file/player_l_destroy.xpm";
	data->player->img[36] = "img_file/player_d_destroy.xpm";
	data->player->img[37] = "img_file/player_t_destroy.xpm";
	data->player->img[38] = "img_file/pl_exit_t_destroy.xpm";
	data->player->img[39] = "img_file/pl_exit_d_destroy.xpm";
	data->player->img[40] = "img_file/pl_exit_l_destroy.xpm";
	data->player->img[41] = "img_file/pl_exit_r_destroy.xpm";
}

void	init_img_spaceship(t_data *data)
{
	data->spaceship->img[0] = "img_file/exit_fire.xpm";
	data->spaceship->img[1] = "img_file/trail_fire.xpm";
	data->spaceship->img[2] = "img_file/landing_spaceship.xpm";
	data->spaceship->img[3] = "img_file/exit_close.xpm";
	data->spaceship->img[4] = "img_file/exit_open.xpm";
	data->spaceship->img[5] = "img_file/exit_open_destroy.xpm";
	data->spaceship->img[6] = "img_file/exit_close_destroy.xpm";
}
