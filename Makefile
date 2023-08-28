all:
	gcc mapcontrol.c getnextlinee/get_next_line.c getnextlinee/get_next_line_utils.c libmlx.a -framework OpenGL -framework AppKit -o solong