/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 22:15:02 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 10:58:25 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void	init_thread(t_struck *s)
{
	int i;
	int j;

	i = 0;
	j = MEM_SIZE / MT;
	while (i < MT)
	{
		s->img.t[i].nb = i;
		s->img.t[i].lim[0] = j * i;
		s->img.t[i].lim[1] = j * i + j;
		s->img.t[i].s = s;
		++i;
	}
}

static void	init_img(t_struck *s)
{
	s->img.move_x = 100;
	s->img.move_y = 15;
	s->img.zoom = 0.9;
	s->img.check = 0;
	s->img.save = 0;
	s->img.cycle_to_die = CYCLE_TO_DIE;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,
		1024) < 0)
		cor_err(10, "SDL_audio");
	enable_music(s);
}

void		init_graph(t_struck *s)
{
	if (!(s->img.mlx = mlx_init()))
		cor_err(14, "Mlx_init");
	if (!(s->img.menu = mlx_new_window(s->img.mlx, 400, 1000, "Informations")))
		cor_err(14, "New window");
	if (!(s->img.win = mlx_new_window(s->img.mlx, X, Y, "Corewar")))
		cor_err(14, "New window");
	if (!(s->img.img = mlx_new_image(s->img.mlx, X, Y)))
		cor_err(14, "New image");
	if (!(s->img.t = (t_thread *)ft_memalloc(sizeof(t_thread) * MT)))
		cor_err(4, NULL);
	init_img(s);
	s->img.data =
	mlx_get_data_addr(s->img.img, &s->img.bpp, &s->img.sl, &s->img.end);
	init_thread(s);
}
