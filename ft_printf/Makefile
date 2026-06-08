# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/11 17:11:14 by apinho-a          #+#    #+#              #
#    Updated: 2026/06/08 12:17:22 by apinho-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

FUNC = ft_printf.c ft_printf_aux.c ft_printf_aux2.c

MACHINE_CODE = $(FUNC:.c=.o)

all : $(NAME) # first rule = default one

# % is a pattern for individual file matching. * expands to the full list at once.
%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
# creates the machine code .o ^
# $< = to depedency and $@ = to target
$(NAME) : $(MACHINE_CODE)
	ar rcs $(NAME) $(MACHINE_CODE)

clean:
	rm -f $(MACHINE_CODE)

fclean: clean
	rm -f $(NAME)
	rm -fr a.out

re: fclean all

.PHONY: all clean fclean re test