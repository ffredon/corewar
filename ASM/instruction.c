/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 19:57:00 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 20:14:52 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

int		instruction_gen_ocp(t_inst *inst)
{
	t_param	*params;
	int		ocp;
	int		decalage;

	decalage = 8;
	ocp = 0;
	params = inst->params;
	while (params)
	{
		ocp = (ocp | (toc(params->type) << (decalage -= 2)));
		params = params->next;
	}
	return (ocp);
}

int		instruction_type(char *str)
{
	int	i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if ((ft_strncmp(g_op_tab[i].name, str,
			ft_strlen(g_op_tab[i].name)) == 0) &&
			str[ft_strlen(g_op_tab[i].name)] == ' ')
			return (i);
		i++;
	}
	return (-1);
}

int		sizebetweeninst(int start, int end, t_inst *ops)
{
	t_inst	*tmp;
	int		i;
	int		total;

	total = 0;
	tmp = ops;
	i = 0;
	while (tmp)
	{
		if (i >= start && i < end)
			total += tmp->size;
		tmp = tmp->next;
		i++;
	}
	return (total);
}
