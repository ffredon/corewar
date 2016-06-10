/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_instruction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:45:38 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 12:14:35 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

t_inst	*new_instruction(char *str)
{
	t_inst	*inst;
	char	**tab;
	int		i;

	ft_strrepchr(str, '\t', ' ');
	inst = ft_memalloc(sizeof(t_inst));
	inst->str = ft_strdup(str);
	inst->type = instruction_type(str);
	if (inst->type == -1)
		return (NULL);
	inst->params = NULL;
	inst->size = 0;
	inst->next = NULL;
	tab = ft_strsplit(ft_strchr(str, ' '), SEPARATOR_CHAR);
	i = -1;
	if (tab && ft_tablen(tab) > 0)
		while (tab[++i])
			inst->params = add_param(&inst->params, new_param(tab[i]));
	else
		asm_error("instruction error, no param", str);
	ft_tabfree(tab);
	return (inst);
}

t_inst	*add_instruction(t_inst **lst, t_inst *new)
{
	t_inst *param;

	param = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (param->next)
			param = param->next;
		param->next = new;
	}
	return (*lst);
}

void	free_instruction(t_inst *inst)
{
	t_param *param;
	t_param *nextparam;

	ft_strdel(&inst->str);
	param = inst->params;
	while (param)
	{
		nextparam = param->next;
		ft_strdel(&param->str);
		free(param);
		param = nextparam;
	}
}

int		size_instruction(t_inst *inst)
{
	t_param	*param;

	inst->size = 1;
	if (g_op_tab[inst->type].ocp)
		inst->size = 2;
	param = inst->params;
	while (param)
	{
		if (param->type == T_REG)
			inst->size += 1;
		else if (param->type == T_IND)
			inst->size += IND_SIZE;
		else if (param->type == T_DIR)
		{
			if (g_op_tab[inst->type].truc)
				inst->size += IND_SIZE;
			else
				inst->size += DIR_SIZE;
		}
		param = param->next;
	}
	return (inst->size);
}

void	check_instruction(t_inst *inst, t_hero *hero)
{
	int		i;
	t_param	*param;

	i = 0;
	if ((g_op_tab[inst->type].nb_params - 1) !=
		ft_strcountchr(inst->str, SEPARATOR_CHAR))
		asm_error("Wrong number of argument", inst->str);
	param = inst->params;
	while (param)
	{
		if (!param->type)
			error_type_param(inst, param, i);
		if (param->type == T_DIR && param->str[1] == LABEL_CHAR)
			check_label_exist(hero, &param->str[2]);
		if (param->type == T_IND && param->str[0] == LABEL_CHAR)
			check_label_exist(hero, &param->str[1]);
		if (!((param->type & g_op_tab[inst->type].param_types[i])
			== param->type))
			error_inst_param(inst, param, i);
		i++;
		param = param->next;
	}
}
