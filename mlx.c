#include "so_long.h"

void ft_images(t_mapinfo *map)
{
	int x;
	int	y;

	x = 64;
	y = 64;
	map->mlx= mlx_init();
	map->window = mlx_new_window(map->mlx,map->column*64,map->row*64,"so_long");
	map->pimgr = mlx_xpm_file_to_image(map->mlx, "textures/pr.xpm"
	,&x, &y);
	map->pimgl = mlx_xpm_file_to_image(map->mlx, "textures/pl.xpm"
	,&x, &y);
	map->pimgu = mlx_xpm_file_to_image(map->mlx, "textures/pu.xpm"
	,&x, &y);
	map->pimgd = mlx_xpm_file_to_image(map->mlx, "textures/pd.xpm"
	,&x, &y);
	map->wimg = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm",
	&x, &y);
	map->bgimg = mlx_xpm_file_to_image(map->mlx, "textures/bg.xpm",
	&x, &y);
	map->cimg = mlx_xpm_file_to_image(map->mlx, "textures/coin.xpm",
	&x, &y);
}
void ft_putimage(t_mapinfo *map, char i , int x, int y)
{
	mlx_put_image_to_window(map->mlx,map->window,map->bgimg,x,y);
	if(i == '1')
		mlx_put_image_to_window(map->mlx,map->window,map->wimg,x,y);
	else if(i == 'P')
	{
		if(map->cmove == 0)
		mlx_put_image_to_window(map->mlx,map->window,map->pimgd,x,y);
		else if(map->cmove == 1)
		mlx_put_image_to_window(map->mlx,map->window,map->pimgu,x,y);
		else if(map->cmove == 2)
		mlx_put_image_to_window(map->mlx,map->window,map->pimgl,x,y);
		else if(map->cmove == 3)
		mlx_put_image_to_window(map->mlx,map->window,map->pimgr,x,y);
	}
	else if(i == 'C')
		mlx_put_image_to_window(map->mlx,map->window,map->cimg,x,y);
	else if(i == 'E')
		mlx_put_image_to_window(map->mlx,map->window,map->pimgr,x,y);
}

int exitcheck(t_mapinfo *map, int x, int y)
{
	if(map->map[y][x] == 'C')
		map->coin--;
	if (map->map[y][x] == '1')
		return (1);
	if(map->map[y][x] == 'E' && map->coin == 0)
	{
		printf("%d step\n",map->pcount +1);
		ft_exit(map, 11);
	}
	else if(map->map[y][x] == 'E' && map->coin != 0)
		return(1);
	map->pcount++;
	printf("%d step\n",map->pcount);
	return(0);
}
void moveplayer(int keycode, t_mapinfo *map)
{
	if(keycode == 13)
	{
		if (!exitcheck(map, map->px, map->py - 1))
		{
			map->py--;
		}
		map->cmove = 1;
	}
	else if(keycode == 0)
	{ 
		if (!exitcheck(map, map->px - 1, map->py))
		{
			map->px--;
		}
		map->cmove = 2;
	}
	else if(keycode == 1)
	{
		if (!exitcheck(map, map->px, map->py + 1))
		{
			map->py++;
		}
		map->cmove = 0;
	}
	else if(keycode == 2)
	{
		if (!exitcheck(map, map->px + 1, map->py))
		{
			map->px++;
		}
		map->cmove = 3;
	}
}


void ft_rendermap(t_mapinfo *map)
{
	int x;
	int y;
	int i;
	int j;
	
	i = 0;
	y = 0;
	while(i < map->row)
	{
		x = 0;
		j = 0;
		while(j < map->column)
		{
			ft_putimage(map, map->map[i][j], x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}
int	frames(int keycode, t_mapinfo *map)
{
	if(keycode == 53 || keycode == 17)
		ft_exit(0,10);
	map->x = map->px;
	map->y = map->py;
	if(keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		moveplayer(keycode,map);
		map->map[map->y][map->x] = '0';
		map->map[map->py][map->px] = 'P';
	}
	ft_rendermap(map);
	mlx_string_put(map->mlx, map->window, 50, 10,
		0x00BDFF, ft_itoa(map->pcount));
	return(0);
}
void ft_mlx(t_mapinfo *map)
{
	
	ft_images(map);
	ft_rendermap(map);
	mlx_hook(map->window,2, 0, frames, map);
	mlx_hook(map->window, 17, 0, ft_exit, 0);
	mlx_loop(map->mlx);
}