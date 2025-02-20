/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:35:20 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:01:47 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_old_position(t_data *data, t_player *player, t_img *img)
{
	if (data->map[player->pos_y][player->pos_x] == 'S')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->spaceship_close, player->pos_x * 64, (player->pos_y) * 64);
		data->map[player->pos_y][player->pos_x] = 'E';
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->floor,
			player->pos_x * 64, (player->pos_y) * 64);
		data->map[player->pos_y][player->pos_x] = '0';
	}
}

void	handle_new_position_r(t_data *data, t_player *player, t_img *img)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->plright_exit,
			player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->player,
			player->pos_x * 64, (player->pos_y) * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}

void	handle_new_position_l(t_data *data, t_player *player, t_img *img)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->pleft_exit,
			player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->player_l,
			player->pos_x * 64, (player->pos_y) * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}

void	handle_new_position_d(t_data *data, t_player *player, t_img *img)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->pdown_exit,
			player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->player_d,
			player->pos_x * 64, (player->pos_y) * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}

void	handle_new_position_t(t_data *data, t_player *player, t_img *img)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj != 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->ptop_exit,
			player->pos_x * 64, player->pos_y * 64);
		data->map[player->pos_y][player->pos_x] = 'S';
	}
	else if (data->map[player->pos_y][player->pos_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->player_t,
			player->pos_x * 64, (player->pos_y) * 64);
		data->map[player->pos_y][player->pos_x] = 'P';
	}
}
