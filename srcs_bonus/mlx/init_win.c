/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:18:02 by samaouch          #+#    #+#             */
/*   Updated: 2025/03/12 13:20:39 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

int	init_mlx(t_data *data)
{
	if (init_img(data) != 0 || init_enemy_img(data) != 0)
		return (-1);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (-1);
	if (load_img_map(data, data->img) != 0)
		return (-1);
	mlx_get_screen_size(data->mlx_ptr, &data->screen_width,
		&data->screen_height);
	if ((data->screen_height) < ((int)data->nb_line + 2) * 64
		|| (data->screen_width) < (int)data->nb_row * 64)
		return (exit_error_parse(ERR_SIZE_MAP));
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->nb_row) * 64,
			(data->nb_line + 1) * 64, "SUPER KAMEHAMEHA");
	if (!data->win_ptr)
		return (-1);
	if (game_loop(data) != 0)
		return (-1);
	return (0);
}

int	game_loop(t_data *data)
{
	if (display_map(data) != 0)
	{
		ft_destroy_mlx(data);
		return (-1);
	}
	if (data->enemy->is_start_pos == true)
		display_life(data, data->enemy);
	mlx_hook(data->win_ptr, 2, 1L << 0, keypress, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx_ptr, game_update, data);
	if (mlx_loop(data->mlx_ptr) != 0)
		return (-1);
	return (0);
}

void	check_end(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj == 0)
	{
		data->end = true;
		if (player->pos_x == data->enemy->pos_x
			&& player->pos_y == data->enemy->pos_y)
		{
			display_right_sprite_end(data, player);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->spaceship->sprite[EXIT_CLOSE], player->pos_x * 64,
				(player->pos_y) * 64);
		}
	}
}

void	display_right_sprite_end(t_data *data, t_player *player)
{
	if (player->last_move == LEFT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_L_EXIT], player->pos_x * 64,
			(player->pos_y) * 64);
	}
	else if (player->last_move == RIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_R_EXIT], player->pos_x * 64,
			(player->pos_y) * 64);
	}
	else if (player->last_move == UP)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_T_EXIT], player->pos_x * 64,
			(player->pos_y) * 64);
	}
	else if (player->last_move == DOWN)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			player->sprite[PL_D_EXIT], player->pos_x * 64,
			(player->pos_y) * 64);
	}
}

int	close_window(t_data *data)
{
	ft_printf("Game quit\n");
	ft_destroy_mlx(data);
	exit(0);
	return (0);
}
