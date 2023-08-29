/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:35:04 by hyalcink          #+#    #+#             */
/*   Updated: 2023/08/29 15:37:20 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "getnextlinee/get_next_line.h"

void	openmap(mapinfo *map)
{
	int	create;
	int	fd;

	create = 0;
	if (ft_strnstr(map->mapname, ".ber"))
	{
		create = 1;
	}
	map->fd = open(map->mapname, O_RDONLY);
	if (map->fd < 0)
	{
		close(map->fd);
		ft_exit(map, 1);
	}
}

void	allocatemap(mapinfo *array)
{
	int	i;

	i = 0;
	array->map = malloc(sizeof(char *) * (array->row + 1));
	array->map[array->row] = NULL;
	while (i < array->row)
	{
		array->map[i] = malloc(sizeof(char) * array->column + 1);
		i++;
	}
}

void	getrow(mapinfo *map)
{
	int		tmprow;
	char	*line;

	tmprow = 0;
	openmap(map);
	line = get_next_line(map->fd);
	while (line)
	{
		free(line);
		line = get_next_line(map->fd);
		tmprow++;
	}
	map->row = tmprow;
	close(map->fd);
}

void	getcolumn(mapinfo *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	openmap(map);
	line = get_next_line(map->fd);
	if (!line)
		ft_exit(map, 1);
	map->column = ft_strlen(line) - 1;
	free(line);
	while (i < map->row)
	{
		line = get_next_line(map->fd);
		if (!line)
			ft_exit(map, 1);
		if (map->column != ft_strlen(line) - 1 && i != map->row - 1)
			map->isvalid = 0;
		else if (map->column != ft_strlen(line) && i == map->row - 1)
			map->isvalid = 0;
		i++;
		free(line);
	}
	close(map->fd);
}

void	start(mapinfo *map)
{
	structinit(map);
	getrow(map);
	getcolumn(map);
	allocatemap(map);
	getmap(map);
	checkmap(map);
	wallcheck(map);
	getplayer(map);
}
