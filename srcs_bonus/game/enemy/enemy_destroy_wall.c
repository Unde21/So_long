/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_destroy_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:18:32 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:03:58 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_destroy_wall(t_data *data, t_enemy *enemy)
{
	if (enemy->pos_y == data->player->pos_y && enemy->is_laser_enemy == false)
		destroy_wall_line(data, enemy);
	else if (enemy->pos_x == data->player->pos_x)
		destroy_wall_row(data, enemy);
	else
		display_floor(data, data->img);
	if (data->spaceship->spaceship_close == false)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_OPEN], data->spaceship->pos_x * 64,
			data->spaceship->pos_y * 64);
		data->map[data->spaceship->pos_y][data->spaceship->pos_x] = 'E';
	}
	else if (data->spaceship->spaceship_close == true)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->spaceship->sprite[EXIT_CLOSE], data->spaceship->pos_x * 64,
			data->spaceship->pos_y * 64);
		data->map[data->spaceship->pos_y][data->spaceship->pos_x] = 'E';
	}
}

void	destroy_wall_line(t_data *data, t_enemy *enemy)
{
	if (enemy->pos_x < data->player->pos_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[ATT_R], enemy->pos_x * 64, enemy->pos_y * 64);
		data->enemy->moved = RIGHT;
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[ATT_L], enemy->pos_x * 64, enemy->pos_y * 64);
		data->enemy->moved = LEFT;
	}
}

void	destroy_wall_row(t_data *data, t_enemy *enemy)
{
	if (enemy->pos_y < data->player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[ATT_D], enemy->pos_x * 64, enemy->pos_y * 64);
		data->enemy->moved = DOWN;
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->sprite[ATT_T], enemy->pos_x * 64, enemy->pos_y * 64);
		data->enemy->moved = UP;
	}
}

void	display_floor(t_data *data, t_img *img)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->enemy->sprite[SHIELD], data->enemy->pos_x * 64,
		data->enemy->pos_y * 64);
	if (data->map[data->enemy->pos_y - 1][data->enemy->pos_x] == 'C')
		--data->nb_obj;
	data->map[data->enemy->pos_y - 1][data->enemy->pos_x] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->sprite[FLOOR],
		data->enemy->pos_x * 64, (data->enemy->pos_y - 1) * 64);
	if (data->map[data->enemy->pos_y + 1][data->enemy->pos_x] == 'C')
		--data->nb_obj;
	data->map[data->enemy->pos_y + 1][data->enemy->pos_x] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->sprite[FLOOR],
		data->enemy->pos_x * 64, (data->enemy->pos_y + 1) * 64);
	if (data->map[data->enemy->pos_y][data->enemy->pos_x + 1] == 'C')
		--data->nb_obj;
	data->map[data->enemy->pos_y][data->enemy->pos_x + 1] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->sprite[FLOOR],
		(data->enemy->pos_x - 1) * 64, data->enemy->pos_y * 64);
	if (data->map[data->enemy->pos_y][data->enemy->pos_x + 1] == 'C')
		--data->nb_obj;
	data->map[data->enemy->pos_y][data->enemy->pos_x + 1] = '0';
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->sprite[FLOOR],
		(data->enemy->pos_x - 1) * 64, data->enemy->pos_y * 64);
}
