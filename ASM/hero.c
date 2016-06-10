/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 06:30:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 13:25:13 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

t_hero	*read_hero(char *file)
{
	t_hero	*hero;
	int		j;

	j = 0;
	hero = (t_hero*)malloc(sizeof(t_hero));
	hero_header(hero, file, &j);
	hero->opts = readops(file + j);
	split_op_label(hero);
	if (ft_tablen(hero->opts) + ft_tablen(hero->label_name) == 0)
		asm_error("empty champion", "");
	hero_gen_ops(hero);
	hero_check_ops(hero);
	hero_size_ops(hero);
	ft_strdel(&file);
	return (hero);
}

void	free_hero(t_hero *hero)
{
	t_inst	*inst;
	t_inst	*tmp;

	ft_strdel(&hero->name);
	ft_strdel(&hero->comment);
	inst = hero->inst;
	ft_tabfree(hero->opts);
	ft_tabfree(hero->label_name);
	free(hero->label_pos);
	while (inst)
	{
		tmp = inst->next;
		free_instruction(inst);
		free(inst);
		inst = tmp;
	}
	free(hero);
}

void	hero_gen_ops(t_hero *hero)
{
	int		i;
	t_inst	*inst;

	i = 0;
	hero->inst = NULL;
	while (hero->opts[i])
	{
		inst = new_instruction(hero->opts[i]);
		if (!inst)
		{
			ft_printf("invalide op:%s", hero->opts[i]);
			exit(0);
		}
		hero->inst = add_instruction(&hero->inst, inst);
		i++;
	}
}

void	hero_check_ops(t_hero *hero)
{
	t_inst *inst;

	inst = hero->inst;
	while (inst)
	{
		check_instruction(inst, hero);
		inst = inst->next;
	}
}

void	hero_size_ops(t_hero *hero)
{
	t_inst *inst;

	inst = hero->inst;
	while (inst)
	{
		hero->size_inst += size_instruction(inst);
		inst = inst->next;
	}
}
