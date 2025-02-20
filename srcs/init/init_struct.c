/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:10:11 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 04:27:15 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_spaceship(t_spaceship *spaceship)
{
	int	i;

	spaceship->spaceship_close = true;
	spaceship->spaceship_is_here = false;
	spaceship->pos_y = 0;
	spaceship->pos_x = 0;
	spaceship->frame = 0;
	spaceship->final_y = 0;
	i = 0;
	while (i < 7)
	{
		spaceship->sprite[i] = NULL;
		++i;
	}
}

int	init_struct_player(t_player *player)
{
	int	i;

	i = -1;
	player->is_start_pos = false;
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_left = false;
	player->frames = 0;
	player->death = false;
	player->fire_frame = 0;
	player->last_move = 0;
	player->s_pos_x = 0;
	player->s_pos_y = 0;
	player->laser_x = 0;
	player->laser_y = 0;
	player->laser_dir = 0;
	player->is_laser_player = false;
	player->is_fighting_laser = false;
	player->final_laser = false;
	while (++i < 41)
		player->sprite[i] = NULL;
	if (gettimeofday(&player->last_time, NULL) == -1)
		return (-1);
	return (0);
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
	data->defeat = false;
	data->landing = true;
	if (gettimeofday(&data->last_time, NULL) == -1)
		return (-1);
	return (0);
}

void	add_enemy_data(t_data *data, t_enemy *enemy)
{
	data->enemy = enemy;
}

void	init_struct_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		img->sprite[i] = NULL;
		++i;
	}
	i = 0;
	while (i < 10)
	{
		img->move_spr[i] = NULL;
		++i;
	}
	img->height = 0;
	img->width = 0;
}
