#include "../includes/life.h"

/*	copies content of temporary map to the main map	*/

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

/*	prints the last iteration	*/

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

/*	loops through all the iterations and when reaching final iteration it prints the map	*/

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
