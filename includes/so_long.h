/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:19:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/11 18:16:04 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdbool.h>
# include "mlx.h"
#include <sys/time.h> 

# define KEY_CLOSE 65307
# define KEY_UP 119
# define KEY_RIGHT 100
# define KEY_LEFT 97
# define KEY_DOWN 115

typedef enum e_exit
{
	SUCCESS,
	ERR_ARGS,
	ERR_MALLOC,
	ERR_FD,
	ERR_DUPLICATE_PLAYER,
	ERR_NO_PLAYER,
	ERR_DUPLICATE_EXIT,
	ERR_NO_EXIT,
	ERR_NO_ITEM,
	ERR_BORDER,
	ERR_SIZE_MAP,
	ERR_MAP,
	ERR_MLX,
	ERR_IMG
}	t_exit;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	bool	start_pos;
	void	*pl_dead_r;
	void	*pl_dead_l;
	char	*img[3];
	bool	dir_left;
}	t_player;

typedef struct s_spaceship
{
	int		pos_x;
	int		pos_y;
	bool	spaceship_close;
	bool	spaceship_is_here;
}	t_spaceship;

typedef struct s_img
{
	void	*move[10];
	void	*nb_zero;
	void	*nb_one;
	void	*nb_two;
	void	*nb_three;
	void	*nb_four;
	void	*nb_five;
	void	*nb_six;
	void	*nb_seven;
	void	*nb_eight;
	void	*nb_nine;
	void	*img[13];
	void	*floor;
	void	*player;
	void	*player_l;
	void	*player_d;
	void	*player_t;
	void	*pl_dead_l;
	void	*object;
	void	*wall;
	void	*spaceship_close;
	void	*spaceship_open;
	void	*plright_exit;
	void	*pleft_exit;
	void	*pdown_exit;
	void	*ptop_exit;
	int		height;
	int		width;
}	t_img;

typedef struct s_enemy
{
	void	*img_top;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	int		pos_x;
	int		pos_y;
	bool	start_pos;
	char	*img[12];
	int		height;
	int		width;
	void	*img_t_exit;
	void	*img_d_exit;
	void	*img_r_exit;
	void	*img_l_exit;
	void	*img_t_opexit;
	void	*img_d_opexit;
	void	*img_r_opexit;
	void	*img_l_opexit;
}	t_enemy;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			screen_width;
	int			screen_height;
	int			fd;
	int			count_key;
	int			nb_obj;
	int			ac;
	char		**av;
	size_t		nb_line;
	size_t		nb_row;
	t_player	*player;
	t_spaceship	*spaceship;
	t_img		*img;
	t_enemy		*enemy;
	struct timeval last_time;
}	t_data;

/* ************************************************************************** */
/*								Parsing							  	  		  */
/* ************************************************************************** */

void	init_struct_spaceship(t_spaceship *spaceship);
void	init_struct_player(t_player *player);
void	init_struct_img(t_img *img);
void	init_struct_data(t_data *data, t_spaceship *spaceship,
			t_player *player, t_img *img);
int		parsing(t_data *data, t_spaceship *spaceship,
			t_player *player, t_img *img);
int		check_inside_map(t_data *data, size_t i, size_t j);
int		map_is_valid(t_data *data);
int		check_duplicate_player_exit(t_data *data, int i, int j);
int		calculate_size_map(char **argv, t_data *data);
int		init_map(t_data *data);
int		exit_error_parse(t_exit error_num);
int		check_access(t_data *data);
char	**copy_map(t_data *data);
void	check_access_recursive(char **cpy, int start_x, int start_y);
int		count_no_access(char **cpy, t_data *data);

/* ************************************************************************** */
/*								Utils							  	  		  */
/* ************************************************************************** */

void	free_all(char **str);
void	free_map(char **map, size_t nb);

/* ************************************************************************** */
/*							init window	and destroy			  	 	 		  */
/* ************************************************************************** */

void	init_img(t_data *data);
int		display_map(t_data *data);
int		load_img_map(t_data *data, t_img *img);
int		load_img_player(t_data *data, t_img *img);
int		load_img_exit(t_data *data, t_img *img);
int		game_loop(t_data *data);
void	put_image_to_win(t_data *data, size_t x, size_t y);
int		init_mlx(t_data *data);
void	ft_destroy_mlx(t_data *data);
void	ft_destroy_img(t_data *data, t_img *img);
void	ft_destroy_img_background(t_data *data, t_img *img);
void	ft_destroy_img_score(t_data *data, t_img *img);
void	ft_destroy_img_death(t_data *data);
void	ft_destroy_img_score_snd(t_data *data, t_img *img);
void	ft_destroy_img_exit(t_data *data, t_img *img);
int		keypress(int keysym, t_data *data);
void	put_floor_score_board(t_data *data);
int		close_window(t_data *data);

/* ************************************************************************** */
/*								player move						  	  		  */
/* ************************************************************************** */

void	move_down(t_data *data, t_player *player, t_img *img);
void	move_left(t_data *data, t_player *player, t_img *img);
void	move_right(t_data *data, t_player *player, t_img *img);
void	move_up(t_data *data, t_player *player, t_img *img);
void	open_spaceship(t_data *data, t_img *img);
void	check_end(t_data *data, t_player *player);
void	handle_old_position(t_data *data, t_player *player, t_img *img);
void	handle_new_position_r(t_data *data, t_player *player, t_img *img);
void	handle_new_position_l(t_data *data, t_player *player, t_img *img);
void	handle_new_position_d(t_data *data, t_player *player, t_img *img);
void	handle_new_position_t(t_data *data, t_player *player, t_img *img);
void	display_move_player(t_data *data);
int		display_count_move(t_data *data);
int		load_img_move(t_data *data, t_img *img);
int		load_img_move_snd(t_data *data, t_img *img);
void	init_move_count(t_data *data);
int		display_right_img(t_data *data, t_img *img);
void	select_right_nb(size_t i, t_data *data, t_img *img, char *str_move);
void	init_img_player(t_data *data);
int		touch_enemy(t_data *data, int next_x, int next_y, int dir);

/* ************************************************************************** */
/*								Enemy					  			  		  */
/* ************************************************************************** */

void	init_struct_enemy(t_enemy *enemy);
int		load_img_enemy(t_data *data, t_enemy *enemy);
int		load_img_enemy_exit(t_data *data, t_enemy *enemy);
void	init_enemy_img(t_data *data);
void	display_enemy(t_data *data);
void	ft_destroy_img_enemy(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy_exit(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy_opexit(t_data *data, t_enemy *enemy);
int		move_enemy(t_data *data);
void	add_enemy_data(t_data *data, t_enemy *enemy);
void	move_enemy_top(t_data *data, t_enemy *enemy);
void	move_enemy_down(t_data *data, t_enemy *enemy);
void	move_enemy_right(t_data *data, t_enemy *enemy);
void	move_enemy_left(t_data *data, t_enemy *enemy);
int		touch_player(t_data *data, int next_x, int next_y);
void	handle_old_position_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_t_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_r_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_l_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_d_enemy(t_data *data, t_enemy *enemy);


#endif
