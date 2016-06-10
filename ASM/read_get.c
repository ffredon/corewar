/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:36:39 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 13:24:08 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_name_error(char *str, char *name, int i)
{
	if (!str[i] || ft_strlen(name) < 1)
		asm_error("Empty name", " ");
	if (ft_strstr(&str[i], NAME_CMD_STRING))
		asm_error("Double name", "");
}

char		*get_name(char *file, int *j)
{
	char	*str;
	char	*name;
	int		i[2];

	name = NULL;
	i[0] = -1;
	str = ft_strstr(file, NAME_CMD_STRING);
	if (!(i[1] = 0) && str == NULL)
		asm_error("No name", "");
	if (str[5] && str[6] && (str[5] != ' ' || str[6] != '"') && str[5] != '"')
		asm_error("Invalid name format", " ");
	if (*j && *j > (int)(ft_strlen(file) - ft_strlen(str)))
		asm_error("Invalid comment/name", " ");
	*j = ft_strlen(file) - ft_strlen(str);
	while (str[++i[0]] && !name && ++*j)
	{
		if (str[i[0]] == '"' && !i[1])
			i[1] = i[0] + 1;
		else if (str[i[0]] == '"' && i[1])
			name = ft_strsub(str, i[1], i[0] - i[1]);
		else if (str[i[0]] == '\n' && !i[1])
			asm_error("Invalid name format", " ");
	}
	get_name_error(str, name, i[0]);
	return (name);
}

static void	get_comment_error(char *str, int i)
{
	if (!str[i])
		asm_error("Empty comment", "");
	if (ft_strstr(&str[i], COMMENT_CMD_STRING))
		asm_error("Error double .comment", "");
}

char		*get_comment(char *file, int *j)
{
	char	*str[2];
	int		i[2];

	str[1] = NULL;
	i[0] = -1;
	str[0] = ft_strstr(file, COMMENT_CMD_STRING);
	if (!(i[1] = 0) && str[0] == NULL)
		asm_error("No Comment", "");
	if (str[0][8] && str[0][9] && (str[0][8] != ' '
	|| str[0][9] != '"') && str[0][8] != '"')
		asm_error("Invalid comment format", " ");
	if (*j && *j > (int)(ft_strlen(file) - ft_strlen(str[0])))
		asm_error("Invalid comment/name", " ");
	*j = ft_strlen(file) - ft_strlen(str[0]);
	while (str[0][++i[0]] && !str[1] && ++*j)
	{
		if (str[0][i[0]] == '"' && !i[1])
			i[1] = i[0] + 1;
		else if (str[0][i[0]] == '"' && i[1])
			str[1] = ft_strsub(str[0], i[1], i[0] - i[1]);
		else if (str[0][i[0]] == '\n' && !i[1])
			asm_error("Invalid comment format", "");
	}
	get_comment_error(str[0], i[0]);
	return (str[1]);
}
