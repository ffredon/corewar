/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 13:55:21 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 15:19:58 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_param	*new_param(char *str)
{
	t_param	*param;

	param = ft_memalloc(sizeof(t_param));
	param->str = ft_strtrim(str);
	param->type = param_type(param->str);
	param->next = NULL;
	return (param);
}

t_param	*add_param(t_param **lst, t_param *new)
{
	t_param *param;

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

int		param_type(char *param)
{
	if (param[0] == 'r')
	{
		if (ft_streachr(&param[1], &ft_isdigit) == 1 &&
			ft_strlen(param) > 1 && ft_strlen(param) < 4)
			return (T_REG);
	}
	else if (param[0] == DIRECT_CHAR)
	{
		if (is_valid_digit(&param[1]))
			return (T_DIR);
		else if (param[1] == LABEL_CHAR && ft_strlen(&param[2]) > 0)
			return (T_DIR);
	}
	else if (is_valid_digit(param) || param[0] == LABEL_CHAR)
	{
		if (is_valid_digit(param))
			return (T_IND);
		else if (ft_streachr(&param[1], &islabelchar) == 1)
			return (T_IND);
	}
	return (0);
}
