/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:01:03 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 19:59:05 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/visualizer.h"

void	controls(t_core *core)
{
	if (core->sdl.event.type == SDL_KEYDOWN)
		on_keydown(core);
}

void	on_keydown(t_core *core)
{
	if (core->sdl.event.key.keysym.sym == SDLK_ESCAPE)
		core->is_runing = 0;
	if (core->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (core->map.step < core->map.iterations)
			core->map.step++;
	}
	if (core->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (core->map.step > 0)
			core->map.step--;
	}
	if (core->sdl.event.key.keysym.sym == SDLK_r)
		core->map.step = 0;
	if (core->sdl.event.key.keysym.sym == SDLK_SPACE)
	{
		if (core->map.automatic == 0)
			core->map.automatic++;
		else if (core->map.automatic == 1)
			core->map.automatic--;
	}
	if (core->sdl.event.key.keysym.sym == SDLK_EQUALS)
	{
		if (core->map.delay > 50)
			core->map.delay -= 100;
	}
	if (core->sdl.event.key.keysym.sym == SDLK_MINUS)
	{
		if (core->map.delay < 2000)
			core->map.delay += 100;
	}
}
