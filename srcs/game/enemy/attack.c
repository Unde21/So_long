/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:47:48 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/14 09:25:13 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_laser(t_data *data, t_enemy *enemy)
{
	 if ((data->player->pos_x > enemy->laser_x && data->player->s_pos_y == enemy->pos_y && enemy->laser_dir != LEFT)
	 	|| (enemy->laser_dir == RIGHT && (size_t)(enemy->laser_x) < data->nb_row - 2))
		laser_right(data, enemy);
	else if ((data->player->pos_x < enemy->laser_x && data->player->s_pos_y == enemy->pos_y && enemy->laser_dir != RIGHT)
		|| (enemy->laser_dir == LEFT && enemy->laser_x >= 2))
		laser_left(data, enemy);
	else if ((data->player->pos_y > enemy->laser_y && data->player->s_pos_x == enemy->pos_x && enemy->laser_dir != UP)
		|| (enemy->laser_dir == DOWN && (size_t)(enemy->laser_y) < data->nb_line - 2))
		laser_down(data, enemy);
	else if ((data->player->pos_y < enemy->laser_y && data->player->s_pos_x == enemy->pos_x && enemy->laser_dir != DOWN)
		|| (enemy->laser_dir == UP && enemy->laser_y >= 2))
		laser_top(data, enemy);
	else if (enemy->laser_dir == RIGHT)
	{
		while (enemy->laser_x != enemy->pos_x)
		{
			if (data->map[enemy->laser_y][enemy->laser_x] == 'L')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->floor, (enemy->laser_x) * 64,
					enemy->laser_y * 64);
				data->map[enemy->laser_y][enemy->laser_x] = '0';
			}
			else if (data->map[enemy->laser_y][enemy->laser_x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->object, (enemy->laser_x) * 64,
					enemy->laser_y * 64);
			}
			else if (data->map[enemy->laser_y][enemy->laser_x] == 'E')
			{
				if (data->spaceship->spaceship_close == true)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_close, (enemy->laser_x) * 64,
					enemy->laser_y * 64);
				}
				else
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->spaceship_open, (enemy->laser_x) * 64,
					enemy->laser_y * 64);
				}
			}
			--enemy->laser_x;
		}
		return (1);
	}
	else if (enemy->laser_dir == LEFT)
	{
		while (enemy->laser_x != enemy->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, (enemy->laser_x) * 64,
			enemy->laser_y * 64);
			++enemy->laser_x;
		}
		return (1);
	}
	else if (enemy->laser_dir == DOWN)
	{
		while (enemy->laser_y != enemy->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, enemy->laser_x * 64,
			enemy->laser_y * 64);
			--enemy->laser_y;
		}
		return (1);
	}
	else if (enemy->laser_dir == UP)
	{
		while (enemy->laser_y != enemy->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->floor, enemy->laser_x * 64,
			enemy->laser_y * 64);
			++enemy->laser_y;
		}
		return (1);
	}
	else
		return (1);
	return (0);
}

void	display_attack_enemy(t_data *data, t_enemy *enemy)
{
	if (data->enemy->moved == RIGHT || data->player->pos_x == enemy->pos_x + 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->attack_r, enemy->pos_x * 64,
			enemy->pos_y * 64);
	}
	else if (data->enemy->moved == LEFT || data->player->pos_x == enemy->pos_x - 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->attack_l, enemy->pos_x * 64,
			enemy->pos_y * 64);
	}
	else if (data->enemy->moved == UP || data->player->pos_y == enemy->pos_y - 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->attack_t, enemy->pos_x * 64,
			enemy->pos_y * 64);
	}
	else if (data->enemy->moved == DOWN || data->player->pos_y == enemy->pos_y + 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->attack_d, enemy->pos_x * 64,
			enemy->pos_y * 64);
	}
}

