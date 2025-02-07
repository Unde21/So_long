/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:18:02 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/07 06:21:36 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

int	init_mlx(t_data *data)
{
	init_img(data);
	init_enemy_img(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (-1);
	mlx_get_screen_size(data->mlx_ptr, &data->screen_width,
		&data->screen_height);
	if ((data->screen_height) < ((int)data->nb_line + 2) * 64
		|| (data->screen_width) < (int)data->nb_row * 64)
	{
		ft_destroy_mlx(data);
		return (exit_error_parse(ERR_SIZE_MAP));
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->nb_row) * 64,
			(data->nb_line + 1) * 64, "./so_long");
	if (!data->win_ptr)
	{
		ft_destroy_mlx(data);
		return (-1);
	}
	if (game_loop(data) != 0)
		return (-1);
	return (0);
}

int	game_loop(t_data *data)
{
	if (display_map(data) != 0)
	{
		ft_destroy_mlx(data);
		return (-1);
	}
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, keypress, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	if (mlx_loop(data->mlx_ptr) != 0)
		return (-1);
	return (0);
}

void	check_end(t_data *data, t_player *player)
{
	if (data->map[player->pos_y][player->pos_x] == 'E' && data->nb_obj == 0)
		close_window(data);
}

int	close_window(t_data *data)
{
	ft_printf("Game quit\n");
	ft_destroy_mlx(data);
	exit(0);
	return (0);
}
