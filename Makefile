NAME =				libftprintf.a
C_FILES = 			format_c.c format_s.c format_int.c format_u.c ft_aux.c ft_printf.c libft.c libftdos.c parameters.c prueba.c
C_FILES_BONUS =
O_FILES =			$(C_FILES:.c=.o)
O_FILES_BONUS =		$(C_FILES_BONUS:.c=.o)
CC = 				gcc
CFLAGS =			-Wall -Wextra -Werror
RM =				rm -f

all:		$(NAME)
$(NAME):	$(O_FILES)
	ar -rc $(NAME) $(O_FILES)
	ranlib $(NAME)

bonus:		$(O_FILES) $(O_FILES_BONUS)
	ar -rc $(NAME) $(O_FILES)
	ranlib $(NAME)

clean:
	$(RM) $(O_FILES) $(O_FILES_BONUS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: 	all bonus clean fclean re
