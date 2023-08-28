#include "minilibx/mlx.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
typedef struct	s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
int	close(int button, int x, int y, t_vars *param)
{
    mlx_put
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data  a;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	//mlx_hook(vars.win, 6, 0, close, &vars);
	//mlx_loop(vars.mlx);
}