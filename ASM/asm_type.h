/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:12:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/24 23:29:47 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_TYPE_H
# define ASM_TYPE_H

typedef struct				s_param
{
	char					*str;
	int						type;
	int						value;
	struct s_param			*next;
}							t_param;

typedef struct				s_instruction
{
	char					*str;
	int						type;
	int						size;
	t_param					*params;
	struct s_instruction	*next;
}							t_inst;

typedef struct				s_hero
{
	char					*name;
	char					*comment;

	char					**opts;
	int						*optslen;

	int						countlabel;
	char					**label_name;
	int						*label_pos;
	int						size_inst;
	t_inst					*inst;
}							t_hero;

#endif
