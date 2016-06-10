/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:33:20 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 21:17:00 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list	*readfile(char *file, int *total)
{
	int		fd;
	t_list	*tmp;
	t_list	*lst;
	char	*line;
	int		ret;

	lst = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		asm_error("can't open file", file);
	while ((ret = get_next_oren(fd, &line)) > 0)
	{
		if (!lst)
			lst = ft_lstnew(line, (sizeof(char) * ft_strlen(line)) + 1);
		else
		{
			tmp = lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_lstnew(line, (sizeof(char) * ft_strlen(line)) + 1);
		}
		*total += ft_strlen(line);
		ft_strdel(&line);
	}
	return (lst);
}

char	*readsource(char *file)
{
	char	*buffer;
	t_list	*lst;
	t_list	*tmp;
	int		total;

	tmp = NULL;
	total = 0;
	lst = readfile(file, &total);
	buffer = ft_strnew(total + ft_lstlen(lst) + 1);
	while (lst)
	{
		tmp = lst;
		ft_strcat(buffer, (void*)lst->content);
		ft_strcat(buffer, "\n");
		ft_strdel((char**)(&lst->content));
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
	if (ft_strlen(buffer) == 0)
		asm_error("empty file", file);
	return (buffer);
}

char	*cleansource(char *file)
{
	int		i;
	int		quote;
	char	*buffer;

	buffer = ft_strnew(ft_strlen(file) + 1);
	i = 0;
	quote = 0;
	while (file[i])
	{
		if (file[i] == '"')
			quote ^= 1;
		if (quote)
			ft_strncat(buffer, &file[i], 1);
		else if (!isblankchar(file[i]) ||
				(isblankchar(file[i]) && !isblankchar(file[i + 1])))
		{
			if (file[i] == '\t')
				file[i] = ' ';
			ft_strncat(buffer, &file[i], 1);
		}
		i++;
	}
	ft_strdel(&file);
	return (buffer);
}

void	rmcommenttype(char *file, char *buffer, int i, int *com)
{
	if (file[i] == COMMENT_CHAR || file[i] == ';')
	{
		if ((file[i - 1] && file[i - 1] == '\n') || !i)
			*com = 1;
		else if (!*com)
			*com = 2;
	}
	if (!*com)
		ft_strncat(buffer, &file[i], 1);
	if (file[i] == '\n')
	{
		if (*com == 2)
			ft_strncat(buffer, "\n", 1);
		*com = 0;
	}
}

char	*rmcomment(char *file)
{
	int		i;
	int		quote;
	int		com;
	char	*buffer;

	com = 0;
	i = 0;
	quote = 0;
	buffer = ft_strnew(ft_strlen(file) + 1);
	while (file[i])
	{
		if (file[i] == '"' && com == 0)
			quote ^= 1;
		if (!quote)
			rmcommenttype(file, buffer, i, &com);
		else
			ft_strncat(buffer, &file[i], 1);
		i++;
	}
	ft_strdel(&file);
	return (buffer);
}
