/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_function_parttwo_next.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:43:02 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 09:21:58 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static unsigned long long	format_value(unsigned long long tmp,
	t_pc *proc, t_struck *s, char type)
{
	char	temp[REG_SIZE];
	int		i;

	if (type == 1)
		return (reg_to_hex(proc->reg[tmp - 1], REG_SIZE));
	else if (type == 2)
	{
		tmp = set_mod(proc->index, tmp);
		i = -1;
		while (++i < REG_SIZE)
			temp[i] = s->map[(tmp + i) % MEM_SIZE];
		return (str_to_int(temp, REG_SIZE));
	}
	return (tmp);
}

static void					stock_and_or_xor(t_struck *s, t_pc *proc)
{
	char no;

	ocp_value(s->map[proc->index + 1], proc->type);
	stock_value(proc->tmp, proc, s, 3);
	no = 1;
	if (proc->type[0] != 1 || (proc->type[0] == 1 &&
		REG_NUMBER >= proc->tmp[0] && proc->tmp[0] > 0))
		if (proc->type[1] != 1 || (proc->type[1] == 1
			&& REG_NUMBER >= proc->tmp[1] && proc->tmp[1] > 0))
			if (proc->type[2] == 1 &&
				REG_NUMBER >= proc->tmp[2] && proc->tmp[2] > 0)
			{
				proc->tmp[0] = format_value(proc->tmp[0],
					proc, s, proc->type[0]);
				proc->tmp[1] = format_value(proc->tmp[1],
					proc, s, proc->type[1]);
				no = 0;
			}
	proc->no = no;
}

void						op_and(t_struck *s, t_pc *proc, t_pc **first)
{
	int	i;
	int	car;

	if (!proc->cycle)
		set_cycle(s, proc, 6, first);
	else if (proc->cycle == 1)
	{
		stock_and_or_xor(s, proc);
		if (!proc->no)
		{
			car = 0;
			i = -1;
			while (++i < REG_SIZE)
				proc->reg[proc->tmp[2] - 1][i] =
			((proc->tmp[0] & proc->tmp[1]) >> i * 8) & 0xff;
			if (!str_to_int(proc->reg[proc->tmp[2] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		proc->no = 0;
		proc->index = (proc->index + move_ocp(proc->type, 3)) % MEM_SIZE;
	}
	--proc->cycle;
}

void						op_or(t_struck *s, t_pc *proc, t_pc **first)
{
	int	i;
	int	car;

	if (!proc->cycle)
		set_cycle(s, proc, 6, first);
	else if (proc->cycle == 1)
	{
		stock_and_or_xor(s, proc);
		if (!proc->no)
		{
			car = 0;
			i = -1;
			while (++i < REG_SIZE)
				proc->reg[proc->tmp[2] - 1][i] =
			((proc->tmp[0] | proc->tmp[1]) >> i * 8) & 0xff;
			if (!str_to_int(proc->reg[proc->tmp[2] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		proc->no = 0;
		proc->index = (proc->index + move_ocp(proc->type, 3)) % MEM_SIZE;
	}
	--proc->cycle;
}

void						op_xor(t_struck *s, t_pc *proc, t_pc **first)
{
	int	i;
	int	car;

	if (!proc->cycle)
		set_cycle(s, proc, 6, first);
	else if (proc->cycle == 1)
	{
		stock_and_or_xor(s, proc);
		car = 0;
		if (!proc->no)
		{
			i = -1;
			while (++i < REG_SIZE)
				proc->reg[proc->tmp[2] - 1][i] =
			((proc->tmp[0] ^ proc->tmp[1]) >> i * 8) & 0xff;
			if (!str_to_int(proc->reg[proc->tmp[2] - 1], REG_SIZE))
				car = 1;
			proc->carry = car;
		}
		proc->no = 0;
		proc->index = (proc->index + move_ocp(proc->type, 3)) % MEM_SIZE;
	}
	--proc->cycle;
}
