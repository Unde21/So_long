/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 03:51:24 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/07 05:51:49 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img_enemy(t_data *data, t_enemy *enemy)
{
	if (enemy->img_top != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_top);
		enemy->img_top = NULL;
	}
	if (enemy->img_down != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_down);
		enemy->img_down = NULL;
	}
	if (enemy->img_left != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_left);
		enemy->img_left = NULL;
	}
	if (enemy->img_right != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, enemy->img_right);
		enemy->img_right = NULL;
	}
}
