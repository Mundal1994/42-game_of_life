#include "../includes/life.h"

void	array_copy(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->total_y)
	{
		j = 0;
		while (j < data->total_x)
		{
			data->map[i][j] = data->temp[i][j];
			++j;
		}
		++i;
	}
}

static void	print_iteration(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_y)
	{
		printf("%s\n", data->map[i]);
		++i;
	}
}

void	game_of_life(t_data *data, int iterations)
{
	int	i;

	i = 0;
	while (i < iterations)
	{
		algorithm(data);
		array_copy(data);
		++i;
	}
	print_iteration(data);
}
