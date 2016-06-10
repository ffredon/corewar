/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:06:40 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/23 00:13:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	isblankchar(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int	islabelchar(int c)
{
	if (ft_strchr(LABEL_CHARS, c))
		return (1);
	return (0);
}

int	is_valid_digit(char *digit)
{
	if (ft_isdigit(digit[0]) || digit[0] == '-' || digit[0] == '+')
	{
		if (ft_strlen(digit) == 1)
		{
			return (1);
		}
		else if (ft_strlen(digit) > 1)
		{
			if (ft_streachr(&digit[1], &ft_isdigit) == 1)
				return (1);
		}
	}
	return (0);
}
