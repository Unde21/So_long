/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:01:44 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/12 12:17:22 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	check_inside_map(t_data *data, size_t i, size_t j)
{
	if ((data->map[i][j] != 'E' && data->map[i][j] != '1'
			&& data->map[i][j] != 'P' && data->map[i][j] != 'C'
			&& data->map[i][j] != '0' && data->map[i][j] != 'B'))
	{
		if (data->map[i][j] != '\n')
			return (exit_error_parse(ERR_MAP));
		else if (j != data->nb_row)
			return (exit_error_parse(ERR_MAP));
	}
	if ((i == 0 && data->map[i][j] != '1') || (i == data->nb_line - 1
			&& data->map[i][j] != '1') || (j == 0 && data->map[i][j] != '1')
		|| (j == data->nb_row - 1 && data->map[i][j] != '1'))
		return (exit_error_parse(ERR_BORDER));
	if (data->map[i][j] == 'C')
		data->nb_obj++;
	if (check_duplicate_player_exit(data, i, j) != 0)
		return (-1);
	return (0);
}

int	check_duplicate_player_exit(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		if (data->player->is_start_pos == true)
			return (exit_error_parse(ERR_DUPLICATE_PLAYER));
		data->player->is_start_pos = true;
		data->player->pos_x = j;
		data->player->pos_y = i;
	}
	else if (data->map[i][j] == 'E')
	{
		if (data->spaceship->spaceship_is_here == true)
			return (exit_error_parse(ERR_DUPLICATE_EXIT));
		data->spaceship->spaceship_is_here = true;
	}
	else if (data->map[i][j] == 'B')
	{
		if (data->enemy->is_start_pos == true)
			return (exit_error_parse(ERR_DUPLICATE_PLAYER));
		data->enemy->is_start_pos = true;
	}
	return (0);
}

int	exit_error_parse(t_exit error_num)
{
	if (error_num == 1)
		ft_putstr_fd("Usage : ./so_long map.ber\n", 2);
	else if (error_num == 2)
		ft_putstr_fd("Error: Malloc failed !\n", 2);
	else if (error_num == 3)
		ft_putstr_fd("Error: Open file !\n", 2);
	else if (error_num == 4)
		ft_putstr_fd("Map Error: Duplicate player 'P' / 'B'\n", 2);
	else if (error_num == 5)
		ft_putstr_fd("Map Error: Player position not found 'P'\n", 2);
	else if (error_num == 6)
		ft_putstr_fd("Map Error: Duplicate Exit 'E'\n", 2);
	else if (error_num == 7)
		ft_putstr_fd("Map Error: Exit position not found 'E'\n", 2);
	else if (error_num == 8)
		ft_putstr_fd("Map Error: No item position 'C'\n", 2);
	else if (error_num == 9)
		ft_putstr_fd("Map Error: Border must be wall '1'\n", 2);
	else if (error_num == 10)
		ft_putstr_fd("Map Error: Size !\n", 2);
	else if (error_num == 11)
		ft_putstr_fd("Map Error: Unknown character found !\n", 2);
	else
		ft_putstr_fd("Error\n", 2);
	return (-1);
}
