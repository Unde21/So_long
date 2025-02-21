/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:38:47 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 04:37:48 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	load_img_map(t_data *data, t_img *img)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		img->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, img->img[i],
				&img->width, &img->height);
		if (!img->sprite[i])
			return (ERR_IMG);
		++i;
	}
	i = 0;
	while (i < 10)
	{
		img->move_spr[i] = mlx_xpm_file_to_image(data->mlx_ptr, img->move[i],
				&img->width, &img->height);
		if (!img->move_spr[i])
			return (ERR_IMG);
		++i;
	}
	if (load_img_exit(data, data->spaceship) != 0)
		return (-1);
	return (0);
}

int	load_img_exit(t_data *data, t_spaceship *spaceship)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		spaceship->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr,
				spaceship->img[i], &data->img->width, &data->img->height);
		if (!spaceship->sprite[i])
			return (ERR_IMG);
		++i;
	}
	if (load_img_player(data, data->player) != 0)
		return (-1);
	if (data->enemy->is_start_pos == true)
	{
		if (load_img_enemy(data, data->enemy) != 0)
			return (-1);
	}
	return (0);
}

int	load_img_player(t_data *data, t_player *player)
{
	int	i;

	i = 0;
	while (i < 42)
	{
		player->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, player->img[i],
				&data->img->width, &data->img->height);
		if (!player->sprite[i])
			return (ERR_IMG);
		++i;
	}
	return (0);
}

int	load_img_enemy(t_data *data, t_enemy *enemy)
{
	int	i;

	i = 0;
	while (i < 31)
	{
		enemy->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[i],
				&data->img->width, &data->img->height);
		if (!enemy->sprite[i])
			return (ERR_IMG);
		++i;
	}
	return (0);
}
