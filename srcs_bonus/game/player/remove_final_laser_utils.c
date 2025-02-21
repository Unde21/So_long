/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_final_laser_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:32:38 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 02:29:23 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_final_laser_line(t_data *data, t_player *player)
{
	if (player->laser_y > 1 && (size_t)(player->laser_y) < data->nb_row - 2)
	{
		if (data->map[player->laser_y - 1][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_y
				- 1);
		else if (data->map[player->laser_y - 1][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_y - 1);
		else
			change_display_floor(data, player->laser_x, player->laser_y - 1);
		if (data->map[player->laser_y + 1][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_y
				+ 1);
		else if (data->map[player->laser_y + 1][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_y + 1);
		else
			change_display_floor(data, player->laser_x, player->laser_y + 1);
	}
	if (data->map[player->laser_y][player->laser_x] == 'E')
		change_display_spaceship(data, player->laser_x, player->laser_y);
	else if (data->map[player->laser_y][player->laser_x] == 'C')
		change_display_object(data, player->laser_x, player->laser_y);
	else
		change_display_floor(data, player->laser_x, player->laser_y);
}

void	remove_final_laser_row(t_data *data, t_player *player)
{
	if (player->laser_x > 1 && (size_t)(player->laser_x) < data->nb_line - 2)
	{
		if (data->map[player->laser_y][player->laser_x - 1] == 'E')
			change_display_spaceship(data, player->laser_x - 1,
				player->laser_y);
		else if (data->map[player->laser_y][player->laser_x - 1] == 'C')
			change_display_object(data, player->laser_x - 1, player->laser_y);
		else
			change_display_floor(data, player->laser_x - 1, player->laser_y);
		if (data->map[player->laser_y][player->laser_x + 1] == 'E')
			change_display_spaceship(data, player->laser_x + 1,
				player->laser_y);
		else if (data->map[player->laser_y][player->laser_x + 1] == 'C')
			change_display_object(data, player->laser_x + 1, player->laser_y);
		else
			change_display_floor(data, player->laser_x + 1, player->laser_y);
	}
	if (data->map[player->laser_y][player->laser_x] == 'E')
		change_display_spaceship(data, player->laser_x, player->laser_y);
	else if (data->map[player->laser_y][player->laser_x] == 'C')
		change_display_object(data, player->laser_x, player->laser_y);
	else
		change_display_floor(data, player->laser_x, player->laser_y);
}

void	change_display_spaceship(t_data *data, int x, int y)
{
	if (data->spaceship->spaceship_close == true)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_DESTROY], x * 64, y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_OP_DESTR], x * 64, y * 64);
	}
	data->map[y][x] = DEST_EXIT;
}

void	change_display_object(t_data *data, int x, int y)
{
	--data->nb_obj;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->sprite[DESTROY_FLOOR], x * 64, y * 64);
	data->map[y][x] = DEST_FLOOR;
}

void	change_display_floor(t_data *data, int x, int y)
{
	if (x != 0 && y != 0)
		data->map[y][x] = DEST_FLOOR;
	else
		data->map[y][x] = '1';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->sprite[DESTROY_FLOOR], x * 64, y * 64);
}
