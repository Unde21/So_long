/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:00:01 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/14 10:04:19 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	attack_player(t_data *data, t_player *player)
{
	struct timeval	current_time;
	long			elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - player->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - player->last_time.tv_usec) / 1000;
	if (data->enemy->is_laser_enemy == false && elapsed_time >= FIRE_FRAME)
		{
			data->enemy->s_pos_x = data->enemy->pos_x;
			data->enemy->s_pos_y = data->enemy->pos_y;
			player->laser_x = player->pos_x;
			player->laser_y = player->pos_y;
			player->is_laser_player = true;
			ft_printf("JE SUIS UN TEST\n");
		}
	++player->fire_frame;
	if (player->is_laser_player == true && player->fire_frame >= FIRE_MOVE_FRAME)
	{
		if (player_laser(data, player) == 1)
		{
			ft_printf("MEGA\n");
			player->is_laser_player = false;
			player->laser_dir = 0;
		}
		player->last_time = current_time;
		player->fire_frame = 0;
	}
}

int player_laser(t_data *data, t_player *player)
{
	if ((data->enemy->pos_x > player->laser_x && data->enemy->s_pos_y == player->pos_y && player->laser_dir != LEFT)
	 	|| (player->laser_dir == RIGHT && (size_t)(player->laser_x) < data->nb_row - 2))
		laser_right_player(data, player);
	else if ((data->enemy->pos_x < player->laser_x && data->enemy->s_pos_y == player->pos_y && player->laser_dir != RIGHT)
		|| (player->laser_dir == LEFT && player->laser_x >= 2))
		laser_left_player(data, player);
	else if ((data->enemy->pos_y > player->laser_y && data->enemy->s_pos_x == player->pos_x && player->laser_dir != UP)
		|| (player->laser_dir == DOWN && (size_t)(player->laser_y) < data->nb_line - 2))
		laser_down_player(data, player);
	else if ((data->enemy->pos_y < player->laser_y && data->enemy->s_pos_x == player->pos_x && player->laser_dir != DOWN)
		|| (player->laser_dir == UP && player->laser_y >= 2))
		laser_top_player(data, player);
	else if (player->laser_dir == RIGHT)
	{
		while (player->laser_x != player->pos_x)
		{
			if (data->map[player->laser_y][player->laser_x] == 'L')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->floor, (player->laser_x) * 64,
					player->laser_y * 64);
				data->map[player->laser_y][player->laser_x] = '0';
			}
			else if (data->map[player->laser_y][player->laser_x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->object, (player->laser_x) * 64,
					player->laser_y * 64);
			}
			else if (data->map[player->laser_y][player->laser_x] == 'E')
			{
				if (data->spaceship->spaceship_close == true)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_close, (player->laser_x) * 64,
					player->laser_y * 64);
				}
				else
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_open, (player->laser_x) * 64,
					player->laser_y * 64);
				}
			}
			--player->laser_x;
		}
		return (1);
	}
	else if (player->laser_dir == LEFT)
	{
		while (player->laser_x != player->pos_x)
		{
			if (data->map[player->laser_y][player->laser_x] == 'L')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->floor, (player->laser_x) * 64,
					player->laser_y * 64);
				data->map[player->laser_y][player->laser_x] = '0';
			}
			else if (data->map[player->laser_y][player->laser_x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->object, (player->laser_x) * 64,
					player->laser_y * 64);
			}
			else if (data->map[player->laser_y][player->laser_x] == 'E')
			{
				if (data->spaceship->spaceship_close == true)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_close, (player->laser_x) * 64,
					player->laser_y * 64);
				}
				else
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_open, (player->laser_x) * 64,
					player->laser_y * 64);
				}
			}
			++player->laser_x;
		}
		return (1);
	}
	else if (player->laser_dir == DOWN)
	{
		while (player->laser_y != player->pos_y)
		{
			
			if (data->map[player->laser_y][player->laser_x] == 'L')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->floor, (player->laser_x) * 64,
					player->laser_y * 64);
				data->map[player->laser_y][player->laser_x] = '0';
			}
			else if (data->map[player->laser_y][player->laser_x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->object, (player->laser_x) * 64,
					player->laser_y * 64);
			}
			else if (data->map[player->laser_y][player->laser_x] == 'E')
			{
				if (data->spaceship->spaceship_close == true)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_close, (player->laser_x) * 64,
					player->laser_y * 64);
				}
				else
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_open, (player->laser_x) * 64,
					player->laser_y * 64);
				}
			}
			--player->laser_y;
		}
		return (1);
	}
	else if (player->laser_dir == UP)
	{
		while (player->laser_y != player->pos_y)
		{
			
			if (data->map[player->laser_y][player->laser_x] == 'L')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->floor, (player->laser_x) * 64,
					player->laser_y * 64);
				data->map[player->laser_y][player->laser_x] = '0';
			}
			else if (data->map[player->laser_y][player->laser_x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->object, (player->laser_x) * 64,
					player->laser_y * 64);
			}
			else if (data->map[player->laser_y][player->laser_x] == 'E')
			{
				if (data->spaceship->spaceship_close == true)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_close, (player->laser_x) * 64,
					player->laser_y * 64);
				}
				else
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_open, (player->laser_x) * 64,
					player->laser_y * 64);
				}
			}
			++player->laser_y;
		}
		return (1);
	}
	else
		return (1);
	return (0);
}

