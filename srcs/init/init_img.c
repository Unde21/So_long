/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:35:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:06:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

int	init_img(t_data *data)
{
	data->img->img[0] = "img_file/floor.xpm";
	data->img->img[1] = "img_file/wall.xpm";
	data->img->img[2] = "img_file/player.xpm";
	data->img->img[3] = "img_file/object.xpm";
	data->img->img[4] = "img_file/exit_close.xpm";
	data->img->img[5] = "img_file/exit_open.xpm";
	data->img->img[6] = "img_file/player_in_exit.xpm";
	data->img->img[7] = "img_file/player_left_exit.xpm";
	data->img->img[8] = "img_file/player_left.xpm";
	data->img->img[9] = "img_file/player_down.xpm";
	data->img->img[10] = "img_file/player_d_exit.xpm";
	data->img->img[11] = "img_file/player_top.xpm";
	data->img->img[12] = "img_file/player_top_exit.xpm";
	init_move_count(data);
	if (check_access_sprite_img(data->img) != 0)
		return (-1);
	return (0);
}

void	init_move_count(t_data *data)
{
	data->img->move[0] = "img_file/nb_zero.xpm";
	data->img->move[1] = "img_file/nb_one.xpm";
	data->img->move[2] = "img_file/nb_two.xpm";
	data->img->move[3] = "img_file/nb_three.xpm";
	data->img->move[4] = "img_file/nb_four.xpm";
	data->img->move[5] = "img_file/nb_five.xpm";
	data->img->move[6] = "img_file/nb_six.xpm";
	data->img->move[7] = "img_file/nb_seven.xpm";
	data->img->move[8] = "img_file/nb_eight.xpm";
	data->img->move[9] = "img_file/nb_nine.xpm";
}

int	check_access_sprite_img(t_img *img)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	while (img->img[i])
	{
		fd = open(img->img[i], O_RDONLY);
		if (fd == -1)
			return (-1);
		close(fd);
		i++;
	}
	i = 0;
	while (img->move[i])
	{
		fd = open(img->move[i], O_RDONLY);
		if (fd == -1)
			return (-1);
		close(fd);
		i++;
	}
	return (0);
}
