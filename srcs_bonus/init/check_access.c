/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:52:18 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:02:37 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <fcntl.h>
#include <unistd.h>

int	check_access_sprite_spaceship(t_spaceship *spaceship)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	while (spaceship->img[i])
	{
		fd = open(spaceship->img[i], O_RDONLY);
		if (fd == -1)
			return (-1);
		close(fd);
		i++;
	}
	return (0);
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

int	check_access_sprite_player(t_player *player)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	while (player->img[i])
	{
		fd = open(player->img[i], O_RDONLY);
		if (fd == -1)
			return (-1);
		close(fd);
		i++;
	}
	return (0);
}

int	check_access_sprite_enemy(t_enemy *enemy)
{
	int	i;
	int	fd;

	fd = 0;
	i = 0;
	while (enemy->img[i])
	{
		fd = open(enemy->img[i], O_RDONLY);
		if (fd == -1)
			return (-1);
		close(fd);
		i++;
	}
	return (0);
}
