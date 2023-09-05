all:
	gcc main.c getmap.c getmap1.c checkmap.c mlx.c so_long_utils.c minilibx/libmlx.a get_next_line/get_next_line.a ft_printf/libftprintf.a -framework OpenGL -framework AppKit -o  solong