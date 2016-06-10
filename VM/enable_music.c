/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_music.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:45:34 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 14:21:12 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void			enable_shoot(t_struck *s)
{
	static char i = 0;

	if (s->sound[0] == NULL)
	{
		s->sound[0] = Mix_LoadWAV("./VM/sounds/BaseBallBatImpact.wav");
		s->sound[1] = Mix_LoadWAV("./VM/sounds/ricochet.wav");
	}
	Mix_PlayChannel(1 + i, s->sound[(int)i], 0);
	i++;
	if (i == 2)
		i = 0;
}

void			enable_music(t_struck *s)
{
	s->music = Mix_LoadMUS("./VM/sounds/gergovia.mp3");
	Mix_PlayMusic(s->music, -1);
}
