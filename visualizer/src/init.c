/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:44:33 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 12:19:39 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizer.h"

void	init(t_core *core)
{
	core->map.file_height = 0;
	core->map.height = 0;
	core->map.width = 0;
	core->map.iterations = 0;
	core->map.step = 0;
	read_map(core);
	init_sdl(core);
}

void	init_sdl(t_core *core)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
		error_print(core, "Error: Failed to initialize SDL2");
	core->sdl.win = SDL_CreateWindow("Game of Life - Visualizer", 0, 0, WIN_W, WIN_H, 0);
	if (!core->sdl.win)
		error_print(core, "Error: Failed to create window");
	core->sdl.rend = SDL_CreateRenderer(core->sdl.win,
				SDL_RENDERER_SOFTWARE, 0);
	if (!core->sdl.rend)
		error_print(core, "Error: Failed to create renderer");
	SDL_SetRenderDrawColor(core->sdl.rend, 25, 25, 25, 255);
	SDL_RenderClear(core->sdl.rend);
	SDL_RenderPresent(core->sdl.rend);
}
