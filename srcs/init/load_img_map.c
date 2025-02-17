/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:38:47 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 01:39:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_img_player(t_data *data, t_img *img)
{
	img->player = mlx_xpm_file_to_image(data->mlx_ptr, img->img[2],
			&img->width, &img->height);
	if (!img->player)
		return (ERR_IMG);
	img->player_t = mlx_xpm_file_to_image(data->mlx_ptr, img->img[11],
			&img->width, &img->height);
	if (!img->player_t)
		return (ERR_IMG);
	img->player_l = mlx_xpm_file_to_image(data->mlx_ptr, img->img[8],
			&img->width, &img->height);
	if (!img->player_l)
		return (ERR_IMG);
	img->ptop_exit = mlx_xpm_file_to_image(data->mlx_ptr, img->img[12],
			&img->width, &img->height);
	if (!img->ptop_exit)
		return (ERR_IMG);
	data->player->pl_dead_r = mlx_xpm_file_to_image(data->mlx_ptr, data->player->img[0],
			&img->width, &img->height);
	if (!data->player->pl_dead_r)
		return (ERR_IMG);
	data->player->pl_dead_l = mlx_xpm_file_to_image(data->mlx_ptr, data->player->img[1],
			&img->width, &img->height);
	if (!data->player->pl_dead_l)
		return (ERR_IMG);
	data->player->pl_dead_l_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->player->img[3],
		&img->width, &img->height);
	if (!data->player->pl_dead_l_exit)
		return (ERR_IMG);
	data->player->pl_dead_r_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->player->img[2],
		&img->width, &img->height);
	if (!data->player->pl_dead_r_exit)
		return (ERR_IMG);
	return (0);
}

int	load_img_exit(t_data *data, t_img *img)
{
	img->player_d = mlx_xpm_file_to_image(data->mlx_ptr, img->img[9],
			&img->width, &img->height);
	if (!img->player_d)
		return (ERR_IMG);
	img->pdown_exit = mlx_xpm_file_to_image(data->mlx_ptr, img->img[10],
			&img->width, &img->height);
	if (!img->pdown_exit)
		return (ERR_IMG);
	img->spaceship_close = mlx_xpm_file_to_image(data->mlx_ptr, img->img[4],
			&img->width, &img->height);
	if (!img->spaceship_close)
		return (ERR_IMG);
	img->plright_exit = mlx_xpm_file_to_image(data->mlx_ptr, img->img[6],
			&img->width, &img->height);
	if (!img->plright_exit)
		return (ERR_IMG);
	img->pleft_exit = mlx_xpm_file_to_image(data->mlx_ptr, img->img[7],
			&img->width, &img->height);
	if (!img->pleft_exit)
		return (ERR_IMG);
	img->exit_fire = mlx_xpm_file_to_image(data->mlx_ptr, img->img[13],
			&img->width, &img->height);
	if (!img->exit_fire)
		return (ERR_IMG);
	img->trail_fire = mlx_xpm_file_to_image(data->mlx_ptr, img->img[14],
			&img->width, &img->height);
	if (!img->trail_fire)
		return (ERR_IMG);
	img->landing_spaceship = mlx_xpm_file_to_image(data->mlx_ptr, img->img[15],
		&img->width, &img->height);
	if (!img->landing_spaceship)
		return (ERR_IMG);
	return (0);
}

int	load_img_map(t_data *data, t_img *img)
{
	img->floor = mlx_xpm_file_to_image(data->mlx_ptr, img->img[0], &img->width,
			&img->height);
	if (!img->floor)
		return (ERR_IMG);
	img->wall = mlx_xpm_file_to_image(data->mlx_ptr, img->img[1], &img->width,
			&img->height);
	if (!img->wall)
		return (ERR_IMG);
	img->object = mlx_xpm_file_to_image(data->mlx_ptr, img->img[3], &img->width,
			&img->height);
	if (!img->object)
		return (ERR_IMG);
	img->explosion = mlx_xpm_file_to_image(data->mlx_ptr, img->img[16], &img->width,
			&img->height);
	if (!img->explosion)
		return (ERR_IMG);
	img->explosion_r = mlx_xpm_file_to_image(data->mlx_ptr, img->img[17], &img->width,
			&img->height);
	if (!img->explosion_r)
		return (ERR_IMG);
	img->explosion_d = mlx_xpm_file_to_image(data->mlx_ptr, img->img[18], &img->width,
			&img->height);
	if (!img->explosion_d)
		return (ERR_IMG);
	img->explosion_t = mlx_xpm_file_to_image(data->mlx_ptr, img->img[19], &img->width,
			&img->height);
	if (!img->explosion_t)
		return (ERR_IMG);


	
	img->laser_fight_x = mlx_xpm_file_to_image(data->mlx_ptr, img->img[20], &img->width,
			&img->height);
	if (!img->laser_fight_x)
		return (ERR_IMG);
	img->laser_fight_y = mlx_xpm_file_to_image(data->mlx_ptr, img->img[21], &img->width,
			&img->height);
	if (!img->laser_fight_y)
		return (ERR_IMG);


		
	if (load_img_exit(data, img) != 0)
		return (-1);
	if (load_img_player(data, img) != 0)
		return (-1);
	if (data->enemy->is_start_pos == true)
	{
		if (load_img_enemy(data, data->enemy) != 0)
			return (-1);
	}
	return (0);
}

