/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function_partthree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 23:41:43 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 04:02:45 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static long long	ft_value(long long int tmp)
{
	long long	i;
	int			a;

	a = 1;
	i = tmp > 0x8000 ? (0xffff - tmp) + 1 : tmp;
	if (i != tmp)
		a = -1;
	return ((i % IDX_MOD) % MEM_SIZE * a);
}

static void			stock_sti(t_struck *s, t_pc *proc, long long ind)
{
	int i;

	if (TYP[2] != 1 || (TYP[2] == 1 && REG_NUMBER >= TMP[2] && TMP[2] > 0))
		if (TYP[1] != 1 || (TYP[1] == 1 && REG_NUMBER >= TMP[1] && TMP[1] > 0))
			if (TYP[0] == 1 && REG_NUMBER >= TMP[0] && TMP[0] > 0)
			{
				if (TYP[1] == 1)
					TMP[1] = reg_to_hex(proc->reg[TMP[1] - 1], REG_SIZE);
				if (TYP[2] == 1)
					TMP[2] = reg_to_hex(proc->reg[TMP[2] - 1], REG_SIZE);
				ind = ft_value((int)TMP[1] + (int)TMP[2]);
				ind = ind + proc->index;
				if ((int)ind < 0)
					ind = MEM_SIZE + ind;
				ind %= MEM_SIZE;
				i = -1;
				while (++i < REG_SIZE)
				{
					s->map[(ind + i) % MEM_SIZE] =
					proc->reg[TMP[0] - 1][REG_SIZE - 1 - i];
					s->col_chp[(ind + i) % MEM_SIZE] = proc->chp;
				}
			}
}

void				op_sti(t_struck *s, t_pc *proc, t_pc **first)
{
	if (!proc->cycle)
		set_cycle(s, proc, 25, first);
	else if (proc->cycle == 1)
	{
		ocp_value(s->map[proc->index + 1], TYP);
		stock_value_ldir(TMP, proc, s, 3);
		stock_sti(s, proc, 0);
		proc->index = (proc->index + move_ocp(TYP, 3)) % MEM_SIZE;
	}
	--proc->cycle;
}

static void			stock_lld(t_struck *s, t_pc *proc, int car)
{
	if ((TYP[0] == 2 || TYP[0] == 4) && TYP[1] == 1 && TMP[1]
		> 0 && TMP[1] < REG_NUMBER + 1)
	{
		if (TYP[0] == 4)
		{
			REG[TMP[1] - 1][3] = (TMP[0] & 0xff000000) >> 24;
			REG[TMP[1] - 1][2] = (TMP[0] & 0x00ff0000) >> 16;
			REG[TMP[1] - 1][1] = (TMP[0] & 0x0000ff00) >> 8;
			REG[TMP[1] - 1][0] = TMP[0] & 0x000000ff;
			if (!str_to_int(REG[TMP[1] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		if (TYP[0] == 2)
		{
			REG[TMP[1] - 1][0] = s->map[(IND + TMP[0]) % MEM_SIZE];
			REG[TMP[1] - 1][1] = s->map[(IND + TMP[0] + 1) % MEM_SIZE];
			REG[TMP[1] - 1][2] = (REG[TMP[1] - 1][0] & 0xf) ? 0xff : 0;
			REG[TMP[1] - 1][3] = (REG[TMP[1] - 1][0] & 0xf) ? 0xff : 0;
			if (!str_to_int(proc->reg[TMP[1] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
	}
}

void				op_lld(t_struck *s, t_pc *proc, t_pc **first)
{
	if (!proc->cycle)
		set_cycle(s, proc, 10, first);
	else if (proc->cycle == 1)
	{
		ocp_value(s->map[proc->index + 1], TYP);
		stock_value(TMP, proc, s, 2);
		stock_lld(s, proc, 0);
		proc->index = (proc->index + move_ocp(TYP, 2)) % MEM_SIZE;
	}
	proc->cycle--;
}
