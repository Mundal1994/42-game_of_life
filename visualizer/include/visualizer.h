/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:24:27 by dpalacio          #+#    #+#             */
/*   Updated: 2022/06/23 19:48:03 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../libft/include/libft.h"
# include "../sdl/include/SDL.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>

/*-----RESOLUTION-----*/
# define WIN_W 1280
# define WIN_H 960

/*--------SDL---------*/
typedef struct s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Event		event;
}					t_sdl;

/*--------MAP---------*/
typedef struct s_map
{
	char		*file;
	int			**matrix;
	int			file_height;
	int			height;
	int			width;
	int			iterations;
	int			step;
	int			automatic;
	int			delay;
}				t_map;

/*--------CORE--------*/
typedef struct s_core
{
	t_sdl		sdl;
	t_map		map;
	int			is_runing;
}				t_core;

/*--------MAIN--------*/
void	exit_visualizer(t_core *core);
void	error_print(t_core *core, char *error_msg);

/*--------READ--------*/
void	read_map(t_core *core);

/*--------INIT--------*/
void	init(t_core *core);
void	init_sdl(t_core *core);

/*--------RENDER-------*/
void	render_frame(t_core *core);
void	display_step(t_core *core);

/*-------CONTROLS------*/
void	controls(t_core *core);
void	on_keydown(t_core *core);

#endif
