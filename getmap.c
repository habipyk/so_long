/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 04:17:43 by hyalcink          #+#    #+#             */
/*   Updated: 2023/09/07 01:14:10 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	structinit(t_mapinfo *map)
{
	map->isvalid = 1;
	map->row = 0;
	map->player = 0;
	map->coin = 0;
	map->exit = 0;
	map->cmove = 0;
	map->pcount = 0;
}

void	getrow(t_mapinfo *map)
{
	int		tmprow;
	char	*line;

	tmprow = 0;
	openmap(map);
	line = get_next_line(map->fd);
	if (!line)
		ft_exit(map, 3);
	while (line)
	{
		free(line);
		line = get_next_line(map->fd);
		tmprow++;
	}
	map->row = tmprow;
	close(map->fd);
}

void	getcolumn(t_mapinfo *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	openmap(map);
	line = get_next_line(map->fd);
	if (!line)
		ft_exit(map, 3);
	map->column = ft_strlen(line) -1;
	free(line);
	while (i < map->row)
	{
		line = get_next_line(map->fd);
		if (!line)
			ft_exit(map, 3);
		if (map->column != ft_strlen(line) - 1 && i != map->row -1)
			ft_exit(map, 3);
		else if (map->column != ft_strlen(line) && i == map->row -1)
			ft_exit(map, 3);
		i++;
		free(line);
	}
	close(map->fd);
}

void	start(t_mapinfo *map)
{
	structinit(map);
	checkmapname(map, ".ber");
	getrow(map);
	getcolumn(map);
	sizecheck(map);
	allocatemap(map);
	getmap(map);
	checkmap(map);
	wallcheck(map);
	checkpath(map);
	ft_mlx(map);
}
