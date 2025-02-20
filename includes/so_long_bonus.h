/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:19:59 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/20 06:00:32 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "enemy.h"
# include "libft.h"
# include "mlx.h"
# include "player.h"
# include <stdbool.h>
# include <sys/time.h>

# define END_FRAME 70000
# define LANDING_FRAME 15000

// Define Map value
# define LASER_CHAR 'L'
# define EXIT 'Z'
# define DEAD_OBJECT 'K'
# define DEAD_EXIT 'V'
# define PL_AND_EXIT 'S'
# define DEST_FLOOR '2'
# define DEST_EXIT '3'
# define PL_DEST_EXIT '4'
# define PL_DEST_FLOOR '5'

// Exit Sprite
# define EXIT_CLOSE 3
# define EXIT_OPEN 4
# define EXIT_FIRE 0
# define TRAIL_FIRE 1
# define LANDING_EXIT 2
# define EXIT_OP_DESTR 5
# define EXIT_DESTROY 6

// Map Sprite
# define FLOOR 0
# define WALL 1
# define OBJECT 2
# define DESTROY_FLOOR 9

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
}					t_exit;

typedef struct s_spaceship
{
	int		pos_x;
	int		pos_y;
	int		final_y;
	bool	spaceship_close;
	bool	spaceship_is_here;
	int		frame;
	void	*img[7];
	void	*sprite[7];
}	t_spaceship;

typedef struct s_img
{
	void	*move[10];
	void	*move_spr[10];
	void	*img[10];
	void	*sprite[10];
	int		height;
	int		width;
}	t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				screen_width;
	int				screen_height;
	int				fd;
	int				count_key;
	int				nb_obj;
	int				ac;
	char			**av;
	bool			end;
	bool			defeat;
	bool			landing;
	size_t			nb_line;
	size_t			nb_row;
	t_player		*player;
	t_spaceship		*spaceship;
	t_img			*img;
	t_enemy			*enemy;
	struct timeval	last_time;
}					t_data;

void	init_struct_spaceship(t_spaceship *spaceship);
void	init_struct_img(t_img *img);
void	check_access_recursive(char **cpy, int start_x, int start_y);

int		parsing(t_data *data, t_spaceship *spaceship,
			t_player *player, t_img *img);
int		map_is_valid(t_data *data);
int		init_struct_player(t_player *player);
int		init_struct_data(t_data *data, t_spaceship *spaceship,
			t_player *player, t_img *img);
int		init_map(t_data *data);
int		exit_error_parse(t_exit error_num);
int		count_no_access(char **cpy, t_data *data);
int		check_inside_map(t_data *data, size_t i, size_t j);
int		check_duplicate_player_exit(t_data *data, int i, int j);
int		check_access(t_data *data);
int		calculate_size_map(char **argv, t_data *data);

char	**copy_map(t_data *data);

/* ************************************************************************** */
/*								Utils							  	  		  */
/* ************************************************************************** */

void	free_map(char **map, size_t nb);
void	free_all(char **str);

/* ************************************************************************** */
/*							init window	and destroy			  	 	 		  */
/* ************************************************************************** */

void	put_image_to_win(t_data *data, size_t x, size_t y);
void	put_floor_score_board(t_data *data);
void	init_move_count(t_data *data);
void	init_img_laser_player(t_data *data);
void	ft_destroy_mlx(t_data *data);
void	ft_destroy_img(t_data *data, t_img *img);
void	destroy_spaceship_sprite(t_data *data, t_spaceship *spaceship);
void	destroy_player_sprite(t_data *data, t_player *player);
void	destroy_enemy_sprite(t_data *data, t_enemy *enemy);

int		load_img_player(t_data *data, t_player *player);
int		load_img_map(t_data *data, t_img *img);
int		load_img_exit(t_data *data, t_spaceship *spaceship);
int		keypress(int keysym, t_data *data);
int		init_mlx(t_data *data);
int		init_img(t_data *data);
int		init_img_spaceship(t_data *data);
int		init_img_player(t_data *data);
int		game_loop(t_data *data);
int		display_map(t_data *data);
int		close_window(t_data *data);
int		check_access_sprite_spaceship(t_spaceship *spaceship);
int		check_access_sprite_player(t_player *player);
int		check_access_sprite_img(t_img *img);
int		check_access_sprite_enemy(t_enemy *enemy);

/* ************************************************************************** */
/*								Game loop					 	 	 		  */
/* ************************************************************************** */

void	open_spaceship(t_data *data, t_spaceship *spaceship);
void	landing_spaceship(t_data *data);
void	landing_spaceship_utils(t_data *data);
void	landing_spaceship_display(t_data *data);
void	display_right_sprite_end(t_data *data, t_player *player);
void	check_end(t_data *data, t_player *player);

int		game_update(t_data *data);
int		death_status(t_data *data);

#endif
