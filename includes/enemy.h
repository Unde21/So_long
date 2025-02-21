/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:31:42 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 23:58:59 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include <sys/time.h>
# include <stdbool.h>

struct					s_data;
typedef struct s_data	t_data;
struct					s_img;
typedef struct s_img	t_img;

# define MOVE_ENEMY_FRAME 150
# define LASER_MVE_FRAME 30
# define LASER_FRAME 5000000
# define LIFE 2

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
# define DESTROY_ENEMY 28
# define LIFE_GREEN 29
# define LIFE_RED 30

typedef struct s_enemy
{
	int					pos_x;
	int					pos_y;
	bool				is_start_pos;
	bool				is_laser_enemy;
	bool				is_fighting_laser;
	bool				is_alive;
	int					moved;
	char				*img[31];
	void				*sprite[31];
	int					height;
	int					width;
	int					life;
	int					laser_frame;
	int					laser_x;
	int					laser_y;
	int					laser_dir;
	int					s_pos_x;
	int					s_pos_y;
}						t_enemy;

void	save_last_position_player(t_data *data);
void	save_exit_and_object(t_data *data, int x, int y);
void	remove_display_laser_enemy(t_data *data, t_enemy *enemy);
void	remove_basic_display_laser_enemy(t_data *data, t_enemy *enemy);
void	move_in_row_after_destroy(t_data *data, t_enemy *enemy);
void	move_in_line_after_destroy(t_data *data, t_enemy *enemy);
void	move_enemy_top(t_data *data, t_enemy *enemy);
void	move_enemy_right(t_data *data, t_enemy *enemy);
void	move_enemy_left(t_data *data, t_enemy *enemy);
void	move_enemy_down(t_data *data, t_enemy *enemy);
void	laser_top(t_data *data, t_enemy *enemy);
void	laser_right(t_data *data, t_enemy *enemy);
void	laser_left(t_data *data, t_enemy *enemy);
void	laser_down(t_data *data, t_enemy *enemy);
void	is_spaceship_at_pos(t_data *data, t_enemy *enemy);
void	init_struct_enemy(t_enemy *enemy);
void	init_enemy_img_laser(t_data *data);
void	handle_old_position_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_t_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_r_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_l_enemy(t_data *data, t_enemy *enemy);
void	handle_new_position_d_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_top_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_right_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_left_enemy(t_data *data, t_enemy *enemy);
void	handle_laser_down_enemy(t_data *data, t_enemy *enemy);
void	handle_enemy_move(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy_opexit(t_data *data, t_enemy *enemy);
void	ft_destroy_img_enemy_exit(t_data *data, t_enemy *enemy);
void	ft_destroy_img_attack_enemy(t_data *data, t_enemy *enemy);
void	enemy_destroy_wall(t_data *data, t_enemy *enemy);
void	display_life(t_data *data, t_enemy *enemy);
void	display_floor(t_data *data, t_img *img);
void	display_enemy(t_data *data);
void	display_attack_enemy(t_data *data, t_enemy *enemy);
void	destroy_wall_row(t_data *data, t_enemy *enemy);
void	destroy_wall_line(t_data *data, t_enemy *enemy);
void	death_enemy(t_data *data, t_enemy *enemy);
void	check_enemy_move_status(t_data *data,
			struct timeval current_time, long elapsed_time);
void	check_enemy_laser_status(t_data *data,
			struct timeval current_time, long elapsed_time);
void	add_enemy_data(t_data *data, t_enemy *enemy);

int		touch_player(t_data *data, int next_x, int next_y);
int		touch_player_left(t_data *data, int next_x, int next_y);
int		remove_enemy_laser_up(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_right(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_left(t_data *data, t_enemy *enemy);
int		remove_enemy_laser_down(t_data *data, t_enemy *enemy);
int		remove_basic_laser_top(t_data *data, t_enemy *enemy);
int		remove_basic_laser_right(t_data *data, t_enemy *enemy);
int		remove_basic_laser_left(t_data *data, t_enemy *enemy);
int		remove_basic_laser_down(t_data *data, t_enemy *enemy);
int		move_enemy(t_data *data);
int		load_img_enemy(t_data *data, t_enemy *enemy);
int		is_needed_remove(t_data *data, t_enemy *enemy);
int		init_enemy_img(t_data *data);
int		enemy_run_with_spaceship(t_data *data);
int		enemy_laser(t_data *data, t_enemy *enemy);

#endif
