SRC			= ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_striteri ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd get_next_line get_next_line_utils

BNO			= ft_lstnew ft_lstadd_front ft_lstlast ft_lstsize ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap get_next_line_bonus get_next_line_utils_bonus

SRCS		= $(addsuffix .c, ${SRC})

BNOS		= $(addsuffix .c, ${BNO})

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

OBJS_BO		= ${BNOS:.c=.o}

NAME		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

bonus:		${OBJS} ${OBJS_BO}
			${AR} ${NAME} ${OBJS} ${OBJS_BO}
			${RN} ${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BO}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
