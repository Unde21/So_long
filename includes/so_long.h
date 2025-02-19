/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:19:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/19 20:21:52 by samaouch         ###   ########lyon.fr   */
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
# define FIRE_MVE_FRAME 500
# define END_FRAME 70000
# define LANDING_FRAME 15000
# define MOVE_ENEMY_FRAME 150
# define LASER_FRAME 5000000
# define LASER_MVE_FRAME 40
# define LASER_CHAR 'L'
# define EXIT 'Z'
# define DEAD_OBJECT 'K'
# define DEAD_EXIT 'V'
# define PL_AND_EXIT 'S'


// Player Sprite
# define PLAYER_R 11
# define PLAYER_T 9
# define PLAYER_L 6
# define PLAYER_D 7
# define PL_T_EXIT 10
# define PL_D_EXIT 8
# define PL_L_EXIT 5
# define PL_R_EXIT 4
# define P_DEATH_R 0
# define P_DEATH_L 1
# define PL_DEATH_EXIT 2
# define PR_DEATH_EXIT 3
# define PLAYER_LASER_R 12
# define PLAYER_LASER_L 13
# define PLAYER_LASER_D 14
# define PLAYER_LASER_T 15
# define PLAYER_EVO_R 16
# define PLAYER_EVO_L 17
# define PLAYER_EVO_D 18
# define PLAYER_EVO_T 19
# define FINAL_LINE 20
# define FINAL_LINE_D 21
# define FINAL_LINE_T 22
# define FINAL_START_T 23
# define FINAL_START_D 24
# define FINAL_STARTR_T 25
# define FINAL_STARTR_D 26
# define FINAL_ROW 27
# define FINAL_ROW_R 28
# define FINAL_ROW_L 29
# define FINAL_STARTT_R 32
# define FINAL_STARTT_L 33
# define FINAL_STARTD_R 30
# define FINAL_STARTD_L 31

// Exit Sprite
# define EXIT_CLOSE 3
# define EXIT_OPEN 4
# define EXIT_FIRE 0
# define TRAIL_FIRE 1
# define LANDING_EXIT 2

// Map Sprite
# define FLOOR 0
# define WALL 1
# define OBJECT 2

// Score Sprite
# define NB_ZERO 0
# define NB_ONE 1
# define NB_TWO 2
# define NB_THREE 3
# define NB_FOUR 4
# define NB_FIVE 5
# define NB_SIX 6
# define NB_SEVEN 7
# define NB_EIGHT 8
# define NB_NINE 9

// Animation Sprite
# define EXPLOSION_L 3
# define EXPLOSION_R 4
# define EXPLOSION_D 5
# define EXPLOSION_T 6
# define LASER_FIGHT_X 7
# define LASER_FIGHT_Y 8


// Enemy Sprite
# define ENEMY_R 3
# define ENEMY_L 0
# define ENEMY_T 2
# define ENEMY_D 1
# define ENEM_OEXIT_T 10
# define ENEM_OEXIT_R 11
# define ENEM_OEXIT_L 8
# define ENEM_OEXIT_D 9
# define ATT_R 15
# define ATT_L 12
# define ATT_D 13
# define ATT_T 14
# define USE_LASER_L 19
# define USE_LASER_R 20
# define USE_LASER_D 24
# define USE_LASER_T 25
# define LASER_START_L 18
# define LASER_START_R 17
# define LASER_START_D 22
# define LASER_START_T 23
# define LASER_LINE 16
# define LASER_ROW 21
# define SHIELD 26
# define ENEM_EXIT_R 7
# define ENEM_EXIT_L 4
# define ENEM_EXIT_D 5
# define ENEM_EXIT_T 6
# define ENEMY_DEATH 27


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
	char	*img[34];
	void	*sprite[34];
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
	bool	final_laser;
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
	void	*img[5];
	void	*sprite[5];
}	t_spaceship;

typedef struct s_img
{
	void	*move[10];
	void	*move_spr[10];
	void	*img[9];
	void	*sprite[9];
	int		height;
	int		width;
}	t_img;

