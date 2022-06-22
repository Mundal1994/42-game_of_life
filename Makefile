NAME = life
#NAME2 = life_vis

CC = gcc -Wall -Wextra -Werror

C = first_srcs/
#F = output_file/
#S = visualizer/

SRC = $(C)main.c
SRC += $(C)read_file.c
SRC += $(C)game_of_life.c
SRC += $(C)game_of_life_vis.c

#SRC2 = $(C)main.c
#SRC2 += $(C)read_file.c
#SRC2 += $(F)game_of_life.c

MAKELIB = make -C libft/ fclean && make -C libft/

all: $(NAME) $(NAME2)
$(NAME): $(SRC)
	$(MAKELIB)
	$(CC) $(SRC) ./libft/libft.a -o $(NAME)
#$(NAME2): $(SRC2)
#	$(MAKELIB)
#	$(CC) $(SRC2) ./libft/libft.a -o $(NAME2)

clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
