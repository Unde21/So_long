/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:38:29 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 05:03:03 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_enemy	t_enemy;
typedef struct s_data	t_data;
typedef struct s_img	t_img;
struct					s_data;
struct					s_img;
struct					s_enemy;

// Key
# define KEY_CLOSE 65307
# define UP 119
# define RIGHT 100
# define LEFT 97
# define DOWN 115
# define FIRE 102

// Frame attack
# define FIRE_FRAME 1000
# define FIRE_MVE_FRAME 800

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
# define PLAYER_R_DESTROY 34
# define PLAYER_L_DESTROY 35
# define PLAYER_D_DESTROY 36
# define PLAYER_T_DESTROY 37
# define EXIT_DESTROY_T 38
# define EXIT_DESTROY_D 39
# define EXIT_DESTROY_L 40
# define EXIT_DESTROY_R 41

typedef struct s_player
{
	int					pos_x;
	int					pos_y;
	bool				is_start_pos;
	char				*img[42];
	void				*sprite[42];
	bool				dir_left;
	bool				death;
	int					frames;
	int					last_move;
	int					s_pos_x;
	int					s_pos_y;
	int					fire_frame;
	int					laser_x;
	int					laser_y;
	int					laser_dir;
	bool				is_laser_player;
	bool				is_fighting_laser;
	bool				final_laser;
	struct timeval		last_time;
}						t_player;

void	select_right_nb(size_t i, t_data *data, t_img *img, char *str_move);
void	save_last_position(t_player *player, t_enemy *enemy);
void	reset_laser_pos(t_data *data, t_player *player);
void	remove_final_laser(t_data *data, t_player *player);
void	remove_final_laser_up(t_data *data, t_player *player);
void	remove_final_laser_row(t_data *data, t_player *player);
void	remove_final_laser_right(t_data *data, t_player *player);
void	remove_final_laser_line(t_data *data, t_player *player);
void	remove_final_laser_left(t_data *data, t_player *player);
void	remove_final_laser_down(t_data *data, t_player *player);
void	remove_display_laser_p(t_data *data, t_player *player);
void	move_up(t_data *data, t_player *player, t_img *img);
void	move_right(t_data *data, t_player *player, t_img *img);
void	move_left(t_data *data, t_player *player, t_img *img);
void	move_down(t_data *data, t_player *player, t_img *img);
void	laser_top_player(t_data *data, t_player *player);
void	laser_right_player(t_data *data, t_player *player);
void	laser_left_player(t_data *data, t_player *player);
void	laser_down_player(t_data *data, t_player *player);
void	input_action(int keysym, t_data *data);
void	handle_old_position(t_data *data, t_player *player, t_img *img);
void	handle_new_position_t(t_data *data, t_player *player);
void	handle_new_position_r(t_data *data, t_player *player);
void	handle_new_position_l(t_data *data, t_player *player);
void	handle_new_position_d(t_data *data, t_player *player);
void	handle_laser_top(t_data *data, t_player *player);
void	handle_laser_status(t_data *data, t_player *player);
void	handle_laser_right(t_data *data, t_player *player);
void	handle_laser_left(t_data *data, t_player *player);
void	handle_laser_down(t_data *data, t_player *player);
void	final_laser_y(t_data *data, t_player *player);
void	final_laser_x(t_data *data, t_player *player);
void	final_laser_up(t_data *data, t_player *player);
void	final_laser_right(t_data *data, t_player *player);
void	final_laser_left(t_data *data, t_player *player);
void	final_laser_down(t_data *data, t_player *player);
void	display_move_player(t_data *data);
void	disp_final_laser(t_data *data, t_player *player);
void	disp_explosion(t_data *data, int next_x, int next_y);
void	check_destroy_old_position(t_data *data, t_player *player);
void	check_destroy_floor_t(t_data *data, t_player *player);
void	check_destroy_floor_r(t_data *data, t_player *player);
void	check_destroy_floor_l(t_data *data, t_player *player);
void	check_destroy_floor_d(t_data *data, t_player *player);
void	change_display_spaceship(t_data *data, int x, int y);
void	change_display_object(t_data *data, int x, int y);
void	change_display_floor(t_data *data, int x, int y);
void	attack_player(t_data *data, t_player *player);

int		touch_enemy(t_data *data, int next_x, int next_y);
int		touch_enemy_left(t_data *data, int next_x, int next_y);
int		remove_player_laser_up(t_data *data, t_player *player);
int		remove_player_laser_right(t_data *data, t_player *player);
int		remove_player_laser_left(t_data *data, t_player *player);
int		remove_player_laser_down(t_data *data, t_player *player);
int		player_laser(t_data *data, t_player *player);
int		is_player_dead(t_data *data, int next_x, int next_y);
int		is_laser_touch(t_data *data, int next_x, int next_y);
int		handle_player_laser(t_data *data, t_player *player);
int		handle_death(t_data *data);
int		display_right_img(t_data *data, t_img *img);
int		display_count_move(t_data *data);
int		check_dir_laser(t_data *data, t_player *player);

#endif
