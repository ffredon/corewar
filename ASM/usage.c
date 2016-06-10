/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:05:48 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 03:06:10 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

void	usage(void)
{
	ft_printf("{red}Usage: ./asm <file1.s> <file2.s> <file*.s>{eoc}\n");
	ft_printf("{yellow}Options : -v Verbose mode\n");
	ft_printf("          -u Generate .mor (unittest.sh){eoc}\n");
}

void	debug_hero(t_hero *hero)
{
	int		i;
	t_inst	*tmp;

	ft_dprintf(2, "\nname :{red}%s{eoc}\ncomment:{green}%s{eoc}\n",
	hero->name, hero->comment);
	ft_dprintf(2, "\n%-20s %-7s %-5s %-5s %-10s\n",
	"Instructions", "Length", "Opcode", "Ocp", "Parameters");
	i = 0;
	tmp = hero->inst;
	while (tmp)
	{
		if (get_label_by_pos(hero, i))
			ft_printf("\n{green}%s:{eoc}", get_label_by_pos(hero, i));
		print_instruction_params(hero, tmp, i);
		i++;
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_instruction_params(t_hero *hero, t_inst *inst, int line)
{
	t_param	*params;
	int		val;

	ft_printf("\n{red}%-20s{eoc} {%d}     ", inst->str, inst->size);
	params = inst->params;
	ft_printf("[{cyan}{bold}%#.2x{eoc}][{cyan}{bold}%#.2x{eoc}]",
	g_op_tab[inst->type].opcode, instruction_gen_ocp(inst));
	while (params)
	{
		if (params->type == T_REG)
			val = ft_atoi(&params->str[1]);
		if (params->type == T_IND)
			val = t_ind_val(params, line, hero);
		if (params->type == T_DIR)
			val = t_dir_val(params, line, hero);
		ft_printf(
		" %-8s [{cyan}{bold}%#-10.*x{eoc}] ",
		code_to_type(params->type),
		tosize(params->type, inst->type) * 2,
		val);
		params = params->next;
	}
}
