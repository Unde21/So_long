/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 20:43:58 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int	move_enemy(t_data *data)
{
	struct timeval current_time;
	long	elapsed_time;
	
	if (data->end == true || data->player->death == true || data->end == true || data->landing == true)
		return (0);
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - data->last_time.tv_sec) * 1000
		+ (current_time.tv_usec - data->last_time.tv_usec) / 1000;  // modifier la division par une multiplication
	if (elapsed_time > 500 && data->enemy->moved == 0)
	{
		// data->enemy->moved = false;
		if (data->player->pos_y < data->enemy->pos_y && data->map[data->enemy->pos_y - 1][data->enemy->pos_x] != '1' && data->enemy->moved == 0)
				move_enemy_top(data, data->enemy);
		else if (data->player->pos_x > data->enemy->pos_x && data->map[data->enemy->pos_y][data->enemy->pos_x + 1] != '1'  && data->enemy->moved == 0)	
				move_enemy_right(data, data->enemy);
		else if (data->player->pos_y > data->enemy->pos_y && data->map[data->enemy->pos_y + 1][data->enemy->pos_x] != '1' && data->enemy->moved == 0)
				move_enemy_down(data, data->enemy);
		else if (data->player->pos_x < data->enemy->pos_x && data->map[data->enemy->pos_y][data->enemy->pos_x - 1] != '1' && data->enemy->moved == 0)
				move_enemy_left(data, data->enemy);
		else
			enemy_destroy_wall(data, data->enemy);
    data->last_time = current_time;
	}
	//TODO change name of Key_right etc ... to Move_RIGHT
	else if (elapsed_time > 200 && data->enemy->moved != 0)
	{
		if (data->enemy->moved == KEY_RIGHT)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			(data->enemy->pos_x + 1) * 64, (data->enemy->pos_y) * 64);
			data->map[data->enemy->pos_y][data->enemy->pos_x + 1] = '0';
			move_enemy_right(data, data->enemy);	
		}
		else if (data->enemy->moved == KEY_LEFT)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			(data->enemy->pos_x - 1)* 64, (data->enemy->pos_y) * 64);
			data->map[data->enemy->pos_y][data->enemy->pos_x - 1] = '0';
			move_enemy_left(data, data->enemy);
		}
		else if (data->enemy->moved == KEY_DOWN)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			data->enemy->pos_x * 64, (data->enemy->pos_y + 1) * 64);
			data->map[data->enemy->pos_y + 1][data->enemy->pos_x] = '0';
			move_enemy_down(data, data->enemy);
		}
		else if (data->enemy->moved == KEY_UP)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			data->enemy->pos_x * 64, (data->enemy->pos_y - 1) * 64);
			data->map[data->enemy->pos_y - 1][data->enemy->pos_x] = '0';
			move_enemy_top(data, data->enemy);
		}
		 data->last_time = current_time;
		 data->enemy->moved = false;
	}
	return (0);
}

//TODO enemy attack change sprit 
void	enemy_destroy_wall(t_data *data, t_enemy *enemy)
{
	if (enemy->pos_y == data->player->pos_y)
	{
		if (enemy->pos_x < data->player->pos_x)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy->attack_r,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
			// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			// (enemy->pos_x + 1) * 64, (enemy->pos_y) * 64);
			// data->map[enemy->pos_y][enemy->pos_x + 1] = '0';
			// move_enemy_right(data, enemy);
			data->enemy->moved = KEY_RIGHT;
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy->attack_l,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
			// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			// (enemy->pos_x - 1)* 64, (enemy->pos_y) * 64);
			// data->map[enemy->pos_y][enemy->pos_x - 1] = '0';
			// move_enemy_left(data, enemy);
			data->enemy->moved = KEY_LEFT;
		}
	}
	else if (enemy->pos_x == data->player->pos_x)
	{
		if (enemy->pos_y < data->player->pos_y)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy->attack_d,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
			// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			// enemy->pos_x * 64, (enemy->pos_y + 1) * 64);
			// data->map[enemy->pos_y + 1][enemy->pos_x] = '0';
			// move_enemy_down(data, enemy);
			data->enemy->moved = KEY_DOWN;
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemy->attack_t,
			enemy->pos_x * 64, (enemy->pos_y) * 64);
			// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->floor,
			// enemy->pos_x * 64, (enemy->pos_y - 1) * 64);
			// data->map[enemy->pos_y - 1][enemy->pos_x] = '0';
			// move_enemy_top(data, enemy);
			data->enemy->moved = KEY_UP;
		}
	}
}

void	move_enemy_top(t_data *data, t_enemy *enemy)
{	
	if (touch_player(data, enemy->pos_x, enemy->pos_y - 1) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->defeat == false)
		--enemy->pos_y;
	handle_new_position_t_enemy(data, enemy);
	// if (data->map[enemy->pos_y][enemy->pos_x] == 'C')
	// {
	// 	ft_printf("test\n");
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->object,
	// 		enemy->pos_x * 64, (enemy->pos_y) * 64);
	// }
	data->enemy->moved = true;
}

void	move_enemy_down(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x, enemy->pos_y + 1) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->defeat == false)
		++enemy->pos_y;
	handle_new_position_d_enemy(data, enemy);
	// if (data->map[enemy->pos_y][enemy->pos_x] == 'C')
	// {
	// 	ft_printf("test\n");
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->object,
	// 		enemy->pos_x * 64, (enemy->pos_y) * 64);
	// }
	data->enemy->moved = true;
}

void	move_enemy_right(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x + 1, enemy->pos_y) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->defeat == false)
		++enemy->pos_x;
	handle_new_position_r_enemy(data, enemy);
	// if (data->map[enemy->pos_y][enemy->pos_x] == 'C')
	// {
	// 	ft_printf("test\n");
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->object,
	// 		(enemy->pos_x) * 64, (enemy->pos_y) * 64);
	// }
	data->enemy->moved = true;
}

void	move_enemy_left(t_data *data, t_enemy *enemy)
{
	if (touch_player(data, enemy->pos_x - 1, enemy->pos_y) != 0)
		return ;
	handle_old_position_enemy(data, enemy);
	if (data->end == false)
		--enemy->pos_x;
	handle_new_position_l_enemy(data, enemy);
	// if (data->map[enemy->pos_y][enemy->pos_x] == 'C')
	// {
	// 	ft_printf("test\n");
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->object,
	// 		(enemy->pos_x) * 64, (enemy->pos_y) * 64);
	// }
	data->enemy->moved = true;
}
