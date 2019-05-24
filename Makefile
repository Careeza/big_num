# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prastoin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:13:09 by prastoin          #+#    #+#              #
#    Updated: 2019/05/22 18:05:40 by fbecerri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = num.a

include src.mk

INC = includes

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -flto -O3

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
		gcc $(FLAG) -I$(INC) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
