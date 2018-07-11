# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/04/17 14:40:39 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
FLAGS		= -Wall -Werror -Wextra
SRC			= fillit.c\
			  get_next_line.c\
			  board.c\
			  pieces.c\
			  formatting.c\
			  main.c
OBJ			= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	@cp libft/libft.a ./
	@gcc $(FLAGS) $(OBJ) -o $(NAME) libft.a

$(OBJ):
	@gcc $(FLAGS) -c $(SRC) -I .

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make -C libft/ fclean

re: fclean all
