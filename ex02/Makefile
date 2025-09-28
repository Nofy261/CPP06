# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/27 14:34:58 by nolecler          #+#    #+#              #
#    Updated: 2025/09/27 14:35:34 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Base

CC = c++

CFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98


SRC := srcs/Base.cpp \
	srcs/main.cpp

OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re