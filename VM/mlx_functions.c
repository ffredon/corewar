/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 22:24:39 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 10:53:04 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

int		define_x(int l, t_img i)
{
	double var;

	var = ((l % (int)sqrt(MEM_SIZE) * 30) + i.move_x);
	return (i.zoom * (X / 2 * ((int)(l / MEM_SIZE) / 30) + var));
}

int		define_y(int l, t_img i)
{
	double var;

	var = ((l / (int)sqrt(MEM_SIZE) * 21) + i.move_y);
	return (i.zoom * (Y / 2 * ((int)(l / MEM_SIZE) / 21) + var));
}

void	set_proc_live(t_struck *s)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (s->map[i] == 1)
			s->proc_live[0][i] = 1;
		else
			s->proc_live[0][i] = 0;
		++i;
	}
}

void	thread_print_sub5(t_thread *m, int l, int *c)
{
	if (m->s->proc_test[l])
		triangle(c, &ft_colors_earth, 1, m->s);
	else if (m->s->proc_live[0][l])
		star(c, &ft_colors_earth, 1, m->s);
	else
		cercle(c, &ft_colors_earth, 1, m->s);
}

void	thread_print_sub6(t_thread *m, int l, int *c)
{
	if (m->s->proc_test[l])
		triangle(c, &black, 1, m->s);
	else
		cercle(c, &black, 1, m->s);
}
