/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_after_final_laser.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:34:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 02:37:25 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_destroy_floor_t(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_T], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_EXIT;
	}
	else if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_T], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = DEST_EXIT;
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != DEST_EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_T_DESTROY], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_FLOOR;
	}
}

void	check_destroy_floor_d(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_D], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_EXIT;
	}
	else if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_D], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = DEST_EXIT;
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != DEST_EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_D_DESTROY], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_FLOOR;
	}
}

void	check_destroy_floor_r(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_R], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_EXIT;
	}
	else if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_R], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = DEST_EXIT;
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != DEST_EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_R_DESTROY], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_FLOOR;
	}
}

void	check_destroy_floor_l(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_L], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_EXIT;
	}
	else if (data->map[player->pos_y][player->pos_x] == DEST_EXIT
		&& data->nb_obj == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[EXIT_DESTROY_L], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = DEST_EXIT;
		data->end = true;
	}
	else if (data->map[player->pos_y][player->pos_x] != DEST_EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PLAYER_L_DESTROY], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = PL_DEST_FLOOR;
	}
}

void	check_destroy_old_position(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == PL_DEST_EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_DESTROY], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = DEST_EXIT;
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[DESTROY_FLOOR], player->pos_x * 64,
			player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = DEST_FLOOR;
	}
}
