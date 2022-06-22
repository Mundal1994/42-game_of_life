#include "../includes/life.h"

static int	error(t_data *data)
{
	if (data->map)
		ft_free2d(data->map);
	if (data->temp)
		ft_free2d(data->map);
	if (data)
		free(data);
	return (ERROR);
}

static int count_size(FILE *fp, t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(fp, &line);
	data->total_y++;
	data->total_x = strlen(line);
	free (line);
	while (ret == 1)
	{
		ret = get_next_line(fp, &line);
		if (ret == 0)
			break ;
		else if (ret == -1)
			return (ERROR);
		data->total_y++;
		free (line);
	}
	return (0);
}

static int	create_map_helper(t_data *data)
{
	int	i;

	data->map = (char **)malloc(sizeof(char *) * (data->total_y + 1));
	if (!data->map)
		return (ERROR);
	data->temp = (char **)malloc(sizeof(char *) * (data->total_y + 1));
	if (!data->temp)
		return (ERROR);
	i = 0;
	while (i < data->total_y)
	{
		data->map[i] = (char *)malloc(sizeof(char) * (data->total_x + 1));
		if (!data->map[i])
			return (error(data));
		data->temp[i] = (char *)malloc(sizeof(char) * (data->total_x + 1));
		if (!data->temp[i])
			return (ERROR);
		++i;
	}
	return (0);
}

static int	make_maps(FILE *fp, t_data *data)
{
	int		ret;
	int		i;
	char	*line;

	create_map_helper(data);
	i = 0;
	ret = get_next_line(fp, &line);
	strcpy(data->map[i], line);
	strcpy(data->temp[i], line);
	i++;
	free (line);
	while (ret == 1)
	{
		ret = get_next_line(fp, &line);
		if (ret == 0)
			break ;
		else if (ret == -1)
			return (ERROR);
		strcpy(data->map[i], line);
		strcpy(data->temp[i], line);
		i++;
		free (line);
	}
	data->map[i] = 0;
	data->temp[i] = 0;
	return (0);
}

int	read_file(char *file, t_data *data)
{
	FILE *fp;

	fp = fopen(file, "r");
	data->total_y = 0;
	if (count_size(fp, data) == ERROR)
		return (ERROR);
	fseek(fp, 0, SEEK_SET);
	if (make_maps(fp, data) == ERROR)
		return (ERROR);
	fclose(fp);
	return (0);
}
