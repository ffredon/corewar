/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function_partone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 23:41:33 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 09:38:39 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void			stock_live(t_struck *s, t_pc *proc)
{
	char	tmp[4];

	tmp[0] = s->map[(proc->index + 1) % MEM_SIZE];
	tmp[1] = s->map[(proc->index + 2) % MEM_SIZE];
	tmp[2] = s->map[(proc->index + 3) % MEM_SIZE];
	tmp[3] = s->map[(proc->index + 4) % MEM_SIZE];
	proc->tmp[0] = str_to_int(tmp, 4);
}

void				op_live(t_struck *s, t_pc *proc, t_pc **first)
{
	int		i;

	if (!proc->cycle)
		set_cycle(s, proc, 10, first);
	else if (proc->cycle == 1)
	{
		stock_live(s, proc);
		i = -1;
		proc->live = -1;
		s->live++;
		while (++i < s->nb_chp)
			if ((int)s->chp[i].tmp[1] == (int)proc->tmp[0])
			{
				if (s->rep & AFF)
				{
					ft_printf("Un processus dit ");
					ft_printf("que le joueur %d ({CGREEN%s}) est en vie\n"
						, s->chp[i].tmp[1], s->chp[i].name);
				}
				s->chp[i].tmp[0]++;
				s->chp[i].last_live = s->cycle;
			}
		proc->index = (proc->index + 5) % MEM_SIZE;
	}
	--proc->cycle;
}

static void			stock_ld(t_struck *s, t_pc *proc)
{
	int					i;
	long long int		ind;
	char				temp[4];

	ocp_value(s->map[proc->index + 1], proc->type);
	stock_value(proc->tmp, proc, s, 2);
	proc->no = 1;
	if (proc->type[1] == 1 && proc->tmp[1] > 0 && proc->tmp[1] < REG_NUMBER + 1)
	{
		if (proc->type[0] == 4)
			proc->no = 0;
		else if (proc->type[0] == 2)
		{
			ind = set_mod(proc->index, proc->tmp[0]);
			if ((int)ind < 0)
				ind = MEM_SIZE + ind;
			i = -1;
			while (++i < REG_SIZE)
				temp[i] = (s->map[(ind + REG_SIZE - 1 - i) % MEM_SIZE]);
			ft_memcpy(&proc->tmp[0], temp, REG_SIZE);
			proc->no = 0;
		}
	}
}

void				op_ld(t_struck *s, t_pc *proc, t_pc **first)
{
	int					car;

	if (!proc->cycle)
		set_cycle(s, proc, 5, first);
	else if (proc->cycle == 1)
	{
		stock_ld(s, proc);
		if (!proc->no)
		{
			car = 0;
			ft_memcpy(proc->reg[proc->tmp[1] - 1], &proc->tmp[0], REG_SIZE);
			if (!str_to_int(proc->reg[proc->tmp[1] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		proc->no = 0;
		proc->index = (proc->index + move_ocp(proc->type, 2)) % MEM_SIZE;
		ft_memset(proc->type, 0, 3);
	}
	--proc->cycle;
}

long long			reg_to_hex(char *str, int size)
{
	char	c;
	char	temp[size];
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	ft_memcpy(temp, str, size);
	while (i < j)
	{
		c = temp[j];
		temp[j] = temp[i];
		temp[i] = c;
		i++;
		j--;
	}
	return (str_to_int(temp, size));
}
