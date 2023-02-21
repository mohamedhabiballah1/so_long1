# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 10:53:28 by mhabib-a          #+#    #+#              #
#    Updated: 2023/02/17 12:50:17 by mhabib-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = get_next_line.c get_next_line_utils.c so_long.c check_map.c check_map2.c path.c
OBJ = $(SRC:.c=.o)
//CFLAGS = -Wall -Wextra -Werror -Imlx
CC = cc
RM = rm -f
LIB = so_long.h

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(LIB)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean : clean
	$(RM) $(NAME) $(NAMEBONUS)

re : fclean all