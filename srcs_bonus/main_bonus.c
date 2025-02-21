/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:19:33 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/21 02:09:23 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_data		data;
	t_spaceship	spaceship;
	t_player	player;
	t_img		img;
	t_enemy		enemy;

	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.ac = argc;
	data.av = argv;
	if (check_map_format(&data) != 0)
		return (1);
	add_enemy_data(&data, &enemy);
	if (parsing(&data, &spaceship, &player, &img) != 0)
	{
		free_map(data.map, data.nb_line);
		return (1);
	}
	close(data.fd);
	if (init_mlx(&data) != 0)
	{
		ft_destroy_mlx(&data);
		return (1);
	}
	return (0);
}

void	free_map(char **map, size_t nb)
{
	size_t	i;

	i = 0;
	if (nb != 0 && map)
	{
		while (i < nb)
		{
			if (map[i])
			{
				free(map[i]);
				map[i] = NULL;
			}
			++i;
		}
	}
	if (map)
		free(map);
	map = NULL;
}

void	free_all(char **str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}
