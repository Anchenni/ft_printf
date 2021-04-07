# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 23:31:51 by anchenni          #+#    #+#              #
#    Updated: 2021/04/04 23:42:44 by anchenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
SRCS		=	ft_printf.c ft_utils.c ft_printf_str.c \
				ft_printf_nbr.c \
				ft_printf_char.c\
				ft_printf_i.c\
				ft_printf_u.c\
				ft_printf_x.c\
				ft_printf_bx.c\
				ft_printf_p.c\
				ft_printf_char_cent.c\
				ft_utils_nbr.c\
				ft_utils2_nbr.c\
				ft_utils_str.c\
				ft_utils2_str.c\
				ft_utils2_x.c\
				ft_utils_x.c\
				ft_utils_p.c\
				ft_utils_u.c\
				ft_utils_printf.c\
				
				
				

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
