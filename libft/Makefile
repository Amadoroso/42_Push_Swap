# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 15:13:50 by apinho-a          #+#    #+#              #
#    Updated: 2026/05/09 20:35:24 by apinho-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
			ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c
FUNC_MACHINE_CODE = $(FUNC_FILES:.c=.o) # = to FUNC_FILES but with .o
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME) # first rule = default one

# % is a pattern for individual file matching. * expands to the full list at once.
%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
# creates the machine code .o ^
# $< = to depedency and $@ = to target
$(NAME) : $(FUNC_MACHINE_CODE)
	ar rcs $(NAME) $(FUNC_MACHINE_CODE)

clean:
	rm -f $(FUNC_MACHINE_CODE)

fclean: clean
	rm -f $(NAME)
	rm -fr a.out

re: fclean all

.PHONY: all clean fclean re