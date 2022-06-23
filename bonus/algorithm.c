#include "../includes/life.h"

static void	count_live_neighbors(t_data *data, int i, int j, int *count)
{
	int	x;
	int	y;
	int	start_x;
	int	k;
	int	n;

	k = 0;
	x = j - 1;
	y = i - 1;
	if (x < 0)
	{
		x = data->total_x - 1;
	}
	if (y < 0)
	{
		y = data->total_y - 1;
	}
	start_x = x;
	while (k < 3)
	{
		x = start_x;
		n = 0;
		while (n < 3)
		{
			if (x == j && y == i)
			{
				if (x == data->total_x - 1)
					x = 0;
				else
					++x;
				++n;
			}
			if (data->map[y][x] == 'X')
				(*count)++;
			if (x == data->total_x - 1)
				x = 0;
			else
				++x;
			++n;
		}
		if (*count > 3)
			break ;
		if (y == data->total_y - 1)
			y = 0;
		else
			++y;
		++k;
	}
}

static int	check_live_cell(t_data *data, int y, int x, int count)
{
	count_live_neighbors(data, y, x, &count);
	if (count == 2 || count == 3)
		return (TRUE);
	return (FALSE);
}

static int	check_dead_cell(t_data *data, int y, int x, int count)
{
	count_live_neighbors(data, y, x, &count);
	if (count == 3)
		return (TRUE);
	return (FALSE);
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
				if (check_dead_cell(data, i, j, 0) == TRUE)
				{
					data->temp[i][j] = 'X';
				}
			}
			else
			{
				if (check_live_cell(data, i, j, 0) == FALSE)
				{
					data->temp[i][j] = '.';
				}
			}
			++j;
		}
		++i;
	}
}
