/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_gen_fcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:17:40 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/24 21:26:44 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_box.h"

long long int		set_mod(int index, long long tmp)
{
	long long int	i;
	int				a;

	a = 1;
	i = tmp > 0x8000 ? (0xffff - tmp) + 1 : tmp;
	if (i != tmp)
		a = -1;
	return (((i * a % IDX_MOD) + index) % MEM_SIZE);
}

unsigned long long	str_to_int(void *s, int len)
{
	int						i;
	int						a;
	unsigned long long int	j;
	unsigned long long int	nb;
	char					*str;

	i = 0;
	j = 0;
	nb = 0;
	a = 2;
	str = (char *)s;
	while (i < len)
	{
		j = (len * 2 - a) ? (pow(16, len * 2 - a)) : 1;
		nb = nb + (str[i] & 0xf0) * j + (str[i] & 0x0f) * j;
		++i;
		a += 2;
	}
	return (nb);
}

void				set_cycle(t_struck *s, t_pc *proc, int cycle, t_pc **first)
{
	(void)first;
	proc->cycle = cycle;
	proc->instruc = s->map[proc->index];
}

void				ocp_value(char c, char *type)
{
	if (((c >> 6) & 0b11) == 0b1)
		type[0] = 1;
	else if (((c >> 6) & 0b11) == 0b11)
		type[0] = 2;
	else if (((c >> 6) & 0b11) == 0b10)
		type[0] = 4;
	else
		type[0] = 0;
	if (((c >> 4) & 0b11) == 0b1)
		type[1] = 1;
	else if (((c >> 4) & 0b11) == 0b11)
		type[1] = 2;
	else if (((c >> 4) & 0b11) == 0b10)
		type[1] = 4;
	else
		type[1] = 0;
	if (((c >> 2) & 0b11) == 0b1)
		type[2] = 1;
	else if (((c >> 2) & 0b11) == 0b11)
		type[2] = 2;
	else if (((c >> 2) & 0b11) == 0b10)
		type[2] = 4;
	else
		type[2] = 0;
}

int					move_ocp(char *type, char nb_param)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (i < (int)nb_param)
	{
		index += (int)type[i];
		++i;
	}
	ft_memset(type, 0, 3);
	return (index + 2);
}