typedef struct s_enemy
{
	int		pos_x;
	int		pos_y;
	bool	is_start_pos;
	bool	is_laser_enemy;
	bool	is_fighting_laser;
	bool	is_alive;
	int		moved;
	char	*img[28];
	void	*sprite[28];
	int		height;
	int		width;
	int		life;
	int		laser_frame;
	int		laser_x;
	int		laser_y;
	int		laser_dir;
	int		s_pos_x;
	int		s_pos_y;
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
void	init_img_spaceship(t_data *data);
int		display_map(t_data *data);
int		load_img_map(t_data *data, t_img *img);
int		load_img_player(t_data *data, t_player *player);
int		load_img_exit(t_data *data, t_spaceship *spaceship);
int		load_img_animation(t_data *data, t_img *img);
int		load_img_player_exit(t_data *data, t_player *player);
int		load_img_player_death(t_data *data, t_player *player);
int		load_img_player_final(t_data *data, t_player *player);
int		game_loop(t_data *data);
void	put_image_to_win(t_data *data, size_t x, size_t y);
int		init_mlx(t_data *data);
void	ft_destroy_mlx(t_data *data);
void	ft_destroy_img(t_data *data, t_img *img);
void	destroy_spaceship_sprite(t_data *data, t_spaceship *spaceship);
void	destroy_enemy_sprite(t_data *data, t_enemy *enemy);
void	destroy_player_sprite(t_data *data, t_player *player);
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
void	landing_spaceship_display(t_data *data);
int		enemy_run_with_spaceship(t_data *data);
void	open_spaceship(t_data *data, t_spaceship *spaceship);
void	display_right_sprite_end(t_data *data, t_player *player);
void	death_enemy(t_data *data, t_enemy *enemy);

/* ************************************************************************** */
/*								player move						  	  		  */
/* ************************************************************************** */

void	move_down(t_data *data, t_player *player, t_img *img);
void	move_left(t_data *data, t_player *player, t_img *img);
void	move_right(t_data *data, t_player *player, t_img *img);
void	move_up(t_data *data, t_player *player, t_img *img);
void	check_end(t_data *data, t_player *player);
void	handle_old_position(t_data *data, t_player *player, t_img *img);
void	handle_new_position_r(t_data *data, t_player *player);
void	handle_new_position_l(t_data *data, t_player *player);
void	handle_new_position_d(t_data *data, t_player *player);
void	handle_new_position_t(t_data *data, t_player *player);
void	display_move_player(t_data *data);
int		display_count_move(t_data *data);
int		load_img_move(t_data *data, t_img *img);
void	disp_final_laser(t_data *data, t_player *player);
void	remove_final_laser(t_data *data, t_player *player);
void	remove_final_laser_row(t_data *data, t_player *player);
void	remove_final_laser_line(t_data *data, t_player *player);
void	remove_final_laser_left(t_data *data, t_player *player);
void	remove_final_laser_right(t_data *data, t_player *player);
void	remove_final_laser_down(t_data *data, t_player *player);
void	remove_final_laser_up(t_data *data, t_player *player);
void	change_display_spaceship(t_data *data, int x, int y);
void	change_display_object(t_data *data, int x, int y);
void	change_display_floor(t_data *data, int x, int y);
void	final_laser_x(t_data *data, t_player *player);
void	final_laser_y(t_data *data, t_player *player);
void	reset_laser_pos(t_data *data, t_player *player);
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
int		is_player_dead(t_data *data, int next_x, int next_y);
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
int		is_laser_touch(t_data *data, int next_x, int next_y);

/* ************************************************************************** */
/*								Enemy					  			  		  */
/* ************************************************************************** */

void	init_struct_enemy(t_enemy *enemy);
int		load_img_enemy(t_data *data, t_enemy *enemy);
int		load_img_enemy_exit(t_data *data, t_enemy *enemy);
int	load_img_start_laser_enemy(t_data *data, t_enemy *enemy);
int	load_img_enemy_laser(t_data *data, t_enemy *enemy);
int	load_img_enemy_exit_open(t_data *data, t_enemy *enemy);
int	load_img_attack_enemy(t_data *data, t_enemy *enemy);
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
void	display_floor(t_data *data, t_img *img);
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
void	save_exit_and_object(t_data *data, int x, int y);
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
