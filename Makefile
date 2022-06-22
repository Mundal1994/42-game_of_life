NAME = life
NAME2 = first_life

CC = gcc -Wall -Wextra -Werror

C = srcs/
S = first_srcs/

SRC = $(C)main.c
SRC += $(C)read_file.c
SRC += $(C)game_of_life.c
SRC += $(C)algorithm.c
SRC += $(C)game_of_life_vis.c

SRC2 = $(C)main.c
SRC2 += $(C)read_file.c
SRC2 += $(S)game_of_life.c
SRC2 += $(C)algorithm.c
SRC2 += $(C)game_of_life_vis.c

MAKELIB = make -C libft/ fclean && make -C libft/

all: $(NAME) $(NAME2)
$(NAME): $(SRC)
	$(MAKELIB)
	$(CC) -O1 $(SRC) ./libft/libft.a -o $(NAME)
$(NAME2): $(SRC2)
	$(MAKELIB)
	$(CC) $(SRC2) ./libft/libft.a -o $(NAME2)

clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME) $(NAME2)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
