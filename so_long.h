/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 03:46:44 by hyalcink          #+#    #+#             */
/*   Updated: 2023/09/05 21:14:08 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list{
	char	**map;
	char	**tmpmap;
	char	*mapname;
	int		row;
	int		column;
	int		isvalid;
	int		fd;
	int		coin;
	int		tmpcoin;
	int		player;
	int		exit;
	int		px;
	int		py;
	int		bool;
	int		pcount;
	int		x;
	int		y;
	int		reache;
	int		cmove;
	void	*mlx;
	void	*window;
	void	*pimgd;
	void	*pimgu;
	void	*pimgl;
	void	*pimgr;
	void	*wimg;
	void	*bgimg;
	void	*cimg;
}	t_mapinfo;

void	checkmapname(t_mapinfo *map, char *ber);
int		ft_exit(t_mapinfo *map, int errno);
void	wallcheck(t_mapinfo *map);
void	freemap(t_mapinfo *map, int a);
void	checkmap(t_mapinfo *map);
void	start(t_mapinfo *map);
void	getmap(t_mapinfo *map);
void	openmap(t_mapinfo *map);
void	allocatemap(t_mapinfo *map);
void	structinit(t_mapinfo *map);
void	getplayer(t_mapinfo *map);
void	checkmapname(t_mapinfo *map, char *ber);
void	rcheck(t_mapinfo *map);
void	isvalid(t_mapinfo *map, int x, int y);
void	checkpath(t_mapinfo *map);
void	ft_mlx(t_mapinfo *map);
void	ft_rendermap(t_mapinfo *map);
void	ft_putimage(t_mapinfo *map, char i, int x, int y);
void	ft_images(t_mapinfo *map);
void	ft_put_move(t_mapinfo *map, char *mc);
char	*ft_itoa(int n);
#endif
