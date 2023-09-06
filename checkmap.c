/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 04:41:49 by hyalcink          #+#    #+#             */
/*   Updated: 2023/09/07 01:23:39 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	value_check(t_mapinfo *map)
{
	int	i;

	i = 1;
	if (map->player != i)
		ft_exit(map, 3);
	if (map->exit != i)
		ft_exit(map, 3);
	if (map->coin < i)
		ft_exit(map, 3);
}

void	checkmap(t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player += 1;
			else if (map->map[i][j] == 'C')
				map->coin += 1;
			else if (map->map[i][j] == 'E')
				map->exit += 1;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				ft_exit(map, 7);
			j++;
		}
		i++;
	}
	map->tmpcoin = map->coin;
	value_check(map);
}

void	wallcheck(t_mapinfo *map)
{
	int	i;

	i = 0;
	while (i < map->column)
	{
		if (map->map[0][i] != '1' || map->map[map->row - 1][i] != '1')
		{
			ft_exit(map, 8);
		}
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			ft_exit(map, 8);
		i++;
	}
}

void	isvalid(t_mapinfo *map, int x, int y)
{
	char	*p;

	p = &map->tmpmap[x][y];
	if (*p == 'E')
		map->reache = 1;
	if (*p != '1' && *p != 'E')
	{
		if (*p == 'C')
			map->tmpcoin--;
		*p = '.';
		if (map->tmpmap[x][y + 1] != '1' &&
			map->tmpmap[x][y + 1] != '.')
			isvalid(map, x, y + 1);
		if (map->tmpmap[x][y - 1] != '1' &&
			map->tmpmap[x][y - 1] != '.')
			isvalid(map, x, y - 1);
		if (map->tmpmap[x - 1][y] != '1' &&
			map->tmpmap[x - 1][y] != '.')
			isvalid(map, x - 1, y);
		if (map->tmpmap[x + 1][y] != '1' &&
			map->tmpmap[x + 1][y] != '.')
			isvalid(map, x + 1, y);
	}
}

void	checkpath(t_mapinfo *map)
{
	int	i;

	i = 0;
	getplayer(map);
	isvalid(map, map->py, map->px);
	if (map->tmpcoin != 0)
		ft_exit(map, 15);
	else if(map->reache != 1)
		ft_exit(map, 16);
}
