/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:19:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/17 05:32:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdbool.h>
# include "mlx.h"
#include <sys/time.h> 

# define KEY_CLOSE 65307
# define UP 119
# define RIGHT 100
# define LEFT 97
# define DOWN 115
# define FIRE 102
# define FIRE_FRAME 1000
# define FIRE_MVE_FRAME 1000
# define END_FRAME 70000
# define LANDING_FRAME 15000
# define MOVE_ENEMY_FRAME 150
# define LASER_FRAME 5000000
# define LASER_MVE_FRAME 50

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
	bool	is_start_pos;
	void	*pl_dead_r;
	void	*pl_dead_l;
	void	*pl_dead_l_exit;
	void	*pl_dead_r_exit;	
	char	*img[4];
	bool	dir_left;
	bool	death;
	int		frames;
	int		last_move;
	int		s_pos_x;
	int		s_pos_y;
	int		fire_frame;
	int		laser_x;
	int		laser_y;
	int		laser_dir;
	bool	is_laser_player;
	bool	is_fighting_laser;
	struct timeval last_time;
}	t_player;

typedef struct s_spaceship
{
	int		pos_x;
	int		pos_y;
	int		final_y;
	bool	spaceship_close;
	bool	spaceship_is_here;
	int		frame;
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
	void	*img[22];
	void	*floor;
	void	*player;
	void	*player_l;
	void	*player_d;
	void	*player_t;
	void	*object;
	void	*wall;
	void	*spaceship_close;
	void	*spaceship_open;
	void	*plright_exit;
	void	*pleft_exit;
	void	*pdown_exit;
	void	*ptop_exit;
	void	*exit_fire;
	void	*trail_fire;
	void	*explosion;
	void	*explosion_r;
	void	*explosion_t;
	void	*explosion_d;
	void	*landing_spaceship;
	void	*laser_fight_x;
	void	*laser_fight_y;
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
	bool	is_start_pos;
	bool	is_laser_enemy;
	bool	is_fighting_laser;
	bool	is_alive;
	int		moved;
	char	*img[27];
	int		height;
	int		width;
	int		life;
	int		laser_frame;
	int		laser_x;
	int		laser_y;
	int		laser_dir;
	int		s_pos_x;
	int		s_pos_y;
	void	*img_t_exit;
	void	*img_d_exit;
	void	*img_r_exit;
	void	*img_l_exit;
	void	*img_t_opexit;
	void	*img_d_opexit;
	void	*img_r_opexit;
	void	*img_l_opexit;
	void	*attack_t;
	void	*attack_r;
	void	*attack_l;
	void	*attack_d;
	void	*laser_start_r;
	void	*laser_start_l;
	void	*laser_start_d;
	void	*laser_start_t;
	void	*laser_line;
	void	*laser_row;
	void	*use_laser_l;
	void	*use_laser_r;
	void	*use_laser_t;
	void	*use_laser_d;
	void	*destroy_wall;
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
	bool		end;
	bool		defeat;
	bool		landing;
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
int		init_struct_player(t_player *player);
void	init_struct_img(t_img *img);
int		init_struct_data(t_data *data, t_spaceship *spaceship,
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
/*								Game loop					 	 	 		  */
/* ************************************************************************** */

int		game_update(t_data *data);
int		death_status (t_data *data);
void	landing_spaceship(t_data *data);
void	landing_spaceship_utils(t_data *data);
int		enemy_run_with_spaceship(t_data *data);

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
int		touch_enemy(t_data *data, int next_x, int next_y);
int		touch_enemy_left(t_data *data, int next_x, int next_y);
int		handle_death(t_data *data);
void	attack_player(t_data *data, t_player *player);
int		player_laser(t_data *data, t_player *player);
void	laser_left_player(t_data *data, t_player *player);
void	laser_right_player(t_data *data, t_player *player);
void	laser_down_player(t_data *data, t_player *player);
void	laser_top_player(t_data *data, t_player *player);
int		handle_player_laser(t_data *data, t_player *player);
void	handle_laser_left(t_data *data, t_player *player);
void	handle_laser_right(t_data *data, t_player *player);
void	handle_laser_down(t_data *data, t_player *player);
void	handle_laser_top(t_data *data, t_player *player);

void	remove_display_laser_p(t_data *data, t_player *player);
int		remove_player_laser_right(t_data *data, t_player *player);
int		remove_player_laser_left(t_data *data, t_player *player);
int		remove_player_laser_down(t_data *data, t_player *player);
int		remove_player_laser_up(t_data *data, t_player *player);

void	handle_laser_status(t_data *data, t_player *player);
int		check_dir_laser(t_data *data, t_player *player);
void	save_last_position(t_player *player, t_enemy *enemy);
void	input_action(int keysym, t_data *data);
void	disp_explosion(t_data *data, int next_x, int next_y);
void	is_laser_touch(t_data *data, int next_x, int next_y);

/* ************************************************************************** */
/*								Enemy					  			  		  */
/* ************************************************************************** */

void	init_struct_enemy(t_enemy *enemy);
int		load_img_enemy(t_data *data, t_enemy *enemy);
int		load_img_enemy_exit(t_data *data, t_enemy *enemy);
void	init_enemy_img(t_data *data);
void	init_enemy_img_laser(t_data *data);
void	display_enemy(t_data *data);
void	ft_destroy_img_enemy(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy_exit(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy_opexit(t_data *data, t_enemy *enemy);
void	ft_destroy_img_attack_enemy(t_data *data, t_enemy *enemy);
int		move_enemy(t_data *data);
void	check_enemy_move_status(t_data *data, struct timeval current_time, long elapsed_time);
void	handle_enemy_move(t_data *data, t_enemy *enemy);
void	save_last_position_player(t_data *data);
void	add_enemy_data(t_data *data, t_enemy *enemy); 
void	move_enemy_top(t_data *data, t_enemy *enemy);
void	move_enemy_down(t_data *data, t_enemy *enemy);
void	move_enemy_right(t_data *data, t_enemy *enemy);
void	move_enemy_left(t_data *data, t_enemy *enemy);
void	move_in_line_after_destroy(t_data *data, t_enemy *enemy);
void	move_in_row_after_destroy(t_data *data, t_enemy *enemy);
void	display_attack_enemy(t_data *data, t_enemy *enemy);
void	check_enemy_laser_status(t_data *data, struct timeval current_time, long elapsed_time);
void	enemy_destroy_wall(t_data *data, t_enemy *enemy);
void	destroy_wall_line(t_data *data, t_enemy *enemy);
void	destroy_wall_row(t_data *data, t_enemy *enemy);
void	display_floor(t_data *data);
int		touch_player(t_data *data, int next_x, int next_y);
int		touch_player_left(t_data *data, int next_x, int next_y);
void	handle_old_position_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_t_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_r_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_l_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_d_enemy(t_data *data, t_enemy *enemy);
int		enemy_laser(t_data *data, t_enemy *enemy);
void	laser_left(t_data *data, t_enemy *enemy);
void	laser_right(t_data *data, t_enemy *enemy);
void	laser_down(t_data *data, t_enemy *enemy);
void	laser_top(t_data *data, t_enemy *enemy);
void	handle_laser_right_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_left_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_top_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_down_enemy(t_data *data, t_enemy *enemy);
void	is_spaceship_at_pos(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_right(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_left(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_down(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_up(t_data *data, t_enemy *enemy);
void	remove_basic_display_laser_enemy(t_data *data, t_enemy *enemy);
int		is_needed_remove(t_data *data, t_enemy *enemy);
void	remove_display_laser_enemy(t_data *data, t_enemy *enemy);
int	remove_basic_laser_top(t_data *data, t_enemy *enemy);
int	remove_basic_laser_down(t_data *data, t_enemy *enemy);
int	remove_basic_laser_left(t_data *data, t_enemy *enemy);
int	remove_basic_laser_right(t_data *data, t_enemy *enemy);

#endif
