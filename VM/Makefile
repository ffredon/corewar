NAME = corewar

INCLUDES = libft/includes/

SRC = main.c\
	 check_valid_file.c\
	 check_valid_file_next.c\
	 map_generation.c\
	 init_mlx.c\
	 mlx_functions.c\
	 mlx_launching_vm.c\
	 mlx_line.c\
	 mlx_print_win.c\
	 mlx_rec_px_img.c\
	 mlx_shapes.c\
	 mlx_thread_print.c\
	 key_functions.c\
	 color_ice.c\
	 burn.c\
	 black.c\
	 color_mag.c\
	 colors_earth.c\
	 lst_functions.c\
	 second_window.c\
	 second_window_next.c\
	 launch_vm.c\
	 launch_vm_next.c\
	 op_function_partone.c \
	 op_function_partone_next.c\
	 op_function_parttwo.c \
	 op_function_parttwo_next.c\
	 op_function_partthree.c \
	 op_function_partthree_next.c\
	 multi_gen_fcts.c\
	 multi_gen_fcts_next.c\
	 print_player.c\
	 enable_music.c\

WFLAGS = -Wall -Werror -Wextra -O3 -march=native

LFLAGS = -L libft/ -lft -lm -lmlx -framework OpenGL -framework AppKit

CC = gcc

OBJ = $(SRC:.c=.o)

SDL2		= -framework SDL2
SDL2_MIXER  = -framework SDL2_mixer

SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER   = -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/

SDL         = -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER  = -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)

all : $(NAME)

%.o: %.c
	$(CC) -c $(WFLAGS) -I $(INCLUDES) $(SDL_HEADER) $< -o $@

$(NAME) : $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) $(SDL) $(SDL_HEADER) $(LFLAGS)

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

sdl_install :
	curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
	unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/

re : fclean all

lre :
	make -C libft/ re

.PHONY: all clean fclean re
