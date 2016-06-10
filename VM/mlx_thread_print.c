/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_thread_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:01:30 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 09:24:16 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void	thread_print_sub1(t_thread *m, int l, int *c)
{
	if (m->s->proc_test[l] == 1)
		star(c, &burn, 1, m->s);
	else if (m->s->proc_test[l] == 2)
		star(c, &ft_colors_ice, 1, m->s);
	else if (m->s->proc_test[l] == 3)
		star(c, &ft_colors_mag, 1, m->s);
	else
		star(c, &ft_colors_earth, 1, m->s);
}

static void	thread_print_sub2(t_thread *m, int l, int *c)
{
	if (m->s->proc_test[l])
		triangle(c, &burn, 1, m->s);
	else if (m->s->proc_live[0][l])
		star(c, &burn, 1, m->s);
	else
		cercle(c, &burn, 1, m->s);
}

static void	thread_print_sub3(t_thread *m, int l, int *c)
{
	if (m->s->proc_test[l])
		triangle(c, &ft_colors_ice, 1, m->s);
	else if (m->s->proc_live[0][l])
		star(c, &ft_colors_ice, 1, m->s);
	else
		cercle(c, &ft_colors_ice, 1, m->s);
}

static void	thread_print_sub4(t_thread *m, int l, int *c)
{
	if (m->s->proc_test[l])
		triangle(c, &ft_colors_mag, 1, m->s);
	else if (m->s->proc_live[0][l])
		star(c, &ft_colors_mag, 1, m->s);
	else
		cercle(c, &ft_colors_mag, 1, m->s);
}

void		*thread_print(void *d)
{
	t_thread	*m;
	int			l;
	int			c[2];

	m = (t_thread*)d;
	l = m->lim[0] - 1;
	while (++l < m->lim[1])
	{
		c[0] = define_x(l, m->s->img);
		c[1] = define_y(l, m->s->img);
		if (m->s->proc_test[l] && m->s->proc_live[0][l])
			thread_print_sub1(m, l, c);
		else if (m->s->col_chp[l] == 1)
			thread_print_sub2(m, l, c);
		else if (m->s->col_chp[l] == 2)
			thread_print_sub3(m, l, c);
		else if (m->s->col_chp[l] == 3)
			thread_print_sub4(m, l, c);
		else if (m->s->col_chp[l] == 4)
			thread_print_sub5(m, l, c);
		else if (!m->s->col_chp[l])
			thread_print_sub6(m, l, c);
	}
	return (NULL);
}
