NAME		=	minishell

SRC_FILES	=	src/main.c \
				src/ft_echo.c \
				src/ft_echo_utils.c \
				src/get_envar.c \

LIBFT_PATH	=	libft/

LIBFT_LIB	=	libft/libft.a

INCLUDE_PATH	=	include/

SRC_OBJS	=	$(SRC_FILES:.c=.o)

LIBFTMAKE	=	$(MAKE) --no-print-directory -C $(LIBFT_PATH)

CC		=	clang

CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE_PATH) 

RM		=	rm -rf

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all:			$(NAME)

$(NAME):		$(SRC_OBJS)
				@$(LIBFTMAKE)
				@$(CC) -lreadline $(CFLAGS) $(SRC_OBJS) $(LIBFT_LIB) -o $(NAME)
				@echo "$(NAME) created"

clean:
			@make --no-print-directory -C $(LIBFT_PATH) clean
			@$(RM) $(SRC_OBJS)
			@echo "$(NAME) .o deleted"

fclean:			clean
				@$(RM) $(NAME) $(LIBFT_LIB)
				@echo "libft.a deleted"
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:			all clean fclean re
