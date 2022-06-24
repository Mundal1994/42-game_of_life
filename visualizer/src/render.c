/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:37:59 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 19:48:08 by dpalacio         ###   ########.fr       */
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
	int			y = core->map.height * core->map.step + 1;
	int			x_off;
	int			y_off;

	x_off = (WIN_W - core->map.width * 20) / 2;
	y_off = (WIN_H - core->map.height * 20) / 2;
	cell.x = 0;
	cell.y = 0;
	cell.w = 20;
	cell.h = 20;
		SDL_SetRenderDrawColor(core->sdl.rend, 25, 25, 25, 255);
		SDL_RenderClear(core->sdl.rend);
		SDL_SetRenderDrawColor(core->sdl.rend, 250, 250, 0, 150);
		while (y < core->map.height * (core->map.step + 1))
		{
			while (x < core->map.width)
			{
				if (core->map.matrix[y][x] == 1)
				{
					cell.x = x * cell.w + x_off;
					cell.y = y * cell.h - core->map.height * core->map.step * cell.h + y_off;
					SDL_RenderDrawRect(core->sdl.rend, &cell);
					SDL_RenderFillRect(core->sdl.rend, &cell);
				}
				x++;
			}
			x = 0;
			y++;
		}
		if (y % core->map.height == 0 && core->map.automatic == 1 && core->map.step < core->map.iterations)
		{
			SDL_Delay(core->map.delay);
			core->map.step++;
		}
}
