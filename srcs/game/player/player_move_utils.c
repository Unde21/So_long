/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:35:20 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/18 03:11:02 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_old_position(t_data *data, t_player *player, t_img *img)
{
	if (data->map[player->pos_y][player->pos_x] == 'S')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_CLOSE], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->sprite[FLOOR], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = '0';
	}
}

void	handle_new_position_r(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_R_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] == 'S'
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_R_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'E';
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_R], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}

void	handle_new_position_l(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_L_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] == 'S'
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_L_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'E';
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_L], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}

void	handle_new_position_d(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_D_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] == 'S'
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_D_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'E';
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_D], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}

void	handle_new_position_t(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_T_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] == 'S'
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_T_EXIT], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'E';
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_T], player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}
