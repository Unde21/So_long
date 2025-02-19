/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:09:58 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 00:35:34 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_img_enemy(t_data *data, t_enemy *enemy)
{
	// enemy->sprite[ENEMY_R] = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		enemy->img[ENEMY_R], &enemy->width, &enemy->height);
	// if (!enemy->sprite[ENEMY_R])
	// 	return (ERR_IMG);
	// enemy->sprite[ENEMY_L] = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		enemy->img[ENEMY_L], &enemy->width, &enemy->height);
	// if (!enemy->sprite[ENEMY_L])
	// 	return (ERR_IMG);
	// enemy->sprite[ENEMY_T] = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		enemy->img[ENEMY_T], &enemy->width, &enemy->height);
	// if (!enemy->sprite[ENEMY_T])
	// 	return (ERR_IMG);
	// enemy->sprite[ENEMY_D] = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		enemy->img[ENEMY_D], &enemy->width, &enemy->height);
	// if (!enemy->sprite[ENEMY_D])
	// 	return (ERR_IMG);
	// if (load_img_enemy_exit(data, enemy) != 0 || load_img_enemy_laser(data,
	// 		enemy) != 0 || load_img_start_laser_enemy(data, enemy) != 0
	// 	|| load_img_enemy_exit_open(data, enemy) || load_img_attack_enemy(data,
	// 		enemy) != 0)
	// 	return (-1);
		int	i;

	i = 0;
	while (i < 29)
	{
	enemy->sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[i], &data->img->width, &data->img->height);
		if (!enemy->sprite[i])
			return (ERR_IMG);
		++i;
	}
	return (0);
	return (0);
}

// int	load_img_enemy_exit(t_data *data, t_enemy *enemy)
// {
// 	enemy->sprite[ENEM_EXIT_R] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_EXIT_R], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_EXIT_R])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEM_EXIT_L] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_EXIT_L], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_EXIT_L])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEM_EXIT_T] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_EXIT_T], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_EXIT_T])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEM_EXIT_D] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_EXIT_D], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_EXIT_D])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEM_OEXIT_R] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_OEXIT_R], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_OEXIT_R])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEM_OEXIT_L] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_OEXIT_L], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_OEXIT_L])
// 		return (ERR_IMG);
// 	return (0);
// }

// int	load_img_enemy_exit_open(t_data *data, t_enemy *enemy)
// {
// 	enemy->sprite[ENEM_OEXIT_D] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_OEXIT_D], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_OEXIT_D])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEM_OEXIT_T] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEM_OEXIT_T], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEM_OEXIT_T])
// 		return (ERR_IMG);
// 	return (0);
// }

// int	load_img_attack_enemy(t_data *data, t_enemy *enemy)
// {
// 	enemy->sprite[ATT_D] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ATT_D], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ATT_D])
// 		return (ERR_IMG);
// 	enemy->sprite[ATT_L] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ATT_L], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ATT_L])
// 		return (ERR_IMG);
// 	enemy->sprite[ATT_R] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ATT_R], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ATT_R])
// 		return (ERR_IMG);
// 	enemy->sprite[ATT_T] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ATT_T], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ATT_T])
// 		return (ERR_IMG);
// 	enemy->sprite[SHIELD] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[SHIELD], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[SHIELD])
// 		return (ERR_IMG);
// 	enemy->sprite[ENEMY_DEATH] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			enemy->img[ENEMY_DEATH], &enemy->width, &enemy->height);
// 	if (!enemy->sprite[ENEMY_DEATH])
// 		return (ERR_IMG);
// 	return (0);
// }
