#include "../includes/life.h"

static void	count_live_neighbors(t_data *data, int i, int j, int *count)
{
	int	end_x;
	int	end_y;
	int	x;
	int	y;
	int	start_x;

	x = j - 1;
	y = i - 1;
	end_x = x + 3;
	end_y = y + 3;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	start_x = x;
	if (end_y > data->total_y)
		end_y = data->total_y;
	if (end_x > data->total_x)
		end_x = data->total_x;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			if (x == j && y == i)
				++x;
			if (data->map[y][x] == 'X')
				(*count)++;
			++x;
		}
		if (*count > 3)
			break ;
		++y;
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

void	algorithm(t_data *data, int *modified)
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
					if (*modified == FALSE)
						*modified = TRUE;
				}
			}
			else
			{
				if (check_live_cell(data, i, j, 0) == FALSE)
				{
					data->temp[i][j] = '.';
					if (*modified == FALSE)
						*modified = TRUE;
				}
			}
			++j;
		}
		++i;
	}
}
