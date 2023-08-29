#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


int	mouse_hook(int button, int x, int y, void *param)
{

	static int color;
	int a = x+10;
	int b = y+10;
	int firsty = y;
	color = 0x00FF00;
	if(button == 4)
	printf("%s\n","up");
	if(button == 5)
	printf("%s\n","down");
	while(x<=a)
	{
		y =firsty;
		while(y<=b)
		{
		mlx_pixel_put(((t_vars *)param)->mlx, ((t_vars *)param)->win, x, y, color);
		y++;
		}
		x++;
	}
	
	
	return (0);
}


int	main(void)
{
	
	 t_vars	vars;
	
	 vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");

	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	
	 mlx_loop(vars.mlx);
}