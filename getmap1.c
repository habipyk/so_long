/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 04:32:45 by hyalcink          #+#    #+#             */
/*   Updated: 2023/09/07 01:16:02 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmapname(t_mapinfo *map, char *ber)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapname[i])
	{
		j = 0;
		while (map->mapname[i + j] == ber[j])
		{
			if (!ber[j + 1])
			{
				if (map->mapname[i - 1] == '/')
					ft_exit(map, 4);
				if (map->mapname [i + j + 1] && ber[j + 1])
					ft_exit(map, 4);
				if (!map->mapname[i + j + 1] && !ber[j + 1])
					map->bool = 1;
			}
			j++;
		}
		i++;
	}
	if (map->bool == 0 || map->mapname[0] == '.')
		ft_exit(map, 4);
}

void	sizecheck(t_mapinfo *map)
{
	if (map->row > 22 || map->column > 40)
	{
		ft_exit(map, 6);
	}
}

void	getmap(t_mapinfo *map)
{
	int		j;
	int		i;
	char	*line;

	openmap(map);
	i = 0;
	while (i < map->row)
	{
		j = 0;
		line = get_next_line(map->fd);
		if (!line)
			ft_exit(map, 3);
		while (j < map->column)
		{
			map->map[i][j] = line[j];
			map->tmpmap[i][j] = line[j];
			j++;
		}
		map->map[i][j] = '\0';
		free(line);
		i++;
	}
	close(map->fd);
}

void	getplayer(t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->px = j;
				map->py = i;
			}
			j++;
		}
		i++;
	}
}
