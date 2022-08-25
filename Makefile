# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquez <pmarquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 08:37:00 by pmarquez          #+#    #+#              #
#    Updated: 2022/06/16 10:28:24 by pmarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libftprintf.a
RM				= rm -f
INCLUDE			= include/ft_printf.h
SRCS			= src/ft_print_char.c src/ft_print_hexa.c src/ft_print_str.c src/ft_print_ptr.c src/ft_print_nbr.c \
					src/ft_print_unsigned.c src/ft_print_percent.c src/ft_printf.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I include/ -c $< -o $@

$(NAME):		$(OBJS)
				make -C libft/ all
				cp libft/libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				make -C libft/ fclean

re:				fclean $(NAME)

.PHONY:			all clean fclean