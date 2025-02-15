/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_laser_dir_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:32:56 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/15 11:37:37 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	laser_down_player(t_data *data, t_player *player)
{	
	player->laser_dir = DOWN;
	if (data->map[player->laser_y + 1][player->laser_x] == 'L')
	{
		// player->is_laser_player = false;
		player->is_fighting_laser = true;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
            data->img->exit_fire, (player->laser_x) * 64, (player->laser_y + 1) * 64);
		// data->enemy->is_laser_enemy = false;
		data->enemy->is_laser_enemy = false;
		// ft_printf("map:%s\n", data->map[player->laser_y]);

		return ;
	}
	else if (data->map[player->laser_y + 1][player->laser_x] == 'B')
	{
		//BUG y a 3 rayon qui parte sur l axe vertical 
		ft_printf("il est touche");
		//TODO transformation quand on le tue (il y a 2 rayon qui parte je sais pas pourquoi, mais le 2eme faudrait qu il soit modifie si cell meurt)
		--data->enemy->life;
		if (data->enemy->life == 0)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
            data->img->explosion_r, (player->laser_x) * 64, (player->laser_y + 1) * 64);
			// data->enemy->is_alive = false;
			data->map[player->laser_y + 1][player->laser_x] = '0';
			data->enemy->pos_x = player->laser_x;
			data->enemy->pos_y = player->laser_y + 1;
		}
		else
		{
			//TODO trouver un moyen de "stun l enemy avec cette image"
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
            data->enemy->destroy_wall, (player->laser_x) * 64, (player->laser_y + 1) * 64);
		}
		remove_player_laser_down(data, player);
		data->player->is_laser_player = false;
		// player->fire_frame = 0;
	}
	else if (data->map[player->laser_y + 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) < data->nb_line - 2)
	{
		handle_laser_down(data, player);
		++player->laser_y;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	// else if (data->map[player->laser_y + 1][player->laser_x] == 'P')
	// {
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 		data->img->explosion_d, player->laser_x * 64, (player->laser_y + 1)
	// 		* 64);
	// 	data->player->death = true;
	// }
}

void	handle_laser_down(t_data *data, t_player *player)
{
	if (player->laser_y == player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->use_laser_d, (player->laser_x) * 64, (player->laser_y)
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_start_d, (player->laser_x) * 64, (player->laser_y
				+ 1) * 64);
	}
	else if ((size_t)(player->laser_y) == data->nb_line - 3)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64, (player->laser_y + 1)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_row, player->laser_x * 64, (player->laser_y + 1)
			* 64);
	}
}

void	laser_top_player(t_data *data, t_player *player)
{
	ft_printf("top\n");
	player->laser_dir = UP;
	// ft_printf("map:%s\n", data->map[player->laser_y]);
	if (data->map[player->laser_y - 1][player->laser_x] == 'L')
	{
		// player->is_laser_player = false;
		player->is_fighting_laser = true;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
            data->img->exit_fire, (player->laser_x) * 64, (player->laser_y - 1) * 64);
		// data->enemy->is_laser_enemy = false;
		data->enemy->is_laser_enemy = false;


		return ;
	}
	else if (data->map[player->laser_y - 1][player->laser_x] == 'B')
	{
		ft_printf("il est touche");
		//TODO transformation quand on le tue (il y a 2 rayon qui parte je sais pas pourquoi, mais le 2eme faudrait qu il soit modifie si cell meurt)
		--data->enemy->life;
		if (data->enemy->life == 0)
			data->enemy->is_alive = false;
		data->map[player->laser_y - 1][player->laser_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
            data->img->explosion_r, (player->laser_x) * 64, (player->laser_y - 1) * 64);
		remove_player_laser_up(data, player);
	}
	else if (data->map[player->laser_y - 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) >= 2)
	{
		handle_laser_top(data, player);
		--player->laser_y;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	// else if (data->map[player->laser_y - 1][player->laser_x] == 'P')
	// {
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 		data->img->explosion_d, player->laser_x * 64, (player->laser_y - 1)
	// 		* 64);
	// 	data->player->death = true;
	// }
}

void	handle_laser_top(t_data *data, t_player *player)
{
	if (player->laser_y == player->pos_y)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->use_laser_d, (player->laser_x) * 64, (player->laser_y)
			* 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_start_d, (player->laser_x) * 64, (player->laser_y
				- 1) * 64);
	}
	else if (player->laser_y == 2)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64, (player->laser_y - 1)
			* 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_row, player->laser_x * 64, (player->laser_y - 1)
			* 64);
	}
}
