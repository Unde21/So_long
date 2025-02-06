/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:03:41 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/05 22:01:41 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

char	**copy_map(t_data *data)
{
	size_t	i;
	char	**cpy;

	i = 0;
	cpy = malloc(sizeof(char *) * (data->nb_line + 1));
	if (!cpy)
		return (NULL);
	while (i < data->nb_line)
	{
		cpy[i] = malloc(sizeof(char) * ft_strlen(data->map[i]) + 1);
		if (!cpy[i])
		{
			free_all(cpy);
			return (NULL);
		}
		++i;
	}
	i = 0;
	while (i < data->nb_line)
	{
		ft_strlcpy(cpy[i], data->map[i], ft_strlen(data->map[i]) + 1);
		++i;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	check_access(t_data *data)
{
	char	**cpy;
	int		start_x;
	int		start_y;

	cpy = copy_map(data);
	if (!cpy)
	{
		free_all(cpy);
		return (exit_error_parse(ERR_MALLOC));
	}
	start_x = data->player->pos_x;
	start_y = data->player->pos_y;
	check_access_recursive(cpy, start_x, start_y);
	if (count_no_access(cpy, data) != 0)
	{
		free_all(cpy);
		ft_putstr_fd("Map Error: Can not access all Collectible or Exit !\n",
			2);
		return (-1);
	}
	free_all(cpy);
	return (0);
}

void	check_access_recursive(char **cpy, int start_x, int start_y)
{
	if (cpy[start_y][start_x] == '1' || cpy[start_y][start_x] == 'V')
		return ;
	cpy[start_y][start_x] = 'V';
	check_access_recursive(cpy, start_x + 1, start_y);
	check_access_recursive(cpy, start_x - 1, start_y);
	check_access_recursive(cpy, start_x, start_y + 1);
	check_access_recursive(cpy, start_x, start_y - 1);
}

int	count_no_access(char **cpy, t_data *data)
{
	size_t	x;
	size_t	y;
	int		nb_object;
	int		exit;

	exit = 0;
	nb_object = 0;
	x = 0;
	y = 0;
	while (y < data->nb_line)
	{
		x = 0;
		while (x < data->nb_row)
		{
			if (cpy[y][x] == 'C')
				++nb_object;
			else if (cpy[y][x] == 'E')
				++exit;
			++x;
		}
		++y;
	}
	if (exit == 0 && nb_object == 0)
		return (0);
	return (-1);
}
