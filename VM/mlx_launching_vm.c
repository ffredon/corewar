/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_launching_vm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:03:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 09:19:17 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

static void	launching_vm_g_sub(t_struck *s, t_op *op, int *final_cycles,
							int *current_cycles)
{
	while (*current_cycles < *final_cycles && !s->max)
	{
		s->cycle++;
		(*current_cycles)++;
		s->nb_proc = 0;
		running_vm(s, s->pro, op);
		if (s->cycle % s->turn == 0)
			break ;
	}
	if (*current_cycles >= *final_cycles)
	{
		kill_process(s->pro, s);
		check_vm(s, final_cycles, current_cycles);
	}
}

void		launching_vm_g(t_struck *s)
{
	static int	final_cycles = CYCLE_TO_DIE;
	static int	current_cycles = 0;
	t_op		op[16];

	init_struck_op(op);
	while (final_cycles > 0 && !s->max)
	{
		launching_vm_g_sub(s, op, &final_cycles, &current_cycles);
		if (s->cycle % s->turn == 0)
			break ;
	}
	if (final_cycles <= 0)
	{
		if (s->nb_proc)
			kill_process_end(s->pro, s);
		s->max = 1;
		s->nb_proc = 0;
	}
}
