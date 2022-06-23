/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:52:59 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 11:54:44 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizer.h"

void	error_print(t_core *core, char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	exit_visualizer(core);
}

void	exit_visualizer(t_core *core)
{
	int	i;

	i = 0;
	if (core->map.matrix)
	{
		while (i < core->map.file_height)
		{
			if (core->map.matrix[i])
				free(core->map.matrix[i]);
			i++;
		}
		free(core->map.matrix);
	}
	if (core->sdl.win)
		SDL_DestroyWindow(core->sdl.win);
	SDL_Quit();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_core	core;

	if (argc != 2)
		error_print(&core, "Usage: ./visualizer <valid_map_path>");
	core.map.file = argv[1];
	init(&core);
	//-------------- PRINT MAP
	int x = 0;
	int y = 0;
	printf("Iterations: %d\n", core.map.iterations);
	while (y < core.map.file_height)
	{
		while (x < core.map.width)
		{
			if (core.map.matrix[y][x] == -1)
			{
				printf("\n");
				y++;
				x = 0;
			}
			printf("%d ", core.map.matrix[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
	//-----------------------
	core.is_runing = 1;
	while (core.is_runing == 1)
	{
		render_frame(&core);
		while (SDL_PollEvent(&core.sdl.event))
		{
			if (core.sdl.event.type == SDL_QUIT)
				core.is_runing = 0;
		}
	}
	exit_visualizer(&core);
	return (0);
}
