/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:59:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:01:42 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	display_count_move(t_data *data)
{
	ft_printf("Number move: %d\n", data->count_key);
	if (display_right_img(data, data->img) != 0)
		return (-1);
	return (0);
}

int	display_right_img(t_data *data, t_img *img)
{
	char	*str_move;
	size_t	i;

	i = 0;
	str_move = ft_itoa(data->count_key);
	if (!str_move)
		return (exit_error_parse(ERR_MALLOC));
	while (str_move[i])
	{
		if (str_move[i] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_zero,
				i * 64, (data->nb_line) * 64);
		else if (str_move[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_one, i
				* 64, (data->nb_line) * 64);
		else if (str_move[i] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_two, i
				* 64, (data->nb_line) * 64);
		select_right_nb(i, data, img, str_move);
		++i;
	}
	free(str_move);
	return (0);
}

void	select_right_nb(size_t i, t_data *data, t_img *img, char *str_move)
{
	if (str_move[i] == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_two, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '3')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_three, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '4')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_four, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_five, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_six, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_seven, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_eight, i
			* 64, (data->nb_line) * 64);
	else if (str_move[i] == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->nb_nine, i
			* 64, (data->nb_line) * 64);
}

int	load_img_move(t_data *data, t_img *img)
{
	img->nb_zero = mlx_xpm_file_to_image(data->mlx_ptr, img->move[0],
			&img->width, &img->height);
	if (!img->nb_zero)
		return (ERR_IMG);
	img->nb_one = mlx_xpm_file_to_image(data->mlx_ptr, img->move[1],
			&img->width, &img->height);
	if (!img->nb_one)
		return (ERR_IMG);
	img->nb_two = mlx_xpm_file_to_image(data->mlx_ptr, img->move[2],
			&img->width, &img->height);
	if (!img->nb_two)
		return (ERR_IMG);
	img->nb_three = mlx_xpm_file_to_image(data->mlx_ptr, img->move[3],
			&img->width, &img->height);
	if (!img->nb_three)
		return (ERR_IMG);
	img->nb_four = mlx_xpm_file_to_image(data->mlx_ptr, img->move[4],
			&img->width, &img->height);
	if (!img->nb_four)
		return (ERR_IMG);
	if (load_img_move_snd(data, img) != 0)
		return (ERR_IMG);
	return (0);
}

int	load_img_move_snd(t_data *data, t_img *img)
{
	img->nb_five = mlx_xpm_file_to_image(data->mlx_ptr, img->move[5],
			&img->width, &img->height);
	if (!img->nb_five)
		return (ERR_IMG);
	img->nb_six = mlx_xpm_file_to_image(data->mlx_ptr, img->move[6],
			&img->width, &img->height);
	if (!img->nb_six)
		return (ERR_IMG);
	img->nb_seven = mlx_xpm_file_to_image(data->mlx_ptr, img->move[7],
			&img->width, &img->height);
	if (!img->nb_seven)
		return (ERR_IMG);
	img->nb_eight = mlx_xpm_file_to_image(data->mlx_ptr, img->move[8],
			&img->width, &img->height);
	if (!img->nb_eight)
		return (ERR_IMG);
	img->nb_nine = mlx_xpm_file_to_image(data->mlx_ptr, img->move[9],
			&img->width, &img->height);
	if (!img->nb_nine)
		return (ERR_IMG);
	return (0);
}
