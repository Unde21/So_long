/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:59:07 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/19 22:51:05 by samaouch         ###   ########lyon.fr   */
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
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->move_spr[NB_ZERO], i * 64, data->nb_line * 64);
		else if (str_move[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->move_spr[NB_ONE], i * 64, data->nb_line * 64);
		else if (str_move[i] == '2')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				img->move_spr[NB_TWO], i * 64, data->nb_line * 64);
		select_right_nb(i, data, img, str_move);
		++i;
	}
	free(str_move);
	return (0);
}

void	select_right_nb(size_t i, t_data *data, t_img *img, char *str_move)
{
	if (str_move[i] == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_TWO], i * 64, data->nb_line * 64);
	else if (str_move[i] == '3')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_THREE], i * 64, data->nb_line * 64);
	else if (str_move[i] == '4')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_FOUR], i * 64, data->nb_line * 64);
	else if (str_move[i] == '5')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_FIVE], i * 64, data->nb_line * 64);
	else if (str_move[i] == '6')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_SIX], i * 64, data->nb_line * 64);
	else if (str_move[i] == '7')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_SEVEN], i * 64, data->nb_line * 64);
	else if (str_move[i] == '8')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_EIGHT], i * 64, data->nb_line * 64);
	else if (str_move[i] == '9')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			img->move_spr[NB_NINE], i * 64, data->nb_line * 64);
}

// int	load_img_move(t_data *data, t_img *img)
// {
// 	img->move_spr[NB_ZERO] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_ZERO], &img->width, &img->height);
// 	if (!img->move_spr[NB_ZERO])
// 		return (ERR_IMG);
// 	img->move_spr[NB_ONE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_ONE], &img->width, &img->height);
// 	if (!img->move_spr[NB_ONE])
// 		return (ERR_IMG);
// 	img->move_spr[NB_TWO] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_TWO], &img->width, &img->height);
// 	if (!img->move_spr[NB_TWO])
// 		return (ERR_IMG);
// 	img->move_spr[NB_THREE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_THREE], &img->width, &img->height);
// 	if (!img->move_spr[NB_THREE])
// 		return (ERR_IMG);
// 	img->move_spr[NB_FOUR] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_FOUR], &img->width, &img->height);
// 	if (!img->move_spr[NB_FOUR])
// 		return (ERR_IMG);
// 	if (load_img_move_snd(data, img) != 0)
// 		return (ERR_IMG);
// 	return (0);
// }

// int	load_img_move_snd(t_data *data, t_img *img)
// {
// 	img->move_spr[NB_FIVE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_FIVE], &img->width, &img->height);
// 	if (!img->move_spr[NB_FIVE])
// 		return (ERR_IMG);
// 	img->move_spr[NB_SIX] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_SIX], &img->width, &img->height);
// 	if (!img->move_spr[NB_SIX])
// 		return (ERR_IMG);
// 	img->move_spr[NB_SEVEN] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_SEVEN], &img->width, &img->height);
// 	if (!img->move_spr[NB_SEVEN])
// 		return (ERR_IMG);
// 	img->move_spr[NB_EIGHT] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_EIGHT], &img->width, &img->height);
// 	if (!img->move_spr[NB_EIGHT])
// 		return (ERR_IMG);
// 	img->move_spr[NB_NINE] = mlx_xpm_file_to_image(data->mlx_ptr,
// 			img->move[NB_NINE], &img->width, &img->height);
// 	if (!img->move_spr[NB_NINE])
// 		return (ERR_IMG);
// 	return (0);
// }
