/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 22:07:42 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 14:13:10 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void	running_vm_next(t_struck *s)
{
	if (!(s->rep & GRAPH) && (s->rep & DUMP) && s->cycle % s->turn_dump == 0)
	{
		system("clear");
		print_map(s, 0);
		ft_printf("Cycle = %d proc = %d\n", s->cycle, s->nb_proc);
		usleep(210000);
	}
	if (s->dump > 0 && s->cycle && s->cycle % s->dump == 0)
	{
		print_map_dump(s);
		exit(1);
	}
	if (!s->nb_proc && !(s->rep & GRAPH))
	{
		print_final(s);
		exit(1);
	}
	if ((s->rep & GRAPH) && !s->nb_proc)
		s->max = 1;
}

static void	running_inside(t_struck *s,
	t_pc *tmp, t_op *op, t_pc **proc)
{
	int		i;

	i = -1;
	while (++i < 16)
		if (op[i].c == s->map[tmp->index])
		{
			op[i].do_op(s, tmp, proc);
			break ;
		}
	if (i >= 16 && ++tmp->index)
		if (tmp->index >= 4096)
			tmp->index = tmp->index % MEM_SIZE;
}

void		running_vm(t_struck *s, t_pc **proc, t_op *op)
{
	t_pc	*tmp;

	tmp = *proc;
	ft_bzero(s->proc_test, MEM_SIZE);
	s->nb_proc = 0;
	while (tmp && ++s->nb_proc)
	{
		if (tmp->cycle > 1)
			--tmp->cycle;
		else
		{
			if (tmp->cycle == 1)
				op[tmp->instruc - 1].do_op(s, tmp, proc);
			else
				running_inside(s, tmp, op, proc);
		}
		s->proc_test[tmp->index] = tmp->chp;
		tmp = tmp->next;
	}
	running_vm_next(s);
}

void		check_vm(t_struck *s, int *final_cycles,
	int *current_cycles)
{
	if (s->live < NBR_LIVE)
	{
		++s->check;
		++s->img.check;
		if (s->check >= MAX_CHECKS)
		{
			*final_cycles -= CYCLE_DELTA;
			s->img.cycle_to_die -= CYCLE_DELTA;
			s->img.check = 0;
			s->check = 0;
		}
	}
	else
	{
		*final_cycles -= CYCLE_DELTA;
		s->check = 0;
		s->img.check = 0;
		s->img.cycle_to_die -= CYCLE_DELTA;
	}
	*current_cycles = 0;
	s->live = 0;
}

void		launching_vm(t_struck *s)
{
	int		final_cycles;
	int		current_cycles;
	t_op	op[16];

	final_cycles = CYCLE_TO_DIE;
	current_cycles = 0;
	s->cycle = 0;
	init_struck_op(op);
	while (final_cycles > 0)
	{
		while (current_cycles < final_cycles)
		{
			s->cycle++;
			current_cycles++;
			running_vm(s, s->pro, op);
		}
		kill_process(s->pro, s);
		check_vm(s, &final_cycles, &current_cycles);
	}
	print_final(s);
	if (s->nb_proc)
		kill_process_end(s->pro, s);
}
