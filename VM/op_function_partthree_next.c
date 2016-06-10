/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function_partthree_next.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:56:23 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/24 21:57:10 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void			stock_lldi(t_struck *s, t_pc *proc)
{
	ocp_value(s->map[proc->index + 1], TYP);
	stock_value_ldir(TMP, proc, s, 3);
	proc->no = 1;
	if (TYP[0] != 1 || (TYP[0] == 1 && REG_NUMBER >= TMP[0] && TMP[0] > 0))
		if (TYP[1] != 1 || (TYP[1] == 1 && REG_NUMBER >= TMP[1] && TMP[1] > 0))
			if (TYP[2] == 1 && REG_NUMBER >= TMP[2] && TMP[2] > 0)
			{
				if (TYP[0] == 1)
					TMP[0] = reg_to_hex(proc->reg[TMP[0] - 1], REG_SIZE);
				if (TYP[1] == 1)
					TMP[1] = reg_to_hex(proc->reg[TMP[1] - 1], REG_SIZE);
				TMP[0] = set_lmod(proc->index, TMP[1] + TMP[0]);
				proc->no = 0;
			}
}

void				op_lldi(t_struck *s, t_pc *proc, t_pc **first)
{
	int car;
	int i;

	if (!proc->cycle)
		set_cycle(s, proc, 50, first);
	else if (proc->cycle == 1)
	{
		stock_lldi(s, proc);
		if (!proc->no)
		{
			car = 0;
			i = -1;
			while (++i < REG_SIZE)
				REG[TMP[2] - 1][i] =
			s->map[(TMP[0] + REG_SIZE - 1 - i) % MEM_SIZE];
			if (!str_to_int(proc->reg[TMP[2] - 1], 4))
				car = 1;
			proc->carry = car;
		}
		proc->no = 0;
		proc->index = (proc->index + move_ocp(TYP, 3)) % MEM_SIZE;
		ft_memset(TYP, 0, 3);
	}
	--proc->cycle;
}

static void			stock_fork_lfork(t_struck *s, t_pc *proc, char c)
{
	char	tmp[2];

	tmp[0] = s->map[(proc->index + 1) % MEM_SIZE];
	tmp[1] = s->map[(proc->index + 2) % MEM_SIZE];
	if (!c)
		TMP[0] = (int)str_to_int(tmp, 2) + proc->index;
	else
		TMP[0] = (int)set_mod(proc->index, (int)str_to_int(tmp, 2));
}

void				op_lfork(t_struck *s, t_pc *proc, t_pc **first)
{
	if (!proc->cycle)
	{
		proc->cycle = 1000;
		proc->instruc = s->map[proc->index];
	}
	else if (proc->cycle == 1)
	{
		stock_fork_lfork(s, proc, 0);
		ft_pcadd(&first, ft_pcnew(proc, TMP[0] % MEM_SIZE));
		proc->index = (proc->index + 3) % MEM_SIZE;
	}
	--proc->cycle;
}

void				op_fork(t_struck *s, t_pc *proc, t_pc **first)
{
	if (!proc->cycle)
	{
		proc->cycle = 800;
		proc->instruc = s->map[proc->index];
	}
	else if (proc->cycle == 1)
	{
		stock_fork_lfork(s, proc, 1);
		ft_pcadd(&first, ft_pcnew(proc, TMP[0] % MEM_SIZE));
		proc->index = (proc->index + 3) % MEM_SIZE;
	}
	--proc->cycle;
}