void	laser_left(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = LEFT;
	if (data->map[enemy->laser_y][enemy->laser_x - 1] != 'P'
		&& enemy->laser_x >= 2
		&& data->map[enemy->laser_y][enemy->laser_x - 1] != 'E')
	{
		if (enemy->laser_x == enemy->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->use_laser_l, (enemy->laser_x) * 64,
				(enemy->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->laser_start_l, (enemy->laser_x - 1) * 64,
				(enemy->laser_y) * 64);
		}
		else if (enemy->laser_x == 2)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, (enemy->laser_x - 1) * 64,
			(enemy->laser_y) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->laser_line, (enemy->laser_x - 1) * 64,
			enemy->laser_y * 64);	
		}
		--enemy->laser_x;
		// if (data->map[enemy->laser_y][enemy->laser_x] == '0')
		// 	data->map[enemy->laser_y][enemy->laser_x] = 'L';
	}
	else if (data->map[enemy->laser_y][enemy->laser_x - 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion, (enemy->laser_x - 1) * 64,
			(enemy->laser_y) * 64);
		data->player->death = true;
	}
}

void	laser_right(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = RIGHT;
	if (data->map[enemy->laser_y][enemy->laser_x + 1] != 'P'
		&& (size_t)(enemy->laser_x) < data->nb_row - 2)
		// && data->map[enemy->laser_y][enemy->laser_x + 1] != 'E')
	{
		if (enemy->laser_x == enemy->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->use_laser_r, (enemy->laser_x) * 64,
				(enemy->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->laser_start_r, (enemy->laser_x  + 1) * 64,
				(enemy->laser_y) * 64);
		}
		else if ((size_t)(enemy->laser_x) == data->nb_row - 3)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (enemy->laser_x  + 1) * 64,
			(enemy->laser_y) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->laser_line, (enemy->laser_x + 1) * 64,
			enemy->laser_y * 64);	
		}
		++enemy->laser_x;
		if (data->map[enemy->laser_y][enemy->laser_x] == '1'
			|| data->map[enemy->laser_y][enemy->laser_x] == '0')
			data->map[enemy->laser_y][enemy->laser_x] = 'L';
	}
	else if (data->map[enemy->laser_y][enemy->laser_x + 1] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_r, (enemy->laser_x  + 1) * 64,
			(enemy->laser_y) * 64);
		data->player->death = true;
	}
}

void	laser_down(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = DOWN;
	if (data->map[enemy->laser_y + 1][enemy->laser_x] != 'P'
		&& (size_t)(enemy->laser_y) < data->nb_line - 2
		&& data->map[enemy->laser_y + 1][enemy->laser_x] != 'E')
	{
		if (enemy->laser_y == enemy->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->use_laser_d, (enemy->laser_x) * 64,
				(enemy->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->laser_start_d, (enemy->laser_x) * 64,
				(enemy->laser_y + 1) * 64);
		}
		else if ((size_t)(enemy->laser_y) == data->nb_line - 3)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->laser_row, enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
		}
		++enemy->laser_y;
		// if (data->map[enemy->laser_y][enemy->laser_x] == '0')
		// 	data->map[enemy->laser_y][enemy->laser_x] = 'L';
	}
	else if (data->map[enemy->laser_y + 1][enemy->laser_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_d, enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
		data->player->death = true;
	}
}

void	laser_top(t_data *data, t_enemy *enemy)
{
	enemy->laser_dir = UP;
	if (data->map[enemy->laser_y - 1][enemy->laser_x] != 'P'
		&& enemy->laser_y >= 2
		&& data->map[enemy->laser_y + 1][enemy->laser_x] != 'E')
	{
		if (enemy->laser_y == enemy->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->use_laser_t, (enemy->laser_x) * 64,
				(enemy->laser_y) * 64);	
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				enemy->laser_start_t, (enemy->laser_x) * 64,
				(enemy->laser_y - 1) * 64);
		}
		else if (enemy->laser_y == 2)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_t, enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->laser_row, enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
		}
		--enemy->laser_y;
		// if (data->map[enemy->laser_y][enemy->laser_x] == '0')
		// 	data->map[enemy->laser_y][enemy->laser_x] = 'L';
	}
	else if (data->map[enemy->laser_y - 1][enemy->laser_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->explosion_t, enemy->laser_x * 64,
			(enemy->laser_y - 1) * 64);
		data->player->death = true;
	}
}
