/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_gen_fcts_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 19:09:17 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 04:17:34 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

long long int	set_lmod(int index, long long tmp)
{
	long long int	i;
	int				a;

	a = 1;
	i = tmp > 0x8000 ? (0xffff - tmp) + 1 : tmp;
	if (i != (long long)tmp)
		a = -1;
	return ((i * a + index) % MEM_SIZE);
}

static void		stock_ind(t_struck *s, unsigned long long *total,
	char *tmp, int *i)
{
	long long ind;

	total[i[0]] = str_to_int(tmp, 2);
	ind = set_mod(i[2], total[i[0]]) % IDX_MOD;
	if (ind < 0)
		ind = MEM_SIZE + ind;
	tmp[0] = s->map[(ind) % MEM_SIZE];
	tmp[1] = s->map[(ind + 1) % MEM_SIZE];
	tmp[2] = s->map[(ind + 2) % MEM_SIZE];
	tmp[3] = s->map[(ind + 3) % MEM_SIZE];
	total[i[0]] = str_to_int(tmp, 4);
}

void			stock_value(unsigned long long *total, t_pc *proc,
	t_struck *s, char nb_param)
{
	int		i[2];
	char	tmp[4];

	i[0] = -1;
	i[1] = 0;
	while (++i[0] < nb_param)
	{
		if (proc->type[i[0]] == 1)
			total[i[0]] = s->map[(proc->index + 2 + i[1]++) % MEM_SIZE];
		if (proc->type[i[0]] == 2 && (i[1] += 2))
		{
			tmp[0] = s->map[(proc->index + i[1]) % MEM_SIZE];
			tmp[1] = s->map[(proc->index + i[1] + 1) % MEM_SIZE];
			total[i[0]] = str_to_int(tmp, 2);
		}
		if (proc->type[i[0]] == 4)
		{
			tmp[0] = s->map[(proc->index + 2 + i[1]) % MEM_SIZE];
			tmp[1] = s->map[(proc->index + 2 + i[1] + 1) % MEM_SIZE];
			tmp[2] = s->map[(proc->index + 2 + i[1] + 2) % MEM_SIZE];
			tmp[3] = s->map[(proc->index + 2 + i[1] + 3) % MEM_SIZE];
			total[i[0]] = str_to_int(tmp, 4);
			i[1] += 4;
		}
	}
}

void			stock_value_dir(unsigned long long *total, t_pc *proc,
	t_struck *s, char nb_param)
{
	int		i[3];
	char	tmp[4];

	i[0] = -1;
	i[1] = 0;
	i[2] = proc->index;
	while (++i[0] < nb_param)
	{
		if (proc->type[i[0]] == 1)
			total[i[0]] = s->map[(proc->index + 2 + i[1]++) % MEM_SIZE];
		if ((proc->type[i[0]] == 2 || proc->type[i[0]] == 4) && (i[1] += 2))
		{
			tmp[0] = s->map[(proc->index + 2 + i[1]) % MEM_SIZE];
			tmp[1] = s->map[(proc->index + 2 + i[1] + 1) % MEM_SIZE];
			if (proc->type[i[0]] == 2)
				stock_ind(s, total, tmp, i);
			if (proc->type[i[0]] == 4 && (proc->type[i[0]] = 2))
				total[i[0]] = str_to_int(tmp, 2);
		}
	}
}

void			stock_value_ldir(unsigned long long *total, t_pc *proc,
	t_struck *s, char nb_param)
{
	int		i[3];
	char	tmp[4];

	i[0] = -1;
	i[1] = 0;
	i[2] = proc->index;
	while (++i[0] < nb_param)
	{
		if (proc->type[i[0]] == 1)
			total[i[0]] = s->map[(proc->index + 2 + i[1]++) % MEM_SIZE];
		if (proc->type[i[0]] == 2 || proc->type[i[0]] == 4)
		{
			tmp[0] = s->map[(proc->index + 2 + i[1]) % MEM_SIZE];
			tmp[1] = s->map[(proc->index + 2 + i[1] + 1) % MEM_SIZE];
			if (proc->type[i[0]] == 2)
				stock_ind(s, total, tmp, i);
			if (proc->type[i[0]] == 4)
			{
				proc->type[i[0]] = 2;
				total[i[0]] = str_to_int(tmp, 2);
			}
			i[1] += 2;
		}
	}
}
