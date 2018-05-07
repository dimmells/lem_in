# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelnyk  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by dmelnyk           #+#    #+#              #
#    Updated: 2018/03/24 15:31:21 by dmelnyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

PATH_LIBFT = src/libft

PATH_LEM_IN = src/lem_in

OBJ = $(SRC:.c=.o)

LIBFT = src/libft/libft.a

SRC =

SRC += src/lem_in/add_link.c
SRC += src/lem_in/add_link_level.c
SRC += src/lem_in/add_room.c
SRC += src/lem_in/add_way.c
SRC += src/lem_in/check.c
SRC += src/lem_in/create_table.c
SRC += src/lem_in/find_min_level.c
SRC += src/lem_in/find_way.c
SRC += src/lem_in/ft_exit.c
SRC += src/lem_in/ft_str_ddel.c
SRC += src/lem_in/get_index.c
SRC += src/lem_in/get_size.c
SRC += src/lem_in/lem_in.c
SRC += src/lem_in/print_way.c
SRC += src/lem_in/read_all.c
SRC += src/lem_in/read_map.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PATH_LIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@gcc $(FLAGS) -c $<
	@mv *o src/lem_in

clean:
	@make clean -C $(PATH_LIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@rm -rf $(NAME)

re: fclean all
