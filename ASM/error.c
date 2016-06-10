/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:53:34 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 12:51:10 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op	g_op_tab[17];

void	asm_error(char *cause, char *str)
{
	ft_dprintf(2, "%s {red}%s{eoc}\n", cause, str);
	exit(0);
}

void	error_type_param(t_inst *inst, t_param *param, int i)
{
	ft_dprintf(2, "{red}Unknown param type for line : {bold}%s{eoc}\n",
	inst->str);
	ft_dprintf(2, "Param [%d] : {green}%s{eoc} ?\n",
	i + 1,
	param->str);
	exit(0);
}

void	error_size(int type, char *str)
{
	if (type == 0)
	{
		ft_dprintf(2, "{red}Champion name length too long{eoc}\n(%d) max %d\n",
		ft_strlen(str),
		PROG_NAME_LENGTH);
	}
	else
	{
		ft_dprintf(2,
			"{red}Champion comment length too long{eoc}\n(%d) max %d\n",
		ft_strlen(str),
		COMMENT_LENGTH);
	}
	exit(0);
}

char	*code_to_type(int type)
{
	if (type == T_REG)
		return ("Register");
	if (type == T_DIR)
		return ("Direct");
	if (type == T_IND)
		return ("Indirect");
	return (NULL);
}

void	error_inst_param(t_inst *inst, t_param *param, int i)
{
	ft_dprintf(2, "{red}Invalid param type for line : {bold}%s{eoc}\n",
	inst->str);
	ft_dprintf(2, "param [%d] : {red}%s{eoc} is %s\n",
	i + 1,
	param->str,
	code_to_type(param->type));
	exit(0);
}
