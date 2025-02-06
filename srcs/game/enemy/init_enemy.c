/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:56:25 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/06 05:45:22 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_enemy(t_data *data, t_enemy *enemy)
{
	data->enemy = enemy;
	enemy->img_top = NULL;
	enemy->img_down = NULL;
	enemy->img_left = NULL;
	enemy->img_right = NULL;
	enemy->pos_x = 0;
	enemy->pos_y = 0;
	enemy->start_pos = false;
	enemy->height = 0;
	enemy->width = 0;
}

void	init_enemy_img(t_data *data)
{
	data->enemy->img[0] = "img_file/nb_zero.xpm";
	data->enemy->img[1] = "img_file/nb_one.xpm";
	data->enemy->img[2] = "img_file/nb_two.xpm";
	data->enemy->img[3] = "img_file/nb_three.xpm";
	data->enemy->img[4] = "img_file/nb_four.xpm";
}
