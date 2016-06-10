/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 22:58:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 01:49:56 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*flagstr(void)
{
	static char *flag = NULL;

	if (!flag)
		flag = ft_strnew('z');
	return (flag);
}

int		getflag(char c)
{
	char *f;

	f = flagstr();
	return (f[(int)c]);
}

int		flagsisdefine(char c, int i)
{
	const char	flags[10] = {'v', 'u'};
	char		*f;

	if (ft_strchr(flags, c))
	{
		if (i)
		{
			f = flagstr();
			f[(int)c] = 1;
		}
		return (1);
	}
	return (0);
}

void	flagsloadwhile(char *avi)
{
	int	a;

	a = 1;
	while (avi[a])
	{
		if (!flagsisdefine(avi[a], 1))
		{
			ft_dprintf(2, "{red}Unknown flag {green}'%c'{eoc} \n", avi[a]);
			exit(0);
		}
		a++;
	}
}

int		flagsload(int ac, char **av)
{
	int valid;
	int	i;

	i = 1;
	valid = 1;
	while (i < ac && valid)
	{
		if (av[i][0] == '-')
		{
			flagsloadwhile(av[i]);
			if (!ft_isdigit(av[i][1]))
				i++;
			else
				valid = 0;
		}
		else
			valid = 0;
	}
	return (i);
}
