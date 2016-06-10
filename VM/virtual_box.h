/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_box.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:48:29 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/05/25 10:41:04 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_BOX_H
# define VIRTUAL_BOX_H
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include <mlx.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <pthread.h>
# include <math.h>

# define COREWAR_EXEC_MAGIC	0xea83f3
# define MAX_PLAYERS 4
# define MEM_SIZE 4096
# define IDX_MOD (MEM_SIZE / 8)
# define REG_NUMBER	16
# define REG_SIZE	4
# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE	21
# define MAX_CHECKS 10
# define X 1900
# define Y 1200
# define MT 16
# define THE struct s_thread

# define T_REG	1
# define T_IND	2
# define T_DIR	4
# define T_LAB	8

# define GRAPH 0x1
# define STOP 0x2
# define DUMP 0x4
# define AFF 0x8
# define IND proc->index
# define TYP proc->type
# define TMP proc->tmp
# define REG proc->reg

# define AR 0, -10, -4, -4, -4, -4, -10, -1, -10, -1, -7, 4, -7, +4, -7
# define TAR 10, -7, 10, 0, 7, 0, 7, 7, 10, 7, 10, 7, 4
# define STAR  AR, TAR , 7, 4, 10, -1, 10, -1, 4, -4, 4, -4, 0, -10

typedef struct			s_pc
{
	int					index;
	int					cycle;
	int					chp;
	char				carry;
	char				live;
	char				instruc;
	char				no;
	char				type[3];
	unsigned long long	tmp[3];
	char				reg[REG_NUMBER][REG_SIZE];
	struct s_pc			*next;
}						t_pc;

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	unsigned char		*op;
	int					tmp[2];
	int					op_len;
	int					last_live;
}						t_champ;

typedef struct			s_img
{
	void				*mlx;
	void				*win;
	void				*menu;
	void				*img;
	char				*data;
	int					sl;
	int					bpp;
	int					end;
	THE					*t;
	int					move_x;
	int					cycle_to_die;
	int					check;
	int					save;
	int					move_y;
	double				zoom;
}						t_img;

typedef struct			s_struck
{
	int					tmp[3];
	int					dump;
	int					turn_dump;
	int					cycle;
	int					check;
	unsigned int		live;
	int					rep;
	char				nb_chp;
	t_champ				chp[MAX_PLAYERS];
	char				*map;
	char				proc_live[2][MEM_SIZE];
	char				proc_test[MEM_SIZE];
	char				*col_chp;
	t_img				img;
	t_pc				**pro;
	char				max;
	int					nb_proc;
	int					turn;
	Mix_Chunk			*sound[2];
	Mix_Music			*music;
}						t_struck;

typedef struct			s_op
{
	char				c;
	void				(*do_op)(t_struck *s, t_pc *proc, t_pc **first);
}						t_op;

typedef struct			s_thread
{
	int					nb;
	int					lim[2];
	t_struck			*s;
}						t_thread;

void					cor_err(char nb, char *str);

unsigned long long		str_to_int(void *str, int len);
void					intro_players(t_struck *s);
void					check_valid_file(t_struck *s, char **files, int i);
void					check_champion(t_struck *s, char *file, int fd);
void					reorg(t_struck *s);
int						ft_opt_a(t_struck *s, int i);
void					map_gen(t_struck *s,
	t_pc **proc, int j, unsigned long long *i);
void					launching_vm(t_struck *s);
void					launching_vm_g(t_struck *s);
void					*thread_print(void *d);
void					ocp_value(char c, char *type);
int						move_ocp(char *type, char nb_param);
void					init_struck_op(t_op *op);
void					stock_value(unsigned long long *total,
	t_pc *proc, t_struck *s, char nb_param);
void					set_cycle(t_struck *s, t_pc *proc,
	int cycle, t_pc **first);
unsigned long long		set_ind(t_struck *s,
	unsigned long long tmp, t_pc *proc);
void					stock_value_dir(unsigned long long *total,
	t_pc *proc, t_struck *s, char nb_param);
void					stock_value_ldir(unsigned long long *total,
	t_pc *proc, t_struck *s, char nb_param);

void					second_window(t_struck *s);
void					init_graph(t_struck *s);
int						aff_graph(t_struck *s);
int						key_functions(int key, t_struck *s);
void					print_map(t_struck *s, int j);
void					print_map_dump(t_struck *s);
void					print_final(t_struck *s);
void					running_vm(t_struck *s, t_pc **proc, t_op *op);
void					set_proc_live(t_struck *s);
void					check_vm(t_struck *s,
	int *final_cycles, int *current_cycles);
void					print_winner(t_struck *s, int i);
void					put_matrix(t_struck *s);
void					put_cycle(t_struck *s);

t_pc					*ft_pcnew(t_pc *father, long long int index_value);
void					ft_pcadd(t_pc ***pclist, t_pc *new);
void					kill_process(t_pc **first, t_struck *s);
void					kill_process_end(t_pc **first, t_struck *s);

int						ft_colors_ice(int i);
int						burn(int i);
int						black(int i);
int						ft_colors_mag(int i);
int						ft_colors_earth(int i);

void					op_live(t_struck *s, t_pc *proc, t_pc **first);
void					op_ld(t_struck *s, t_pc *proc, t_pc **first);
void					op_st(t_struck *s, t_pc *proc, t_pc **first);
void					op_add(t_struck *s, t_pc *proc, t_pc **first);
void					op_sub(t_struck *s, t_pc *proc, t_pc **first);
void					op_and(t_struck *s, t_pc *proc, t_pc **first);
void					op_or(t_struck *s, t_pc *proc, t_pc **first);
void					op_xor(t_struck *s, t_pc *proc, t_pc **first);
void					op_zjump(t_struck *s, t_pc *proc, t_pc **first);
void					op_ldi(t_struck *s, t_pc *proc, t_pc **first);
void					op_sti(t_struck *s, t_pc *proc, t_pc **first);
void					op_fork(t_struck *s, t_pc *proc, t_pc **first);
void					op_lld(t_struck *s, t_pc *proc, t_pc **first);
void					op_lldi(t_struck *s, t_pc *proc, t_pc **first);
void					op_lfork(t_struck *s, t_pc *proc, t_pc **first);
void					op_aff(t_struck *s, t_pc *proc, t_pc **first);
long long int			set_mod(int index, long long tmp);
long long int			set_lmod(int index, long long tmp);
long long				reg_to_hex(char *str, int size);

void					rec_px_img(t_struck *s,
	int *c, int (*f)(int i), int color);
void					px_img(t_struck *s, float x, float y, int color);
void					line_px_img(t_struck *s, int *l, int col);
int						define_x(int l, t_img i);
int						define_y(int l, t_img i);
void					cercle(int *c, int (*f)(int i), int col, t_struck *s);
void					triangle(int *c, int (*f)(int i), int col, t_struck *s);
void					star(int *c, int (*f)(int i), int col, t_struck *s);

void					thread_print_sub5(t_thread *m, int l, int *c);
void					thread_print_sub6(t_thread *m, int l, int *c);

void					enable_shoot(t_struck *s);
void					enable_music(t_struck *s);

#endif
