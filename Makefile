NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 
		
OBJS = $(SRC:.c=.o)

OBJ_DIR = obj

RM = rm -f

INCLUDE = -L ./libft -lft 

LIB_DIR = libft/

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
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "${LGREEN}Program compiled✅${NC}"

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make -s clean -C $(LIB_DIR)
	@echo "${MAGENTA}Objects deleted🧹${NC}"

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C $(LIB_DIR)
	@echo "${MAGENTA}All clean✨${NC}"

re:	fclean all

g3:
	gcc src/*.c libft/*.c libft/printf/*.c -g3 -fsanitize="address" -o pipex

.PHONY: all clean fclean re g3