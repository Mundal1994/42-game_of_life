/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:29:05 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 12:19:32 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizer.h"

static void	allocate_map(t_core *core);
static void	fill_map_matrix(t_core *core, int fd);

void	read_map(t_core *core)
{
	char	*line;
	int		fd;

	fd = open(core->map.file, O_RDONLY);
	if (fd < 0)
		error_print(core, "Error: Failed to open map file");

	core->map.iterations = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (core->map.file_height == 1)
			core->map.width = ft_strlen(line);
		core->map.file_height++;
		if (core->map.iterations == 0 && core->map.file_height > 1)
			core->map.height++;
		if (ft_atoi(line) != 0)
			core->map.iterations = ft_atoi(line);
		free(line);
	}
	close(fd);
	allocate_map(core);
	fd = open(core->map.file, O_RDONLY);
	if (fd < 0)
		error_print(core, "Error: Failed to open map file");
	fill_map_matrix(core, fd);
	close(fd);
}

static void	allocate_map(t_core *core)
{
	int	i;

	i = 0;
	core->map.matrix = (int **)ft_memalloc((core->map.file_height) * sizeof(int *));
	if (!core->map.matrix)
		error_print(core, "Error: Failed to allocate map matrix");
	while (i < core->map.file_height)
	{
		core->map.matrix[i] = (int *)ft_memalloc(core->map.width * sizeof(int));
		if (!core->map.matrix[i])
			error_print(core, "Error: Failed to allocate map matrix");
		i++;
	}
}

static void	fill_map_matrix(t_core *core, int fd)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	x = -1;
	while (get_next_line(fd, &line) == 1)
	{
		while (x++ < core->map.width)
		{
			if (line[x] == '.')
				core->map.matrix[y][x] = 0;
			else if (line[x] == 'X')
				core->map.matrix[y][x] = 1;
			else
				core->map.matrix[y][x] = -1;
		}
		x = -1;
		free(line);
		y++;
	}
}
