/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 03:51:24 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/13 16:39:23 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->img_top != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_top);
		enemy->img_top = NULL;
	}
	if (enemy->img_down != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_down);
		enemy->img_down = NULL;
	}
	if (enemy->img_left != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_left);
		enemy->img_left = NULL;
	}
	if (enemy->img_right != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_right);
		enemy->img_right = NULL;
	}
	ft_destroy_img_death(data);
	ft_destroy_img_enemy_exit(data, enemy);
	ft_destroy_img_enemy_opexit(data, enemy);
	ft_destroy_img_attack_enemy(data, enemy);
}

void	ft_destroy_img_enemy_exit(t_data *data, t_enemy *enemy)
{
	if (enemy->img_t_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_t_exit);
		enemy->img_t_exit = NULL;
	}
	if (enemy->img_d_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_d_exit);
		enemy->img_d_exit = NULL;
	}
	if (enemy->img_l_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_l_exit);
		enemy->img_l_exit = NULL;
	}
	if (enemy->img_r_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_r_exit);
		enemy->img_r_exit = NULL;
	}
}

void	ft_destroy_img_enemy_opexit(t_data *data, t_enemy *enemy)
{
	if (enemy->img_t_opexit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_t_opexit);
		enemy->img_t_opexit = NULL;
	}
	if (enemy->img_d_opexit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_d_opexit);
		enemy->img_d_opexit = NULL;
	}
	if (enemy->img_l_opexit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_l_opexit);
		enemy->img_l_opexit = NULL;
	}
	if (enemy->img_r_opexit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_r_opexit);
		enemy->img_r_opexit = NULL;
	}
	if (data->img->exit_fire != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->exit_fire);
		data->img->exit_fire = NULL;
	}
}

void	ft_destroy_img_death(t_data *data)
{
	if (data->player->pl_dead_l != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->pl_dead_l);
		data->player->pl_dead_l = NULL;
	}
	if (data->player->pl_dead_r != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->pl_dead_r);
		data->player->pl_dead_r = NULL;
	}
	if (data->player->pl_dead_l_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->pl_dead_l_exit);
		data->player->pl_dead_l_exit = NULL;
	}
	if (data->player->pl_dead_r_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->pl_dead_r_exit);
		data->player->pl_dead_r_exit = NULL;
	}
	if (data->img->trail_fire != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->trail_fire);
		data->img->trail_fire = NULL;
	}
}

void	ft_destroy_img_attack_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->attack_t != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->attack_t);
		enemy->attack_t = NULL;
	}
	if (enemy->attack_d != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->attack_d);
		enemy->attack_d = NULL;
	}
	if (enemy->attack_l != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->attack_l);
		enemy->attack_l = NULL;
	}
	if (enemy->attack_r != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->attack_r);
		enemy->attack_r = NULL;
	}
	if (data->img->explosion != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->explosion);
		data->img->explosion = NULL;
	}
}
