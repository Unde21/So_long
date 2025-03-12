/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:45:48 by samaouch          #+#    #+#             */
/*   Updated: 2025/03/12 13:25:23 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_img(t_data *data, t_img *img)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (img->sprite[i] != NULL)
		{
			mlx_destroy_image(data->mlx_ptr, img->sprite[i]);
			img->sprite[i] = NULL;
		}
		++i;
	}
	i = 0;
	while (i < 10)
	{
		if (data->img->move_spr[i] != NULL)
		{
			mlx_destroy_image(data->mlx_ptr, data->img->move_spr[i]);
			data->img->move_spr[i] = NULL;
		}
		++i;
	}
	destroy_enemy_sprite(data, data->enemy);
	destroy_player_sprite(data, data->player);
	destroy_spaceship_sprite(data, data->spaceship);
}

void	destroy_enemy_sprite(t_data *data, t_enemy *enemy)
{
	int	i;

	i = 0;
	if (data->enemy->is_start_pos == false)
		return ;
	while (i < 31)
	{
		if (enemy->sprite[i] != NULL)
		{
			mlx_destroy_image(data->mlx_ptr, enemy->sprite[i]);
			enemy->sprite[i] = NULL;
		}
		++i;
	}
}

void	destroy_player_sprite(t_data *data, t_player *player)
{
	int	i;

	i = 0;
	while (i < 42)
	{
		if (player->sprite[i] != NULL)
		{
			mlx_destroy_image(data->mlx_ptr, player->sprite[i]);
			player->sprite[i] = NULL;
		}
		++i;
	}
}

void	destroy_spaceship_sprite(t_data *data, t_spaceship *spaceship)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (spaceship->sprite[i] != NULL)
		{
			mlx_destroy_image(data->mlx_ptr, spaceship->sprite[i]);
			spaceship->sprite[i] = NULL;
		}
		++i;
	}
}
