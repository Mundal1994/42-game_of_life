#ifndef LIFE_H
# define LIFE_H

# include "../libft/libft.h"
# include <stdio.h>
# include <ctype.h>

typedef struct s_data
{
	char	**map;
	char	**temp;
	int		total_x;
	int		total_y;
}	t_data;

int		read_file(char *file, t_data *data);
void	game_of_life(t_data *data, int iterations);
void	game_of_life_vis(t_data *data, int iterations);
void	algorithm(t_data *data);
void	array_copy(t_data *data);

#endif
