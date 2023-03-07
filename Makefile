# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 10:53:28 by mhabib-a          #+#    #+#              #
#    Updated: 2023/03/05 09:35:50 by mhabib-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = get_next_line.c get_next_line_utils.c check_map.c check_map2.c path.c hooks.c open_tools.c place_map.c place_tools.c place_tools2.c hooks_tools.c
MANDATORY = so_long.c $(SRC)
OBJ = $(MANDATORY:.c=.o)
CFLAGS = -Wall -Wextra -Werror -Imlx
CC = cc
RM = rm -f
LIB = so_long.h

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(LIB)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean : clean
	$(RM) $(NAME) $(NAMEBONUS)

re : fclean all