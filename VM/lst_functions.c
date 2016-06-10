/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:59:21 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 10:28:32 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

t_pc	*ft_pcnew(t_pc *father, long long int index_value)
{
	t_pc	*new;
	int		i;

	(!(new = (t_pc*)ft_memalloc(sizeof(t_pc)))) ? cor_err(4, NULL) : 1;
	new->index = index_value % MEM_SIZE;
	if (new->index < 0)
		new->index = MEM_SIZE + new->index;
	new->cycle = 0;
	new->chp = father->chp;
	new->live = 0;
	new->live = father->live;
	new->carry = father->carry;
	new->instruc = 0;
	new->no = 0;
	i = -1;
	ft_bzero(new->tmp, 3);
	while (++i < REG_NUMBER)
		ft_memcpy(new->reg[i], father->reg[i], REG_SIZE);
	return (new);
}

void	ft_pcadd(t_pc ***pclist, t_pc *new)
{
	if (**pclist)
	{
		new->next = **pclist;
		**pclist = new;
	}
	else
		**pclist = new;
}

void	kill_process(t_pc **first, t_struck *s)
{
	t_pc	**tmp;
	t_pc	*temp;
	int		i;

	tmp = first;
	while (*tmp)
	{
		if (!(*tmp)->live)
		{
			if ((s->rep & GRAPH))
				enable_shoot(s);
			--s->nb_proc;
			temp = (*tmp)->next;
			free(*tmp);
			*tmp = temp;
		}
		else
		{
			(*tmp)->live = 0;
			tmp = &(*tmp)->next;
		}
	}
	i = -1;
	while (++i < s->nb_chp)
		s->chp[i].tmp[0] = 0;
}

void	kill_process_end(t_pc **first, t_struck *s)
{
	t_pc	**tmp;
	t_pc	*temp;

	tmp = first;
	(void)s;
	while (*tmp)
	{
		temp = (*tmp)->next;
		free(*tmp);
		*tmp = temp;
	}
}
