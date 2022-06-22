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

int	main(int argc, char **argv)
{
	if (argc == 3 && is_pos_digit(argv[2]) == TRUE)
	{
		if (argv && argc)
			printf("correct\n");
		// collect initial map file info from argv[1]
		FILE *fp;
		int ret;
		char *line;
		fp = fopen(argv[1], "r");
		line = NULL;
		ret = get_next_line(fp, &line);
		printf("line: %s\n", line);
		while (ret > 0)
		{
			ret = get_next_line(fp, &line);
			if (ret == 0)
			{
				free (line);
				break ;
			}
			printf("line: %s\n", line);
			free(line);
		}
		// play game of life
		
	}
	else
		printf("Usage: ./life maps/initial_state iterations\n");
	return (0);
}

/*

Rules of the Game of Life
The universe of the Game of Life is an infinite, two-dimensional
orthogonal grid of square cells, each of which is in one of two
possible states, live or dead. Every cell interacts with its eight
neighbors, which are the cells that are horizontally, vertically, or
diagonally adjacent. At each step in time, the following transitions
occur:
• Any live cell with two or three live neighbors survives.
• Any dead cell with three live neighbors becomes a live cell.
• All other live cells die in the next generation. Similarly, all
other dead cells stay dead.

*/