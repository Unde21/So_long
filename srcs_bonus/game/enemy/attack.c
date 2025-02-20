/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:47:48 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:03:52 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_laser(t_data *data, t_enemy *enemy)
{
	if ((data->player->pos_x > enemy->laser_x
			&& data->player->s_pos_y == enemy->pos_y
			&& enemy->laser_dir != LEFT) || (enemy->laser_dir == RIGHT
			&& (size_t)(enemy->laser_x) < data->nb_row - 2))
		laser_right(data, enemy);
	else if ((data->player->pos_x < enemy->laser_x
			&& data->player->s_pos_y == enemy->pos_y
			&& enemy->laser_dir != RIGHT) || (enemy->laser_dir == LEFT
			&& enemy->laser_x >= 2))
		laser_left(data, enemy);
	else if ((data->player->pos_y > enemy->laser_y
			&& data->player->s_pos_x == enemy->pos_x && enemy->laser_dir != UP)
		|| (enemy->laser_dir == DOWN
			&& (size_t)(enemy->laser_y) < data->nb_line - 2))
		laser_down(data, enemy);
	else if ((data->player->pos_y < enemy->laser_y
			&& data->player->s_pos_x == enemy->pos_x
			&& enemy->laser_dir != DOWN) || (enemy->laser_dir == UP
			&& enemy->laser_y >= 2))
		laser_top(data, enemy);
	else if (is_needed_remove(data, enemy))
		return (1);
	return (0);
}

int	is_needed_remove(t_data *data, t_enemy *enemy)
{
	if (enemy->laser_dir == RIGHT)
		return (remove_basic_laser_right(data, enemy));
	else if (enemy->laser_dir == LEFT)
		return (remove_basic_laser_left(data, enemy));
	else if (enemy->laser_dir == DOWN)
		return (remove_basic_laser_down(data, enemy));
	else if (enemy->laser_dir == UP)
		return (remove_basic_laser_top(data, enemy));
	else
		return (1);
	return (0);
}

void	display_attack_enemy(t_data *data, t_enemy *enemy)
{
	if (data->enemy->moved == RIGHT || data->player->pos_x == enemy->pos_x + 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ATT_R], enemy->pos_x * 64, enemy->pos_y * 64);
	}
	else if (data->enemy->moved == LEFT
		|| data->player->pos_x == enemy->pos_x - 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ATT_L], enemy->pos_x * 64, enemy->pos_y * 64);
	}
	else if (data->enemy->moved == UP
		|| data->player->pos_y == enemy->pos_y - 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ATT_T], enemy->pos_x * 64, enemy->pos_y * 64);
	}
	else if (data->enemy->moved == DOWN
		|| data->player->pos_y == enemy->pos_y + 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			enemy->sprite[ATT_D], enemy->pos_x * 64, enemy->pos_y * 64);
	}
}
