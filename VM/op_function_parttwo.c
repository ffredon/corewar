/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function_parttwo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 23:41:40 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/24 21:44:32 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void			stock_zjmp(t_struck *s, t_pc *proc)
{
	char tmp[2];

	if (proc->carry == 1)
	{
		tmp[0] = s->map[(proc->index + 1) % MEM_SIZE];
		tmp[1] = s->map[(proc->index + 2) % MEM_SIZE];
		proc->index = set_mod(proc->index, str_to_int(tmp, 2)) % MEM_SIZE;
		if (proc->index < 0)
			proc->index = MEM_SIZE + proc->index;
	}
	else
		proc->index = (proc->index + 3) % MEM_SIZE;
}

void				op_zjump(t_struck *s, t_pc *proc, t_pc **first)
{
	if (!proc->cycle)
		set_cycle(s, proc, 20, first);
	else if (proc->cycle == 1)
		stock_zjmp(s, proc);
	--proc->cycle;
}

static void			stock_ldi(t_struck *s, t_pc *proc)
{
	long long	ind;
	int			i;

	if (TYP[0] != 1 || (TYP[0] == 1 && REG_NUMBER >= TMP[0] && TMP[0] > 0))
		if (TYP[1] != 1 || (TYP[1] == 1 && REG_NUMBER >= TMP[1] && TMP[1] > 0))
			if (TYP[2] == 1 && REG_NUMBER >= TMP[2] && TMP[2] > 0)
			{
				if (TYP[0] == 1)
					TMP[0] = reg_to_hex(proc->reg[TMP[0] - 1], REG_SIZE);
				if (TYP[1] == 1)
					TMP[1] = reg_to_hex(proc->reg[TMP[1] - 1], REG_SIZE);
				ind = set_mod(proc->index, (TMP[0] + TMP[1]));
				if (ind < 0)
					ind = MEM_SIZE + ind;
				i = -1;
				while (++i < REG_SIZE)
					proc->reg[TMP[2] - 1][i] =
				s->map[(ind + REG_SIZE - 1 - i) % MEM_SIZE];
			}
}

void				op_ldi(t_struck *s, t_pc *proc, t_pc **first)
{
	if (!proc->cycle)
		set_cycle(s, proc, 25, first);
	else if (proc->cycle == 1)
	{
		ocp_value(s->map[proc->index + 1], proc->type);
		stock_value_dir(proc->tmp, proc, s, 3);
		stock_ldi(s, proc);
		proc->index = (proc->index + move_ocp(proc->type, 3)) % MEM_SIZE;
	}
	--proc->cycle;
}
