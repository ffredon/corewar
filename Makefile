# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/18 10:11:23 by fredon            #+#    #+#              #
#    Updated: 2016/05/25 12:05:13 by dmoureu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	corewar

VMDIR	=	VM

ASMDIR	=	ASM

.PHONY	:	re clean fclean all ASM VM

all		:	$(NAME)

$(NAME)	:	VM ASM

VM		:
		make -C $(VMDIR)
		cp $(VMDIR)/corewar ./

ASM		:
		make -C $(ASMDIR)
		cp $(ASMDIR)/asm ./

clean	:	VMCL ASMCL

VMCL	:
		make -C $(VMDIR) clean

ASMCL	:
		make -C $(ASMDIR) clean

fclean	:	VMFCL ASMFCL

VMFCL	:
		make -C $(VMDIR) fclean
		rm ./corewar
ASMFCL	:
		make -C $(ASMDIR) fclean
		rm ./asm
re		:	fclean all
