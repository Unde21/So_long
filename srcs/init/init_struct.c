/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:10:11 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 14:19:31 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_spaceship(t_spaceship *spaceship)
{
	spaceship->spaceship_close = true;
	spaceship->spaceship_is_here = false;
	spaceship->pos_y = 0;
	spaceship->pos_x = 0;
	spaceship->frame = 0;
}

void	init_struct_player(t_player *player)
{
	player->is_start_pos = false;
	player->pos_x = 0;
	player->pos_y = 0;
	player->pl_dead_r = NULL;
	player->pl_dead_l = NULL;
	player->pl_dead_l_exit = NULL;
	player->pl_dead_r_exit = NULL;
	player->dir_left = false;
	player->death_frame = 0;
	player->death = false;
	player->last_move = 0;
}

int	init_struct_data(t_data *data, t_spaceship *spaceship, t_player *player,
		t_img *img)
{
	data->img = img;
	data->spaceship = spaceship;
	data->player = player;
	data->nb_obj = 0;
	data->count_key = 0;
	data->nb_line = 0;
	data->nb_row = 0;
	data->screen_height = 0;
	data->screen_width = 0;
	data->fd = 0;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->end = false;
	if (gettimeofday(&data->last_time, NULL) == -1)
		return (-1);
	return (0);
}

void	add_enemy_data(t_data *data, t_enemy	*enemy)
{
	data->enemy = enemy;
}
void	init_struct_img(t_img *img)
{
	img->nb_zero = NULL;
	img->nb_one = NULL;
	img->nb_two = NULL;
	img->nb_three = NULL;
	img->nb_four = NULL;
	img->nb_five = NULL;
	img->nb_six = NULL;
	img->nb_seven = NULL;
	img->nb_eight = NULL;
	img->nb_nine = NULL;
	img->floor = NULL;
	img->player = NULL;
	img->player_l = NULL;
	img->player_d = NULL;
	img->player_t = NULL;
	img->object = NULL;
	img->wall = NULL;
	img->spaceship_close = NULL;
	img->spaceship_open = NULL;
	img->plright_exit = NULL;
	img->pleft_exit = NULL;
	img->pdown_exit = NULL;
	img->ptop_exit = NULL;
	img->exit_fire = NULL;
	img->trail_fire = NULL;
	img->height = 0;
	img->width = 0;
}