void	laser_left_player(t_data *data, t_player *player)
{
	player->laser_dir = LEFT;
	if (data->map[player->laser_y][player->laser_x - 1] != 'B'
		&& player->laser_x >= 2)
	{
		if (player->laser_x == player->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->use_laser_l, (player->laser_x) * 64,
				(player->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->laser_start_l, (player->laser_x - 1) * 64,
				(player->laser_y) * 64);
			// ft_printf("test1\n");
		}
		else if (player->laser_x == 2)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, (player->laser_x - 1) * 64,
			(player->laser_y) * 64);
			// ft_printf("test2\n");

		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_line, (player->laser_x - 1) * 64,
			player->laser_y * 64);
			// ft_printf("test3\n");

		}
		--player->laser_x;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	// else if (data->map[player->laser_y][player->laser_x - 1] == 'P')
	// {
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 		data->img->explosion, (player->laser_x - 1) * 64,
	// 		(player->laser_y) * 64);
	// 	// data->player->death = true;
	// }
	// ft_printf("left\n");
}

void	laser_right_player(t_data *data, t_player *player)
{
	player->laser_dir = RIGHT;
	if (data->map[player->laser_y][player->laser_x + 1] != 'B'
		&& (size_t)(player->laser_x) < data->nb_row - 2)
	{
		if (player->laser_x == player->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->use_laser_r, (player->laser_x) * 64,
				(player->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->laser_start_r, (player->laser_x + 1) * 64,
				(player->laser_y) * 64);
		}
		else if ((size_t)(player->laser_x) == data->nb_row - 3)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_line, (player->laser_x + 1) * 64,
			player->laser_y * 64);	
		}
		++player->laser_x;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	else if (data->map[player->laser_y][player->laser_x + 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (player->laser_x + 1) * 64,
			(player->laser_y) * 64);
		// data->player->death = true;
	}
	ft_printf("right\n");
}

void	laser_down_player(t_data *data, t_player *player)
{
	player->laser_dir = DOWN;
	if (data->map[player->laser_y + 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) < data->nb_line - 2)
	{
		if (player->laser_y == player->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->use_laser_d, (player->laser_x) * 64,
				(player->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->laser_start_d, (player->laser_x) * 64,
				(player->laser_y + 1) * 64);
		}
		else if ((size_t)(player->laser_y) == data->nb_line - 3)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64,
			(player->laser_y + 1) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_row, player->laser_x * 64,
			(player->laser_y + 1) * 64);
		}
		++player->laser_y;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	else if (data->map[player->laser_y + 1][player->laser_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64,
			(player->laser_y + 1) * 64);
		data->player->death = true;
	}
}

void	laser_top_player(t_data *data, t_player *player)
{
		player->laser_dir = UP;
	if (data->map[player->laser_y - 1][player->laser_x] != 'B'
		&& (size_t)(player->laser_y) >= 2)
	{
		if (player->laser_y == player->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->use_laser_d, (player->laser_x) * 64,
				(player->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->enemy->laser_start_d, (player->laser_x) * 64,
				(player->laser_y - 1) * 64);
		}
		else if (player->laser_y == 2)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64,
			(player->laser_y - 1) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->enemy->laser_row, player->laser_x * 64,
			(player->laser_y - 1) * 64);
		}
		--player->laser_y;
		if (data->map[player->laser_y][player->laser_x] == '1'
			|| data->map[player->laser_y][player->laser_x] == '0')
			data->map[player->laser_y][player->laser_x] = 'L';
	}
	else if (data->map[player->laser_y - 1][player->laser_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, player->laser_x * 64,
			(player->laser_y - 1) * 64);
		data->player->death = true;
	}
}
