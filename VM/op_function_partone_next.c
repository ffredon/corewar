/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function_partone_next.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:25:11 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/24 21:26:16 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void			stock_add_sub(t_struck *s, t_pc *proc, char c)
{
	ocp_value(s->map[proc->index + 1], proc->type);
	proc->no = 1;
	if (proc->type[0] == 1 && proc->type[1] == 1 && proc->type[2] == 1)
	{
		if (REG_NUMBER >= s->map[(IND + 2)] && s->map[(IND + 2)] > 0 &&
			REG_NUMBER >= s->map[(IND + 3)] && s->map[(IND + 3)] > 0 &&
			REG_NUMBER >= s->map[(IND + 4)] && s->map[(IND + 4)] > 0)
		{
			if (!c)
				proc->tmp[0] = reg_to_hex(proc->reg[(s->map[(IND + 2)] - 1) %
					MEM_SIZE], REG_SIZE) +
			reg_to_hex(proc->reg[(s->map[(IND + 3)] - 1)
				% MEM_SIZE], REG_SIZE);
			else
				proc->tmp[0] = reg_to_hex(proc->reg[(s->map[(IND + 2)] - 1) %
					MEM_SIZE], REG_SIZE) -
			reg_to_hex(proc->reg[(s->map[(IND + 3)] - 1) % MEM_SIZE], REG_SIZE);
			proc->tmp[2] = s->map[(IND + 4) % MEM_SIZE];
			proc->no = 0;
		}
	}
}

void				op_add(t_struck *s, t_pc *proc, t_pc **first)
{
	int					i;
	int					car;

	if (!proc->cycle)
		set_cycle(s, proc, 10, first);
	else if (proc->cycle == 1)
	{
		stock_add_sub(s, proc, 0);
		if (!proc->no)
		{
			car = 0;
			i = -1;
			while (++i < REG_SIZE)
			{
				proc->reg[proc->tmp[2] - 1][i] = proc->tmp[0] & 0xff;
				proc->tmp[0] = proc->tmp[0] >> 8;
			}
			if (!str_to_int(proc->reg[proc->tmp[2] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		proc->index = (proc->index + move_ocp(proc->type, 3)) % MEM_SIZE;
		ft_memset(proc->type, 0, 3);
	}
	proc->cycle--;
}

void				op_sub(t_struck *s, t_pc *proc, t_pc **first)
{
	int					i;
	int					car;

	if (!proc->cycle)
		set_cycle(s, proc, 10, first);
	else if (proc->cycle == 1)
	{
		stock_add_sub(s, proc, 1);
		if (!proc->no)
		{
			car = 0;
			i = -1;
			while (++i < REG_SIZE)
			{
				proc->reg[proc->tmp[2] - 1][i] = proc->tmp[0] & 0xff;
				proc->tmp[0] = proc->tmp[0] >> 8;
			}
			if (!str_to_int(proc->reg[proc->tmp[2] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		proc->index = (proc->index + move_ocp(proc->type, 3)) % MEM_SIZE;
		ft_memset(proc->type, 0, 3);
	}
	proc->cycle--;
}

static void			stock_st(t_struck *s, t_pc *proc)
{
	ocp_value(s->map[proc->index + 1], proc->type);
	stock_value(proc->tmp, proc, s, 2);
	proc->no = 0;
	if (proc->type[0] == 1 && proc->tmp[0] > 0 && proc->tmp[0] < REG_NUMBER + 1)
	{
		if (proc->type[1] == 1 && proc->tmp[1] > 0
			&& proc->tmp[1] < REG_NUMBER + 1)
			ft_memcpy(proc->reg[proc->tmp[1] - 1],
				proc->reg[proc->tmp[0] - 1], REG_SIZE);
		else if (proc->type[1] == 2)
			;
		else
			proc->no = 1;
	}
	else
		proc->no = 1;
}

void				op_st(t_struck *s, t_pc *proc, t_pc **first)
{
	long long			ind;
	int					i;

	if (!proc->cycle)
		set_cycle(s, proc, 5, first);
	else if (proc->cycle == 1)
	{
		stock_st(s, proc);
		if (!proc->no)
			if (proc->type[1] == 2)
			{
				ind = set_mod(proc->index, proc->tmp[1]);
				if (ind < 0)
					ind = MEM_SIZE + ind;
				i = -1;
				while (++i < REG_SIZE)
				{
					s->map[(ind + i) % MEM_SIZE] =
					(proc->reg[proc->tmp[0] - 1][REG_SIZE - 1 - i] & 0xff);
					s->col_chp[(ind + i) % MEM_SIZE] = proc->chp;
				}
			}
		proc->index = (proc->index + move_ocp(proc->type, 2)) % MEM_SIZE;
	}
	--proc->cycle;
}
