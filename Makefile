SRC = ./src/fdf.c\
	./src/creat_map.c\
	./src/free_utils.c\
	./src/algebra.c\
	./src/display.c\
	./src/display_utils.c\
	./src/handlers1.c\
	./src/handlers2.c\
	./src/maps_res.c\

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -rf

INCLUDE = fdf.h

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = ./include/Libft/libft.a

MINILIBX = ./minilibx-linux/libmlx.a

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) -lX11 -lXext -lm -lz -O3 -o $(NAME)

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