# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichubare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 16:55:43 by ichubare          #+#    #+#              #
#    Updated: 2017/10/01 17:53:07 by ichubare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = lem_in.c \
	  fill_struct.c \
	  fill_struct1.c \
	  fill_struct2.c \
	  fill_struct3.c \
	  free_struct.c \
	  fill_graph.c \
	  fill_graph1.c \
	  clear_ways.c \
	  push_ants.c \
	  get_next_line.c \
	  ft_strsub.c \
	  ft_strsplit.c \
	  ft_strnew.c \
	  ft_strnequ.c \
	  ft_strlen.c \
	  ft_strjoin.c \
	  ft_strequ.c \
	  ft_strcmp.c \
	  ft_strchr.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putchar.c \
	  ft_lstnew.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_atoi.c \
	  ft_lstadd.c \
	  ft_memdel.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strncat.c \
	  ft_strncpy.c \
	  ft_strcat.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@gcc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)
