/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_vm_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:58:43 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 09:13:13 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

void				op_aff(t_struck *s, t_pc *proc, t_pc **first)
{
	unsigned long long tmp;

	if (!proc->cycle)
		set_cycle(s, proc, 2, first);
	else if (proc->cycle == 1)
	{
		ocp_value(s->map[proc->index + 1], proc->type);
		if (proc->type[0] == 1 && s->map[proc->index + 2] > 0
			&& s->map[proc->index + 2] <= REG_NUMBER)
		{
			tmp = reg_to_hex(proc->reg[s->map[proc->index + 2] - 1], REG_SIZE);
			if (ft_isascii(tmp) && (s->rep & AFF))
				ft_printf("Aff: %c\n", tmp);
		}
		proc->index = (proc->index + move_ocp(proc->type, 1)) % MEM_SIZE;
		ft_memset(proc->type, 0, 3);
		if (proc->index >= MEM_SIZE)
			proc->index = proc->index % MEM_SIZE;
	}
	--proc->cycle;
}

void				init_struck_op(t_op *op)
{
	int i;

	i = -1;
	while (++i < 16)
		op[i].c = i + 1;
	op[0].do_op = op_live;
	op[1].do_op = op_ld;
	op[2].do_op = op_st;
	op[3].do_op = op_add;
	op[4].do_op = op_sub;
	op[5].do_op = op_and;
	op[6].do_op = op_or;
	op[7].do_op = op_xor;
	op[8].do_op = op_zjump;
	op[9].do_op = op_ldi;
	op[10].do_op = op_sti;
	op[11].do_op = op_fork;
	op[12].do_op = op_lld;
	op[13].do_op = op_lldi;
	op[14].do_op = op_lfork;
	op[15].do_op = op_aff;
}

void				print_final(t_struck *s)
{
	int i;
	int j;
	int k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < s->nb_chp)
	{
		ft_printf("Champion {CGREEN%s} was last seen alive at {CRED%d}\n",
			s->chp[i].name, s->chp[i].last_live);
		if (j < s->chp[i].last_live)
		{
			k = i;
			j = s->chp[i].last_live;
		}
	}
	ft_printf("Contestant %d (%d), \"%s\", has won ! \n", k + 1,
		s->chp[k].tmp[1], s->chp[k].name);
}
