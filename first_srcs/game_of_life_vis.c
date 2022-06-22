#include "life.h"

static void	write_to_file(t_data *data, FILE *fp)
{
	int	i;

	i = 0;
	while (i < data->total_y)
	{
		fprintf(fp, "%s\n", data->map[i]);
		++i;
	}
}

void	game_of_life_vis(t_data *data, int iterations)
{
	FILE	*fp;
	int		i;

	i = 0;
	fp = fopen("iterations.txt", "w");
	write_to_file(data, fp);
	while (i < iterations)
	{
		fprintf(fp, "\n");
		algorithm(data);
		array_copy(data);
		write_to_file(data, fp);
		++i;
	}
	fclose(fp);
}
