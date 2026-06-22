NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -Iincludes/

LIBFT_DIR   = libft/
LIBFT_NAME  = libft.a
LIBFT       = $(LIBFT_DIR)$(LIBFT_NAME)

FUNC        = argument_parsing/argv_parser.c \
              argument_parsing/argv_parser_utils.c \
              argument_parsing/flag_parser.c \
              argument_parsing/disorder_strat.c \
              argument_parsing/insertion_sort.c \
              stack_functions/stack_func.c \
              output_printing/output_printing.c \
              algorithms/algorithm_routing.c \
              algorithms/medium_algorithm.c \
              algorithms/medium_algorithm_utils.c \
              operations/push_op.c \
              operations/revrot_op.c \
              operations/rotate_op.c \
              operations/swap_op.c \
              main.c

# Mapeia os ficheiros .c para .o mantendo a estrutura de pastas
MACHINE_CODE = $(FUNC:.c=.o)

HEADER      = includes/push_swap.h

all : $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(NAME) : $(MACHINE_CODE) $(LIBFT)
	$(CC) $(CFLAGS) $(MACHINE_CODE) $(LIBFT) -o $(NAME)

# Regra de compilação genérica correta para subpastas
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean:
	rm -f $(MACHINE_CODE)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re