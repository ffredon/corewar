/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 22:43:09 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 08:55:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void		key_functions_sub(int key, t_struck *s)
{
	if (key == 83)
		if (s->img.zoom > 0)
			s->img.zoom -= 0.1;
	if (key == 84)
		if (s->img.zoom < 3)
			s->img.zoom += 0.1;
	if (key == 69)
		if (s->turn < 500)
			s->turn += 5;
	if (key == 78)
		if (s->turn > 6)
			s->turn -= 5;
	if (key == 65)
		s->turn = 2;
}

int			key_functions(int key, t_struck *s)
{
	(void)s;
	if (key == 53)
		exit(1);
	if (key == 49)
		s->rep ^= STOP;
	if (key == 123)
		s->img.move_x -= 7;
	if (key == 124)
		s->img.move_x += 7;
	if (key == 125)
		s->img.move_y += 7;
	if (key == 126)
		s->img.move_y -= 7;
	key_functions_sub(key, s);
	return (1);
}
