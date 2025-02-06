NAME = so_long

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
