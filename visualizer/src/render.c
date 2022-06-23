/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:37:59 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 12:19:34 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizer.h"

void	render_frame(t_core *core)
{
	SDL_SetRenderDrawColor(core->sdl.rend, 25, 25, 25, 255);
	SDL_RenderClear(core->sdl.rend);
	display_step(core);
	SDL_RenderPresent(core->sdl.rend);
}

void	display_step(t_core *core)
{
	SDL_Rect	cell;
	int			x = 0;
	int			y = 0;
	int			step = 0;
	cell.x = 0;
	cell.y = 0;
	cell.w = 20;
	cell.h = 20;
	while (y < core->map.file_height)
	{
		SDL_SetRenderDrawColor(core->sdl.rend, 25, 25, 25, 255);
		SDL_RenderClear(core->sdl.rend);
		SDL_SetRenderDrawColor(core->sdl.rend, 250, 250, 0, 150);
		while (y < core->map.height * (step + 1))
		{
			while (x < core->map.width)
			{
				if (core->map.matrix[y][x] == 1)
				{
					cell.x = x * cell.w;
					cell.y = y * cell.h - core->map.height * step * cell.h;
					SDL_RenderDrawRect(core->sdl.rend, &cell);
					SDL_RenderFillRect(core->sdl.rend, &cell);
				}
				x++;
			}
			x = 0;
			y++;
		}
		step++;
		SDL_RenderPresent(core->sdl.rend);
		SDL_Delay(1000);
	}
}
