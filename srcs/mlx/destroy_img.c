/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:45:48 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/07 03:52:03 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img(t_data *data, t_img *img)
{
	ft_destroy_img_background(data, img);
	ft_destroy_img_exit(data, img);
	ft_destroy_img_score(data, img);
	ft_destroy_img_score_snd(data, img);
	ft_destroy_img_enemy(data, data->enemy);
	if (img->player != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->player);
		img->player = NULL;
	}
	if (img->player_t != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->player_t);
		img->player_t = NULL;
	}
	if (img->player_l != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->player_l);
		img->player_l = NULL;
	}
	if (img->player_d != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->player_d);
		img->player_d = NULL;
	}
}

void	ft_destroy_img_exit(t_data *data, t_img *img)
{
	if (img->ptop_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->ptop_exit);
		img->ptop_exit = NULL;
	}
	if (img->pleft_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->pleft_exit);
		img->pleft_exit = NULL;
	}
	if (img->pdown_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->pdown_exit);
		img->pdown_exit = NULL;
	}
	if (img->plright_exit != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->plright_exit);
		img->plright_exit = NULL;
	}
}

void	ft_destroy_img_background(t_data *data, t_img *img)
{
	if (img->floor != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->floor);
		img->floor = NULL;
	}
	if (img->wall != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->wall);
		img->wall = NULL;
	}
	if (img->object != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->object);
		img->object = NULL;
	}
	if (img->spaceship_close != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->spaceship_close);
		img->spaceship_close = NULL;
	}
	if (img->spaceship_open != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->spaceship_open);
		img->spaceship_open = NULL;
	}
}

void	ft_destroy_img_score(t_data *data, t_img *img)
{
	if (img->nb_zero != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_zero);
		img->nb_zero = NULL;
	}
	if (img->nb_one != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_one);
		img->nb_one = NULL;
	}
	if (img->nb_two != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_two);
		img->nb_two = NULL;
	}
	if (img->nb_three != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_three);
		img->nb_three = NULL;
	}
	if (img->nb_four != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_four);
		img->nb_four = NULL;
	}
}

void	ft_destroy_img_score_snd(t_data *data, t_img *img)
{
	if (img->nb_five != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_five);
		img->nb_five = NULL;
	}
	if (img->nb_six != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_six);
		img->nb_six = NULL;
	}
	if (img->nb_seven != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_seven);
		img->nb_seven = NULL;
	}
	if (img->nb_eight != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_eight);
		img->nb_eight = NULL;
	}
	if (img->nb_nine != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->nb_nine);
		img->nb_nine = NULL;
	}
}
