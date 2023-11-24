SRC = ./src/fdf.c\
	./src/creat_map.c\
	./src/free_utils.c\
	./src/algebra.c\
	./src/display.c\
	./src/display_utils.c\
	./src/handlers.c\

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = ./include/Libft/libft.a

MINILIBX = ./minilibx-linux/libmlx.a

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) -lX11 -lXext -lm -lz -o $(NAME) $(LIBFT) $(MINILIBX)

$(LIBFT):
	make -C ./include/Libft -s

$(MINILIBX):
	make -C ./minilibx-linux -s

clean:
	$(RM) $(OBJ)
	make -C ./include/Libft clean -s
	make -C ./minilibx-linux clean -s

fclean: clean
	$(RM) $(NAME)
	make -C ./include/Libft fclean -s

re: fclean all