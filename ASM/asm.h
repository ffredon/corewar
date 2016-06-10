/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 06:55:44 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/05/25 13:25:33 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft/libft.h"
# include "asm_type.h"

int					flagsload(int ac, char **av);
int					getflag(char c);

void				print_instruction_params(t_hero *hero, t_inst *inst,
					int line);

void				write_to_hexa(int fd, long nb, int size);
void				write_name(int fd, char *name, int size);
void				write_comment(int fd, char *comment);
void				write_magicnumber(int fd);
char				*readsource(char *file);
char				*cleansource(char *file);
char				*rmcomment(char *file);
char				*get_name(char *file, int *j);
char				*get_comment(char *file, int *j);
char				**readops(char *file);
t_hero				*read_hero(char *file);
void				debug_hero(t_hero *hero);
void				split_op_label(t_hero *hero);
void				hero_gen_ops(t_hero *hero);
void				hero_check_ops(t_hero *hero);
void				hero_size_ops(t_hero *hero);
void				free_hero(t_hero *hero);
void				hero_header(t_hero *hero, char *file, int *j);

void				asm_error(char *cause, char *str);
void				error_type_param(t_inst *inst, t_param *param, int i);
void				error_inst_param(t_inst *inst, t_param *param, int i);
void				error_size(int type, char *str);

char				*to_hexa(long nb, int size);
int					toc(int a);
int					tosize(int a, int inst_type);

int					is_valid_digit(char *digit);

void				usage(void);

int					isblankchar(char c);
int					islabelchar(int c);

void				op_analyse(t_hero *hero);
void				op_length_analyse(t_hero *hero);

void				write_instructions(int fd, t_hero *hero);
void				write_instruction(int fd, t_hero *hero, t_inst *inst,
					int line);

t_inst				*new_instruction(char *str);
t_inst				*add_instruction(t_inst **lst, t_inst *new);
void				free_instruction(t_inst *inst);
int					instruction_type(char *str);
int					size_instruction(t_inst *inst);
void				check_instruction(t_inst *inst, t_hero *hero);
int					instruction_gen_ocp(t_inst *inst);

t_param				*new_param(char *str);
t_param				*add_param(t_param **lst, t_param *new);
int					param_type(char *param);
char				*code_to_type(int type);

int					calc_dist_to_label(t_hero *hero, int start, int end);
int					get_pos_label(t_hero *hero, char *label);
char				*get_label_by_pos(t_hero *hero, int pos);
int					opthavelabel(char *opt);
char				*optgetlabelname(char *opt);
void				check_label_exist(t_hero *hero, char *label);
int					sizebetweeninst(int start, int end, t_inst *ops);

int					t_dir_val(t_param *param, int line, t_hero *hero);
int					t_ind_val(t_param *param, int line, t_hero *hero);

#endif