int	load_img_enemy(t_data *data, t_enemy *enemy)
{
	enemy->img_right = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[3],
			&enemy->width, &enemy->height);
	if (!enemy->img_right)
		return (ERR_IMG);
	enemy->img_left = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[0],
			&enemy->width, &enemy->height);
	if (!enemy->img_left)
		return (ERR_IMG);
	enemy->img_top = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[2],
			&enemy->width, &enemy->height);
	if (!enemy->img_top)
		return (ERR_IMG);
	enemy->img_down = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[1],
			&enemy->width, &enemy->height);
	if (!enemy->img_down)
		return (ERR_IMG);
	if (load_img_enemy_exit(data, enemy) != 0)
		return (-1);
	enemy->img_d_opexit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[9],
			&enemy->width, &enemy->height);
	if (!enemy->img_d_opexit)
		return (ERR_IMG);
	enemy->img_t_opexit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[10],
			&enemy->width, &enemy->height);
	if (!enemy->img_t_opexit)
		return (ERR_IMG);
	





	enemy->attack_d = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[13],
			&enemy->width, &enemy->height);
	if (!enemy->attack_d)
		return (ERR_IMG);
	enemy->attack_l = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[12],
			&enemy->width, &enemy->height);
	if (!enemy->attack_l)
		return (ERR_IMG);
	enemy->attack_r = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[15],
		&enemy->width, &enemy->height);
	if (!enemy->attack_r)
		return (ERR_IMG);
	enemy->attack_t = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[14],
			&enemy->width, &enemy->height);
	if (!enemy->attack_t)
		return (ERR_IMG);




	enemy->use_laser_l = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[19],
			&enemy->width, &enemy->height);
	if (!enemy->use_laser_l)
		return (ERR_IMG);
	enemy->use_laser_r = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[20],
			&enemy->width, &enemy->height);
	if (!enemy->use_laser_r)
		return (ERR_IMG);
	enemy->laser_start_l = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[18],
		&enemy->width, &enemy->height);
	if (!enemy->laser_start_l)
		return (ERR_IMG);
	enemy->laser_start_r = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[17],
			&enemy->width, &enemy->height);
	if (!enemy->laser_start_r)
		return (ERR_IMG);
	enemy->laser_line = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[16],
			&enemy->width, &enemy->height);
	if (!enemy->laser_line)
		return (ERR_IMG);












	enemy->use_laser_t = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[25],
			&enemy->width, &enemy->height);
	if (!enemy->use_laser_t)
		return (ERR_IMG);
	enemy->use_laser_d = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[24],
			&enemy->width, &enemy->height);
	if (!enemy->use_laser_d)
		return (ERR_IMG);
	enemy->laser_start_t = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[23],
		&enemy->width, &enemy->height);
	if (!enemy->laser_start_t)
		return (ERR_IMG);
	enemy->laser_start_d = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[22],
			&enemy->width, &enemy->height);
	if (!enemy->laser_start_d)
		return (ERR_IMG);
	enemy->laser_row = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[21],
			&enemy->width, &enemy->height);
	if (!enemy->laser_row)
		return (ERR_IMG);



	enemy->destroy_wall = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[26],
		&enemy->width, &enemy->height);
	if (!enemy->destroy_wall)
		return (ERR_IMG);
	return (0);
}

int	load_img_enemy_exit(t_data *data, t_enemy *enemy)
{
	enemy->img_r_exit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[7],
			&enemy->width, &enemy->height);
	if (!enemy->img_r_exit)
		return (ERR_IMG);
	enemy->img_l_exit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[4],
			&enemy->width, &enemy->height);
	if (!enemy->img_l_exit)
		return (ERR_IMG);
	enemy->img_t_exit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[6],
			&enemy->width, &enemy->height);
	if (!enemy->img_t_exit)
		return (ERR_IMG);
	enemy->img_d_exit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[5],
			&enemy->width, &enemy->height);
	if (!enemy->img_down)
		return (ERR_IMG);
	enemy->img_r_opexit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[11],
			&enemy->width, &enemy->height);
	if (!enemy->img_r_opexit)
		return (ERR_IMG);
	enemy->img_l_opexit = mlx_xpm_file_to_image(data->mlx_ptr, enemy->img[8],
			&enemy->width, &enemy->height);
	if (!enemy->img_l_opexit)
		return (ERR_IMG);
	return (0);
}
