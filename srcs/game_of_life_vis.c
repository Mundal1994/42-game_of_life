#include "../includes/life.h"

static void	write_to_file(t_data *data, FILE *fp, int iteration)
{
	int	i;

	i = 0;
	fprintf(fp, "%d\n", iteration);
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
	write_to_file(data, fp, i);
	while (i < iterations)
	{
		algorithm(data);
		array_copy(data);
		++i;
		write_to_file(data, fp, i);
	}
	fclose(fp);
}
