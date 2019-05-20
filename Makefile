# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prastoin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:13:09 by prastoin          #+#    #+#              #
#    Updated: 2019/05/20 14:50:39 by fbecerri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = num

include src.mk

INC = includes

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(FLAG) -I$(INC) $(OBJ) -o $(NAME)

%.o: %.c
		gcc $(FLAG) -I$(INC) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
