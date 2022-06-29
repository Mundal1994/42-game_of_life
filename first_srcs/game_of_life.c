#include "../includes/life.h"

/*	checks the neighboring cells if they are dead or alive cells	*/

static int	count_live_neighbors(t_data *data, int i, int j)
{
	int	end_x;
	int	end_y;
	int	x;
	int	y;
	int	start_x;
	int	count;

	x = j - 1;
	y = i - 1;
	end_x = x + 3;
	end_y = y + 3;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	start_x = x;
	count = 0;
	while (y < data->total_y && y < end_y)
	{
		x = start_x;
		while (x < data->total_x && x < end_x)
		{
			if (x == j && y == i)
				++x;
			if (data->map[y][x] == 'X')
				++count;
			++x;
		}
		++y;
	}
	return (count);
}

/*
**	checking an alive cells neighbors
**	if there are 2 or 3 surrounding alive cells the alive cell keeps living
**	or else it will turn into a dead cell
*/

static int	check_live_cell(t_data *data, int y, int x)
{
	int count;

	count = count_live_neighbors(data, y, x);
	if (count == 2 || count == 3)
		return (TRUE);
	else
		return (FALSE);
}

/*
**	checking a dead cells neighbors
**	if there are 3 surrounding alive cells the dead cell turns into a living cell
*/

static int	check_dead_cell(t_data *data, int y, int x)
{
	int count;

	count = count_live_neighbors(data, y, x);
	if (count == 3)
		return (TRUE);
	else
		return (FALSE);
}

/*	looping through each cell to check their neighbors	*/

static void	first_algorithm(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->total_y)
	{
		j = 0;
		while (j < data->total_x)
		{
			if (data->map[i][j] == '.')
			{
				if (check_dead_cell(data, i, j) == TRUE)
				{
					data->temp[i][j] = 'X';
				}
			}
			else
			{
				if (check_live_cell(data, i, j) == FALSE)
				{
					data->temp[i][j] = '.';
				}
			}
			++j;
		}
		++i;
	}
}

/*	copy the temporary array to the main map	*/

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

/*	printing the map to the terminal	*/

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

/*	does the choosen iterations and ends it with printing to the terminal	*/

void	game_of_life(t_data *data, int iterations)
{
	int	i;

	i = 0;
	while (i < iterations)
	{
		first_algorithm(data);
		array_copy(data);
		++i;
	}
	print_iteration(data);
}
