/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:38:47 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/07 09:54:53 by samaouch         ###   ########lyon.fr   */
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
	if (load_img_exit(data, img) != 0)
		return (-1);
	if (load_img_player(data, img) != 0)
		return (-1);
	if (data->enemy->start_pos == true)
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
	return (0);
}
