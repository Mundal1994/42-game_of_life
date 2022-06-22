/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:29:05 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/22 15:53:29 by dpalacio         ###   ########.fr       */
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
	core->map.height = 0;
	core->map.iterations = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (core->map.width == 0)
		{
			core->map.width = ft_strlen(line);
			if (core->map.width == 1)
				core->map.width = 0;
		}
		if (core->map.width != 0)
			core->map.height++;
		else
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
	int	j;

	i = 0;
	j = 0;
	core->map.matrix = (int ***)ft_memalloc((core->map.height) * sizeof(int **));
	if (!core->map.matrix)
		error_print(core, "Error: Failed to allocate map matrix");
	while (j < core->map.iterations)
	{
		core->map.matrix[j] = (int **)ft_memalloc((core->map.height) * sizeof(int *));
		while (i < core->map.height)
		{
			core->map.matrix[j][i] = (int *)ft_memalloc(core->map.width * sizeof(int));
			if (!core->map.matrix[i])
				error_print(core, "Error: Failed to allocate map matrix");
			i++;
		}
		i = 0;
		j++;
	}
}

static void	fill_map_matrix(t_core *core, int fd)
{
	char	*line;
	int		z;
	int		y;
	int		x;

	z = 0;
	y = 0;
	x = -1;
	while (get_next_line(fd, &line) == 1)
	{
		//NEED TO WORK HERE FOR THE 3D DIMENSION OF THE ARRAY
		
		while (x++ < core->map.width)
		{
			if (line[x] == '.')
				core->map.matrix[z][y][x] = 0;
			if (line[x] == 'X')
			core->map.matrix[z][y][x] = 1;
			if (
		}
		x = -1;
		free(line);
		y++;
	}
}
