#include "life.h"

static int	is_pos_digit(char *argv)
{
	int i = 0;

	while (argv[i] != '\0')
	{
		if (isdigit(argv[i]) == 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static int	initialize_functions(char **argv, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (read_file(argv[1 + i], data) == ERROR)
		return (0);
	if (i == 0)
		game_of_life(data, atoi(argv[2 + i]));
	else
		game_of_life_vis(data, atoi(argv[2 + i]));
	data->map = ft_free2d(data->map);
	free (data->map);
	data->temp = ft_free2d(data->temp);
	free (data->temp);
	free (data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3 && is_pos_digit(argv[2]) == TRUE && strcmp("-v", argv[1]) != 0)
		initialize_functions(argv, 0);
	else if (argc == 4 && is_pos_digit(argv[3]) == TRUE && strcmp("-v", argv[1]) == 0)
		initialize_functions(argv, 1);
	else
		printf("Usage: ./life maps/initial_state iterations\n");
	return (0);
}
