# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 11:14:21 by nolecler          #+#    #+#              #
#    Updated: 2025/09/23 09:03:38 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CC = c++

CFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98

SRC := srcs/ScalarConverter.cpp \
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