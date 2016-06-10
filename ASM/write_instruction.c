/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 13:42:40 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 22:39:04 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

void	write_instruction_opcode(int fd, t_inst *inst)
{
	write_to_hexa(fd, g_op_tab[inst->type].opcode, 1);
}

void	write_instruction_ocp(int fd, t_inst *inst)
{
	if (instruction_gen_ocp(inst) != 0x80)
		write_to_hexa(fd, instruction_gen_ocp(inst), 1);
}

void	write_instruction_params(int fd, t_hero *hero, t_inst *inst, int line)
{
	t_param	*params;
	int		val;

	params = inst->params;
	while (params)
	{
		if (params->type == T_REG)
			val = ft_atoi(&params->str[1]);
		if (params->type == T_IND)
			val = t_ind_val(params, line, hero);
		if (params->type == T_DIR)
			val = t_dir_val(params, line, hero);
		write_to_hexa(fd, val, tosize(params->type, inst->type));
		params = params->next;
	}
}

void	write_instruction(int fd, t_hero *hero, t_inst *inst, int line)
{
	write_instruction_opcode(fd, inst);
	write_instruction_ocp(fd, inst);
	write_instruction_params(fd, hero, inst, line);
}
