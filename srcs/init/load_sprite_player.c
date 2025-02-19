/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:14:35 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/19 06:22:44 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_img_player(t_data *data, t_player *player)
{
	player->sprite[PLAYER_R] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_R], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_R])
		return (ERR_IMG);
	player->sprite[PLAYER_T] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_T], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_T])
		return (ERR_IMG);
	player->sprite[PLAYER_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_L], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_L])
		return (ERR_IMG);
	player->sprite[PLAYER_D] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_D], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_D])
		return (ERR_IMG);
	player->sprite[PL_T_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PL_T_EXIT], &data->img->width, &data->img->height);
	if (!player->sprite[PL_T_EXIT])
		return (ERR_IMG);
	if (load_img_player_death(data, player) != 0 || load_img_player_exit(data,
			player) != 0 || load_img_player_final(data, player) != 0)
		return (-1);
	return (0);
}

int	load_img_player_death(t_data *data, t_player *player)
{
	player->sprite[P_DEATH_R] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player->img[P_DEATH_R], &data->img->width,
			&data->img->height);
	if (!player->sprite[P_DEATH_R])
		return (ERR_IMG);
	player->sprite[P_DEATH_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player->img[P_DEATH_L], &data->img->width,
			&data->img->height);
	if (!player->sprite[P_DEATH_L])
		return (ERR_IMG);
	player->sprite[PL_DEATH_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player->img[PL_DEATH_EXIT], &data->img->width,
			&data->img->height);
	if (!player->sprite[PL_DEATH_EXIT])
		return (ERR_IMG);
	player->sprite[PR_DEATH_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			data->player->img[PR_DEATH_EXIT], &data->img->width,
			&data->img->height);
	if (!player->sprite[PR_DEATH_EXIT])
		return (ERR_IMG);
	player->sprite[PLAYER_LASER_T] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_LASER_T], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_LASER_T])
		return (ERR_IMG);
	return (0);
}

int	load_img_player_exit(t_data *data, t_player *player)
{
	player->sprite[PL_D_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PL_D_EXIT], &data->img->width, &data->img->height);
	if (!player->sprite[PL_D_EXIT])
		return (ERR_IMG);
	player->sprite[PL_R_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PL_R_EXIT], &data->img->width, &data->img->height);
	if (!player->sprite[PL_R_EXIT])
		return (ERR_IMG);
	player->sprite[PL_L_EXIT] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PL_L_EXIT], &data->img->width, &data->img->height);
	if (!player->sprite[PL_L_EXIT])
		return (ERR_IMG);
	player->sprite[PLAYER_LASER_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_LASER_L], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_LASER_L])
		return (ERR_IMG);
	player->sprite[PLAYER_LASER_R] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_LASER_R], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_LASER_R])
		return (ERR_IMG);
	player->sprite[PLAYER_LASER_D] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_LASER_D], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_LASER_D])
		return (ERR_IMG);
	return (0);
}

int	load_img_player_final(t_data *data, t_player *player)
{
	player->sprite[PLAYER_EVO_R] = mlx_xpm_file_to_image(data->mlx_ptr,
		player->img[PLAYER_EVO_R], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_EVO_R])
		return (ERR_IMG);
	player->sprite[PLAYER_EVO_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_EVO_L], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_EVO_L])
		return (ERR_IMG);
	player->sprite[PLAYER_EVO_T] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_EVO_T], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_EVO_T])
		return (ERR_IMG);
	player->sprite[PLAYER_EVO_D] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[PLAYER_EVO_D], &data->img->width, &data->img->height);
	if (!player->sprite[PLAYER_EVO_D])
		return (ERR_IMG);






	player->sprite[FINAL_LINE] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_LINE], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_LINE])
		return (ERR_IMG);
	player->sprite[FINAL_LINE_D] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_LINE_D], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_LINE_D])
		return (ERR_IMG);
	player->sprite[FINAL_LINE_T] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_LINE_T], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_LINE_T])
		return (ERR_IMG);



	player->sprite[FINAL_START_D] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_START_D], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_START_D])
		return (ERR_IMG);
	player->sprite[FINAL_START_T] = mlx_xpm_file_to_image(data->mlx_ptr,
		player->img[FINAL_START_T], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_START_T])
		return (ERR_IMG);



	// player->sprite[FINAL_ROW] = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		player->img[FINAL_STARTR_D], &data->img->width, &data->img->height);
	// if (!player->sprite[FINAL_STARTR_D])
	// 	return (ERR_IMG);
	// player->sprite[FINAL_STARTR_T] = mlx_xpm_file_to_image(data->mlx_ptr,
	// 	player->img[FINAL_STARTR_T], &data->img->width, &data->img->height);
	// if (!player->sprite[FINAL_STARTR_T])
	// 	return (ERR_IMG);





	player->sprite[FINAL_ROW] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_ROW], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_ROW])
		return (ERR_IMG);
	player->sprite[FINAL_ROW_R] = mlx_xpm_file_to_image(data->mlx_ptr,
		player->img[FINAL_ROW_R], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_ROW_R])
		return (ERR_IMG);
	player->sprite[FINAL_ROW_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_ROW_L], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_ROW_L])
		return (ERR_IMG);

		
	player->sprite[FINAL_STARTT_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_STARTT_L], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_STARTT_L])
		return (ERR_IMG);
	player->sprite[FINAL_STARTT_R] = mlx_xpm_file_to_image(data->mlx_ptr,
		player->img[FINAL_STARTT_R], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_STARTT_R])
		return (ERR_IMG);


	player->sprite[FINAL_STARTD_L] = mlx_xpm_file_to_image(data->mlx_ptr,
			player->img[FINAL_STARTD_L], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_STARTD_L])
		return (ERR_IMG);
	player->sprite[FINAL_STARTD_R] = mlx_xpm_file_to_image(data->mlx_ptr,
		player->img[FINAL_STARTD_R], &data->img->width, &data->img->height);
	if (!player->sprite[FINAL_STARTD_R])
		return (ERR_IMG);
	return (0);
}
