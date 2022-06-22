# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molesen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 12:16:20 by molesen           #+#    #+#              #
#    Updated: 2021/12/15 09:51:20 by molesen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror

SRCS = get_next_line.c
SRCS += ft_strchr.c
SRCS += ft_strdel.c
SRCS += ft_strdup.c
SRCS += ft_strjoin.c
SRCS += ft_strlen_stop.c
SRCS += ft_strcpy.c
SRCS += ft_strlen.c
SRCS += ft_free2d.c
SRCS += ft_strsub.c
SRCS += ft_strncpy.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(SRCS)
	@$(CC) -c -I ./includes $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
