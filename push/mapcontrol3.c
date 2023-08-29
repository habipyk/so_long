/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:05:10 by hyalcink          #+#    #+#             */
/*   Updated: 2023/08/29 15:20:26 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextlinee/get_next_line.h"

void	structinit(mapinfo *map)
{
	map->isvalid = 1;
	map->row = 0;
}

void	ft_exit(mapinfo *map, int errno)
{
	freemap(map);
	if (errno == 1)
		write(1, "invalid char\n", 13);
		exit(1);
}

void	getmap(mapinfo *map)
{
	int	j;
	int	i;
	char	*line;
	
	openmap(map);
	i = 0;
	if (map->isvalid == 1)
	{
		while (i < map->row)
		{
			j = 0;
			line = get_next_line(map->fd);
			if (!line)
				ft_exit(map, 1);
			while (j < map->column)
			{
				map->map[i][j] = line[j];
				j++;
			}
			map->map[i][j] = '\0';
			free(line);
			i++;
		}
	}
	close(map->fd);
}

void	getplayer(mapinfo *map)
{
	int i;
	int j;

	i = 0;
	while(i < map->row)
	{
		j = 0;
		while(map->map[i][j] != '\0')
		{
			if(map->map[i][j]=='P')
			{
				map->px = j;
				map->py = i;
			}
			j++;
		}
		i++;
	}
}