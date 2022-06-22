#include "life.h"

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

static int	check_live_cell(t_data *data, int y, int x)
{
	int count;

	count = count_live_neighbors(data, y, x);
	if (count == 2 || count == 3)
		return (TRUE);
	else
		return (FALSE);
}

static int	check_dead_cell(t_data *data, int y, int x)
{
	int count;

	count = count_live_neighbors(data, y, x);
	if (count == 3)
		return (TRUE);
	else
		return (FALSE);
}

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

void	algorithm(t_data *data)
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
