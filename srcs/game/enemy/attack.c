/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:47:48 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/13 11:51:20 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_laser(t_data *data, t_enemy *enemy)
{
	if ((enemy->laser_x + 1 > data->nb_row - 2 && enemy->laser_y + 1 > data->nb_line - 2))
	{
		//enemy->is_laser_enemy = false;
		// data->enemy->laser_frame = 0;
		ft_printf("player x : %d, y: %d laser x:%d y:%d\n", (int)(data->player->s_pos_x), (int)(data->player->s_pos_y), (int)(data->enemy->laser_x), (int)(data->enemy->laser_y));
		return (1);
	}
	if (data->player->s_pos_x > enemy->laser_x)
		laser_right(data, enemy);
	else if (data->player->s_pos_x < enemy->laser_x)
		laser_left(data, enemy);
	else if (data->player->s_pos_y > enemy->laser_y)
		laser_down(data, enemy);
	else
		return (1);
	data->enemy->laser_frame = 0;
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
	if (data->map[enemy->laser_y][enemy->laser_x - 1] != 'P'
		&& enemy->laser_x < data->nb_row - 2
		&& enemy->laser_x < (size_t)(data->player->pos_x)
		&& data->map[enemy->laser_y][enemy->laser_x - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->pl_dead_r, (enemy->laser_x - 1) * 64,
			enemy->laser_y * 64);
		enemy->is_laser_enemy = true;
		++enemy->laser_x;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x - 1] == 'P')
		data->player->death = true;
}

void	laser_right(t_data *data, t_enemy *enemy)
{
	if (data->map[enemy->laser_y][enemy->laser_x + 1] != 'P'
		&& enemy->laser_x < data->nb_row - 2
		&& enemy->laser_x < (size_t)(data->player->pos_x)
		&& data->map[enemy->laser_y][enemy->laser_x + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->pl_dead_r, (enemy->laser_x + 1) * 64,
			enemy->laser_y * 64);
		enemy->is_laser_enemy = true;
		++enemy->laser_x;
	}
	else if (data->map[enemy->laser_y][enemy->laser_x + 1] == 'P')
		data->player->death = true;
}

void	laser_down(t_data *data, t_enemy *enemy)
{
	ft_printf("test\n");
	if (data->map[enemy->laser_y + 1][enemy->laser_x] != 'P'
		&& enemy->laser_y < data->nb_line - 2
		&& enemy->laser_y < (size_t)(data->player->pos_x)
		&& data->map[enemy->laser_y + 1][enemy->laser_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->pl_dead_r, enemy->laser_x * 64,
			(enemy->laser_y + 1) * 64);
		enemy->is_laser_enemy = true;
		++enemy->laser_y;
	}
	else if (data->map[enemy->laser_y + 1][enemy->laser_x] == 'P')
		data->player->death = true;
}
