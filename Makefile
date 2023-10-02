# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:43:40 by svalente          #+#    #+#              #
#    Updated: 2023/03/03 11:35:07 by svalente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

SRC = 	create_list\
		ft_atol\
		op_push\
		op_rev_rotate\
		op_rotate\
		op_swap\
		rules_checker\
		sort_3\
		sort_5\
		find\
		lists_functions\
		sort_all_numbers\
		sort_long\
		algo_send_a\
		algo_best\

SRC_BONUS = checker_bonus/checker\
			checker_bonus/ft_strcmp\
			checker_bonus/move_push\
			checker_bonus/move_rev_rotate\
			checker_bonus/move_rotate\
			checker_bonus/move_swap\
			checker_bonus/get_next_line/get_next_line\
			checker_bonus/get_next_line/get_next_line_utils\

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#$(VERBOSE).SILENT: #apagar!!

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

all: $(NAME)

$(NAME): $(SRC:=.o)
		make -C $(FT_PRINTF_PATH)
		$(CC) $(CFLAGS) $(SRC:=.o) $(FT_PRINTF) push_swap.c -fsanitize=address -o $(NAME) 

clean:
		$(RM) $(SRC:=.o) $(SRC_BONUS:=.o)
		make clean -C $(FT_PRINTF_PATH)

fclean: clean
		make fclean -C $(FT_PRINTF_PATH)
		$(RM) $(NAME) $(BONUS_NAME)
	
re: fclean all bonus

bonus: all $(BONUS_NAME)

$(BONUS_NAME):	$(SRC_BONUS:=.o)
				$(CC) $(CFLAGS) $(SRC_BONUS:=.o) $(SRC:=.c) $(FT_PRINTF) -fsanitize=address -o $(BONUS_NAME)