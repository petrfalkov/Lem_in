cmake_minimum_required(VERSION 3.6)
project(Lem_in)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES lem_in.c lem_in.h libft/libft.h libft/ft_putstr.c libft/ft_strnequ.c libft/get_next_line.c libft/get_next_line.h libft/ft_isdigit.c
        libft/ft_atoi.c libft/ft_isalnum.c libft/ft_strequ.c libft/ft_strsplit.c libft/ft_strnew.c libft/ft_lstadd.c libft/ft_strchr.c libft/ft_putchar.c
        libft/ft_strlen.c libft/ft_strcpy.c libft/ft_strncat.c libft/ft_memdel.c libft/ft_strdel.c libft/ft_strncpy.c libft/ft_strjoin.c libft/ft_strcmp.c
        libft/ft_strcat.c libft/ft_strjoin.c)
add_executable(LEM_IN ${SOURCE_FILES})

