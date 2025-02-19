/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_final_laser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:36:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/19 20:21:45 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_final_laser(t_data *data, t_player *player)
{
	if (player->laser_x == 0 || player->laser_y == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->sprite[OBJECT],
					(player->laser_x) * 64, player->laser_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->sprite[OBJECT],
					(player->laser_x) * 64, (player->laser_y + 1)* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->sprite[OBJECT],
					(player->laser_x) * 64, (player->laser_y - 1 )* 64);
		player->laser_x++;
	}
	if (player->laser_dir == LEFT)
		remove_final_laser_left(data, player);
	else if (player->laser_dir == RIGHT)
		remove_final_laser_right(data, player);
	else if (player->laser_dir == DOWN)
		remove_final_laser_down(data, player);
	else if (player->laser_dir == UP)
		remove_final_laser_up(data, player);
}


void	remove_final_laser_left(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_x != player->pos_x)
	{
		remove_final_laser_line(data, player);
		++player->laser_x;
	}
}

void	remove_final_laser_right(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_x != player->pos_x)
	{
		remove_final_laser_line(data, player);
		--player->laser_x;
	}
}

void	remove_final_laser_down(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_y != player->pos_y)
	{
		remove_final_laser_row(data, player);
		++player->laser_y;
	}
}

void	remove_final_laser_up(t_data *data, t_player *player)
{
	player->final_laser = false;
	while (player->laser_y != player->pos_y)
	{
		remove_final_laser_row(data, player);
		--player->laser_y;
	}
}

void	remove_final_laser_line(t_data *data, t_player *player)
{
	if (player->laser_y > 1 && (size_t)(player->laser_y) < data->nb_row - 2)
	{
		if (data->map[player->laser_y - 1][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_y - 1);
		else if (data->map[player->laser_y - 1][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_y - 1);
		else
			change_display_floor(data, player->laser_x, player->laser_y - 1);
		if (data->map[player->laser_y + 1][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_y + 1);
		else if (data->map[player->laser_y + 1][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_y + 1);
		else
			change_display_floor(data, player->laser_x, player->laser_y + 1);
		if (data->map[player->laser_y][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_y);
		else if (data->map[player->laser_y][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_y);
		else
			change_display_floor(data, player->laser_x, player->laser_y);
	}
	
}

void	remove_final_laser_row(t_data *data, t_player *player)
{
	if (player->laser_x > 1 && (size_t)(player->laser_x) < data->nb_line - 2)
	{
		if (data->map[player->laser_x - 1][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_x - 1);
		else if (data->map[player->laser_x - 1][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_x - 1);
		else
			change_display_floor(data, player->laser_x, player->laser_x - 1);
		if (data->map[player->laser_x + 1][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_x + 1);
		else if (data->map[player->laser_x + 1][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_x + 1);
		else
			change_display_floor(data, player->laser_x, player->laser_x + 1);
		if (data->map[player->laser_x][player->laser_x] == 'E')
			change_display_spaceship(data, player->laser_x, player->laser_x);
		else if (data->map[player->laser_x][player->laser_x] == 'C')
			change_display_object(data, player->laser_x, player->laser_x);
		else
			change_display_floor(data, player->laser_x, player->laser_x);
	}
}

void	change_display_spaceship(t_data *data, int x, int y)
{
	if (data->spaceship->spaceship_close == true)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_CLOSE], x * 64, y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_OPEN], x * 64, y * 64);
	}
}

void	change_display_object(t_data *data, int x, int y)
{
	--data->nb_obj;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], x * 64, y * 64);
}

void	change_display_floor(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->sprite[FLOOR], x * 64, y * 64);
}
