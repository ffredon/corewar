/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:04:17 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 09:19:15 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void	print_win_sub(t_struck *s, int j, int i)
{
	if (s->img.data[i] > 0 && (j = 1))
		s->img.data[i] -= 1;
	if (s->img.data[i] < 0 && (j = 1))
		s->img.data[i] += 1;
}

void	print_win(t_struck *s)
{
	int i;
	int k;
	int j;

	i = -1;
	j = 0;
	while (++i < s->img.sl * Y)
		print_win_sub(s, j, i);
	if (!j)
	{
		s->max = 2;
		i = -1;
		j = -1;
		while (++i < s->nb_chp)
			if (j < s->chp[i].last_live)
			{
				k = i;
				j = s->chp[i].last_live;
			}
		print_winner(s, k);
	}
}

int		aff_graph(t_struck *s)
{
	int			i;
	int			j;
	pthread_t	p[MT];

	if (!s->max)
	{
		ft_bzero(s->img.data, s->img.sl * Y);
		i = -1;
		if (!(s->rep & STOP))
			launching_vm_g(s);
		while (++i < MT)
			pthread_create(&p[i], NULL, thread_print, &s->img.t[i]);
		j = -1;
		while (++j < MT)
			pthread_join(p[j], NULL);
	}
	else
		print_win(s);
	set_proc_live(s);
	mlx_clear_window(s->img.mlx, s->img.menu);
	second_window(s);
	if (s->max < 2)
		mlx_put_image_to_window(s->img.mlx, s->img.win, s->img.img, 0, 0);
	return (1);
}
