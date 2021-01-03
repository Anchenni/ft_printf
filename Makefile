NAME		=	libftprintf.a
SRCS		=	ft_printf.c ft_utils.c ft_printf_str.c \
				ft_printf_nbr.c \
				ft_printf_char.c\
				ft_printf_i.c\
				ft_printf_u.c\
				ft_printf_x.c\
				ft_printf_bx.c\
				ft_printf_p.c\
				ft_printf_percent.c\
				
				
				

OBJS		= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: $(NAME)
$(NAME): $(OBJS)
	
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)
	
fclean:     clean
	/bin/rm -f $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
