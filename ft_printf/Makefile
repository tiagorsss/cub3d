# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:40:08 by lumiguel          #+#    #+#              #
#    Updated: 2023/11/25 17:40:02 by lumiguel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = ft_printf16.c ft_putstr.c ft_putchar.c ft_printnbr.c ft_putnbr_u.c ft_strchr.c ft_printf.c
SRCBOBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCBOBJ)
	ar rcs $(NAME) $(SRCBOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(SRCBOBJ)

fclean: clean
	rm -f $(NAME)
	

re: fclean all


.PHONY: all clean fclean re