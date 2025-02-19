/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:29:10 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/19 02:28:11 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	parsing(t_data *data, t_spaceship *spaceship, t_player *player, t_img *img)
{
	if (data->ac != 2)
		return (exit_error_parse(ERR_ARGS));
	if (init_struct_data(data, spaceship, player, img) != 0)
		return (-1);
	if (calculate_size_map(data->av, data) != 0)
		return (-1);
	data->map = ft_calloc(sizeof(char *), (data->nb_line + 1));
	if (!data->map)
		return (exit_error_parse(ERR_MALLOC));
	data->fd = open(data->av[1], O_RDONLY);
	if (data->fd == -1)
		return (exit_error_parse(ERR_FD));
	if (init_map(data) != 0)
	{
		close(data->fd);
		return (-1);
	}
	init_struct_spaceship(spaceship);
	if (init_struct_player(player) != 0)
		return (-1);
	init_struct_img(img);
	init_struct_enemy(data->enemy);
	if (map_is_valid(data) != 0)
		return (-1);
	return (0);
}

int	init_map(t_data *data)
{
	size_t	i;
	int		check_error;

	check_error = 0;
	i = 0;
	while (i < data->nb_line)
	{
		data->map[i] = get_next_line(data->fd, &check_error);
		if (!data->map || check_error != 0)
		{
			free_all(data->map);
			return (exit_error_parse(ERR_MALLOC));
		}
		if (i == 0)
			data->nb_row = ft_strlen(data->map[i]) - 1;
		else
		{
			if (data->nb_row != ft_strlen(data->map[i]) - 1)
				return (exit_error_parse(ERR_SIZE_MAP));
		}
		++i;
	}
	return (0);
}

int	calculate_size_map(char **argv, t_data *data)
{
	char	*line;
	int		check_error;

	check_error = 0;
	line = NULL;
	data->nb_line = 0;
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		return (exit_error_parse(ERR_FD));
	while (1)
	{
		line = get_next_line(data->fd, &check_error);
		if (check_error != 0)
			return (-1);
		if (!line)
			break ;
		++data->nb_line;
		free(line);
	}
	close(data->fd);
	return (0);
}

int	map_is_valid(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (check_inside_map(data, i, j) != 0)
				return (-1);
			++j;
		}
		++i;
	}
	if (data->spaceship->spaceship_is_here == false)
		return (exit_error_parse(ERR_NO_EXIT));
	else if (data->nb_obj == 0)
		return (exit_error_parse(ERR_NO_ITEM));
	else if (data->player->is_start_pos == false)
		return (exit_error_parse(ERR_NO_PLAYER));
	if (check_access(data) != 0)
		return (-1);
	return (0);
}
