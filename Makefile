NAME = so_long

NAME_BONUS = so_long_bonus

SRCS := srcs/main.c \
	srcs/parsing/map_is_valid.c \
	srcs/parsing/map_is_valid_utils.c \
	srcs/parsing/check_access.c \
	srcs/mlx/init_win.c \
	srcs/mlx/mlx_utils.c \
	srcs/mlx/destroy_img.c \
	srcs/game/display_map.c \
	srcs/game/player_move.c \
	srcs/game/player_move_utils.c \
	srcs/game/display_move.c \
	srcs/game/open_exit.c \
	srcs/init/init_struct.c \
	srcs/init/init_img.c \
	srcs/init/load_img_map.c \


SRCSB := srcs_bonus/main_bonus.c \
	srcs_bonus/parsing/map_is_valid.c \
	srcs_bonus/parsing/map_is_valid_utils.c \
	srcs_bonus/parsing/check_access.c \
	srcs_bonus/mlx/init_win.c \
	srcs_bonus/mlx/mlx_utils.c \
	srcs_bonus/mlx/destroy_img.c \
	srcs_bonus/init/load_sprite_map.c \
	srcs_bonus/init/init_img.c \
	srcs_bonus/init/check_access.c \
	srcs_bonus/init/init_struct.c \
	srcs_bonus/init/init_enemy.c \
	srcs_bonus/game/display_map.c \
	srcs_bonus/game/display_move.c \
	srcs_bonus/game/game_update.c \
	srcs_bonus/game/landing_spaceship.c \
	srcs_bonus/game/open_exit.c \
	srcs_bonus/game/player/player_move.c \
	srcs_bonus/game/player/player_move_utils.c \
	srcs_bonus/game/player/remove_laser.c \
	srcs_bonus/game/player/remove_final_laser.c \
	srcs_bonus/game/player/remove_final_laser_utils.c \
	srcs_bonus/game/player/move_after_final_laser.c \
	srcs_bonus/game/player/final_laser_x.c \
	srcs_bonus/game/player/final_laser_y.c \
	srcs_bonus/game/player/player_laser_dir_x.c \
	srcs_bonus/game/player/player_laser_dir_y.c \
	srcs_bonus/game/player/final_laser.c \
	srcs_bonus/game/player/get_player_input.c \
	srcs_bonus/game/player/attack_player.c \
	srcs_bonus/game/player/player_laser_dir_utils.c \
	srcs_bonus/game/player/attack_player_utils.c \
	srcs_bonus/game/enemy/display_enemy.c \
	srcs_bonus/game/enemy/move_enemy.c \
	srcs_bonus/game/enemy/move_enemy_dir.c \
	srcs_bonus/game/enemy/move_enemy_utils.c \
	srcs_bonus/game/enemy/move_enemy_old_pos.c \
	srcs_bonus/game/enemy/remove_laser_fight.c \
	srcs_bonus/game/enemy/remove_laser.c \
	srcs_bonus/game/enemy/attack.c \
	srcs_bonus/game/enemy/touch_player.c \
	srcs_bonus/game/enemy/enemy_destroy_wall.c \
	srcs_bonus/game/enemy/move_after_destroy.c \
	srcs_bonus/game/enemy/enemy_laser_x.c \
	srcs_bonus/game/enemy/enemy_laser_y.c \


HEADER := libft/libft.h \
		includes/so_long.h \

HEADERB := libft/libft.h \
		includes/so_long_bonus.h \
		includes/enemy.h \
		includes/player.h \


CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFFLAGS := -MMD -MP

RM := rm -rf

SRC_DIR := srcs/
SRCB_DIR := srcs_bonus/
OBJ_DIR := .objs/
OBJB_DIR := .objs_bonus/
DEPS := $(OBJS:.o=.d)
DEPSB := $(OBJSB:.o=.d)
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
-include $(DEPSB)

all: $(NAME)

$(NAME): libft/libft.a  minilibx-linux/libmlx.a $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(MLX_FLAGS) ./libft/libft.a  -o $@
	@echo "$(CYAN)$(BOLD)$(FIRE)$(NAME) made successfully!$(OK)$(END)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

$(OBJB_DIR)%.o: $(SRCB_DIR)%.c $(HEADERB)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCS) $(CPPFFLAGS) -c -o $@ $<


bonus: $(NAME_BONUS)

$(NAME_BONUS): libft/libft.a  minilibx-linux/libmlx.a $(OBJSB) Makefile
	@$(RM) $(NAME)
	$(CC) $(CFLAGS) $(OBJSB) $(INCS) $(MLX_FLAGS) ./libft/libft.a  -o $@
	@echo "$(MAGENTA)$(BOLD)$(FIRE)$(NAME_BONUS) made successfully!$(OK)$(END)"


libft/libft.a : FORCE
	@$(MAKE) --no-print-directory -C libft

minilibx-linux/libmlx.a : FORCE
	@$(MAKE) --no-print-directory -C minilibx-linux

FORCE :

clean:
	@$(RM) $(OBJ_DIR) $(OBJB_DIR)
	@$(MAKE) --no-print-directory -C libft clean
	@$(MAKE) -C minilibx-linux clean
	@echo "$(YELLOW)$(BOLD)$(CLEAN)Objects directory cleaned$(CLEAN)$(END)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C libft fclean
	@echo "$(YELLOW)$(BOLD)$(CLEAN)Everything cleaned $(DONE)$(END)"

re: fclean all

.PHONY: all clean fclean re libft FORCE bonus
