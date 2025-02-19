NAME = so_long

SRCS := srcs/main.c \
	srcs/parsing/map_is_valid.c \
	srcs/parsing/map_is_valid_utils.c \
	srcs/parsing/check_access.c \
	srcs/mlx/init_win.c \
	srcs/mlx/mlx_utils.c \
	srcs/mlx/destroy_img.c \
	srcs/init/load_sprite_map.c \
	srcs/init/load_sprite_player.c \
	srcs/init/init_img.c \
	srcs/init/init_struct.c \
	srcs/init/load_sprite_enemy.c \
	srcs/init/load_sprite_enemy_laser.c \
	srcs/game/display_map.c \
	srcs/game/display_move.c \
	srcs/game/game_update.c \
	srcs/game/landing_spaceship.c \
	srcs/game/open_exit.c \
	srcs/game/player/player_move.c \
	srcs/game/player/player_move_utils.c \
	srcs/game/player/remove_laser.c \
	srcs/game/player/remove_final_laser.c \
	srcs/game/player/player_laser_dir_x.c \
	srcs/game/player/player_laser_dir_y.c \
	srcs/game/player/final_laser.c \
	srcs/game/player/get_player_input.c \
	srcs/game/player/attack_player.c \
	srcs/game/player/player_laser_dir_utils.c \
	srcs/game/player/attack_player_utils.c \
	srcs/game/enemy/display_enemy.c \
	srcs/game/enemy/init_enemy.c \
	srcs/game/enemy/move_enemy.c \
	srcs/game/enemy/move_enemy_dir.c \
	srcs/game/enemy/move_enemy_utils.c \
	srcs/game/enemy/move_enemy_old_pos.c \
	srcs/game/enemy/remove_laser_fight.c \
	srcs/game/enemy/remove_laser.c \
	srcs/game/enemy/attack.c \
	srcs/game/enemy/touch_player.c \
	srcs/game/enemy/enemy_destroy_wall.c \
	srcs/game/enemy/move_after_destroy.c \
	srcs/game/enemy/enemy_laser_x.c \
	srcs/game/enemy/enemy_laser_y.c \


HEADER := libft/libft.h \
		includes/so_long.h \


CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MMD -MP

RM := rm -rf

SRC_DIR := srcs/
OBJ_DIR := .objs/
DEPS := $(OBJS:.o=.d)
INCS := -I./includes -I./libft -I./minilibx-linux
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

MLX_DIR 	= minilibx-linux/
LIB_MLX 	= $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS	= -L $(MLX_DIR) -I $(MLX_DIR) -lmlx_Linux -lX11 -lXext $(LIB_MLX)


BOLD := \033[1m
GREEN := \033[0;32m
RED := \033[0;31m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m
YELLOW := \033[0;33m
END := \033[0m

CHECKMARK := "✔️"
WARNING := "⚠️"
FIRE := "🔥"
OK := "✅"
CLEAN := "🧹"
DONE := "🏁"

-include $(DEPS)

all: $(NAME)

$(NAME): libft/libft.a  minilibx-linux/libmlx.a $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(MLX_FLAGS) ./libft/libft.a  -o $@
	@echo "$(CYAN)$(BOLD)$(FIRE)$(NAME) made successfully!$(OK)$(END)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

libft/libft.a : FORCE
	@$(MAKE) --no-print-directory -C libft

minilibx-linux/libmlx.a : FORCE
	@$(MAKE) --no-print-directory -C minilibx-linux

FORCE :

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C libft clean
	@$(MAKE) -C minilibx-linux clean
	@echo "$(YELLOW)$(BOLD)$(CLEAN)Objects directory cleaned$(CLEAN)$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C libft fclean
	@echo "$(YELLOW)$(BOLD)$(CLEAN)Everything cleaned $(DONE)$(END)"

re: fclean all

.PHONY: all clean fclean re libft FORCE
