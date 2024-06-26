NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize="address"

SRC = src/main.c src/get_map.c src/parse.c src/map_dimensions.c src/flood_fill.c\
		src/images.c src/moves.c src/hooks.c
		
OBJ_DIR = src/obj

OBJS = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

RM = rm -f

INCLUDE = -L ./libft -lft -L ./minilibx -lmlx 

LIB_DIR = libft/

MLX_DIR = minilibx/

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

#COLORS
GREEN=\033[0;32m
LGREEN=\033[1;92m
CIAN=\033[36m
RED=\033[31m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "${CIAN}Compiling...${NC}"
	@make -s -C $(LIB_DIR)
	@make -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(MLX_FLAGS) -o $(NAME)
	@echo "${LGREEN}Program compiled✅${NC}"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)
	@make -s clean -C $(LIB_DIR)
	@make -s clean -C $(MLX_DIR)
	@echo "${MAGENTA}Objects deleted🧹${NC}"

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C $(LIB_DIR)
	@make -s clean -C $(MLX_DIR)
	@echo "${MAGENTA}All clean✨${NC}"

re:	fclean all

g3:
	gcc src/*.c libft/*.c libft/printf/*.c libft/gnl/*.c -g3 -fsanitize="address" -o so_long

.PHONY: all clean fclean re g3