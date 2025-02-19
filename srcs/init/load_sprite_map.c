/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:38:47 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 00:02:34 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_img_map(t_data *data, t_img *img)
{
// 	img->sprite[FLOOR] = mlx_xpm_file_to_image(data->mlx_ptr, img->img[FLOOR],
// 			&img->width, &img->height);
// 	if (!img->sprite[FLOOR])
// 		return (ERR_IMG);
// 	img->sprite[WALL] = mlx_xpm_file_to_image(data->mlx_ptr, img->img[WALL],
// 			&img->width, &img->height);
// 	if (!img->sprite[WALL])
// 		return (ERR_IMG);
// 	img->sprite[OBJECT] = mlx_xpm_file_to_image(data->mlx_ptr, img->img[OBJECT],
// 			&img->width, &img->height);
// 	if (!img->sprite[OBJECT])
// 		return (ERR_IMG);
// 	img->sprite[DESTROY_FLOOR] = mlx_xpm_file_to_image(data->mlx_ptr, img->img[DESTROY_FLOOR],
// 			&img->width, &img->height);
// 	if (!img->sprite[DESTROY_FLOOR])
// 		return (ERR_IMG);
// 	if (load_img_exit(data, data->spaceship) != 0
// 		|| load_img_animation(data, img) != 0)
// 		return (-1);
// 	if (load_img_player(data, data->player) != 0)
// 		return (-1);
// 	if (data->enemy->is_start_pos == true)
// 	{
// 		if (load_img_enemy(data, data->enemy) != 0)
// 			return (-1);
// 	}
// 	return (0);

	int	i;

	i = 0;
	while (i < 10)
	{
		img->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, img->img[i], &img->width, &img->height);
		if (!img->sprite[i])
			return (ERR_IMG);
		++i;
	}
	i = 0;
	while (i < 10)
	{
		img->move_spr[i] = mlx_xpm_file_to_image(data->mlx_ptr, img->move[i], &img->width, &img->height);
		if (!img->move_spr[i])
			return (ERR_IMG);
		++i;
	}
	if (load_img_exit(data, data->spaceship) != 0)
		return (-1);
	if (load_img_player(data, data->player) != 0)
		return (-1);
	if (data->enemy->is_start_pos == true)
	{
		if (load_img_enemy(data, data->enemy) != 0)
			return (-1);
	}
	return (0);
}

int	load_img_exit(t_data *data, t_spaceship *spaceship)
{
// 	spaceship->sprite[EXIT_FIRE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			spaceship->img[EXIT_FIRE], &data->img->width, &data->img->height);
// 	if (!spaceship->sprite[EXIT_FIRE])
// 		return (ERR_IMG);
// 	spaceship->sprite[TRAIL_FIRE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			spaceship->img[TRAIL_FIRE], &data->img->width, &data->img->height);
// 	if (!spaceship->sprite[TRAIL_FIRE])
// 		return (ERR_IMG);
// 	spaceship->sprite[LANDING_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			spaceship->img[LANDING_EXIT], &data->img->width,
// 			&data->img->height);
// 	if (!spaceship->sprite[LANDING_EXIT])
// 		return (ERR_IMG);
// 	spaceship->sprite[EXIT_CLOSE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			spaceship->img[EXIT_CLOSE], &data->img->width, &data->img->height);
// 	if (!spaceship->sprite[EXIT_CLOSE])
// 		return (ERR_IMG);
// 	spaceship->sprite[EXIT_OPEN] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			spaceship->img[EXIT_OPEN], &data->img->width, &data->img->height);
// 	if (!spaceship->sprite[EXIT_OPEN])
// 		return (ERR_IMG);
// 	return (0);
	int	i;

	i = 0;
	while (i < 4)
	{
		//  if (!spaceship->img[i])
        //     return (ERR_IMG);
		spaceship->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, spaceship->img[i], &data->img->width, &data->img->height);
		if (!spaceship->sprite[i])
			return (ERR_IMG);
		++i;
	}
	return (0);
}

// int	load_img_animation(t_data *data, t_img *img)
// {
// 	img->sprite[EXPLOSION_L] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->img[EXPLOSION_L], &img->width, &img->height);
// 	if (!img->sprite[EXPLOSION_L])
// 		return (ERR_IMG);
// 	img->sprite[EXPLOSION_R] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->img[EXPLOSION_R], &img->width, &img->height);
// 	if (!img->sprite[EXPLOSION_R])
// 		return (ERR_IMG);
// 	img->sprite[EXPLOSION_D] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->img[EXPLOSION_D], &img->width, &img->height);
// 	if (!img->sprite[EXPLOSION_D])
// 		return (ERR_IMG);
// 	img->sprite[EXPLOSION_T] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->img[EXPLOSION_T], &img->width, &img->height);
// 	if (!img->sprite[EXPLOSION_T])
// 		return (ERR_IMG);
// 	img->sprite[LASER_FIGHT_X] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->img[LASER_FIGHT_X], &img->width, &img->height);
// 	if (!img->sprite[LASER_FIGHT_X])
// 		return (ERR_IMG);
// 	img->sprite[LASER_FIGHT_Y] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->img[LASER_FIGHT_Y], &img->width, &img->height);
// 	if (!img->sprite[LASER_FIGHT_Y])
// 		return (ERR_IMG);
// 	return (0);
// }
