/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:10:10 by hyalcink          #+#    #+#             */
/*   Updated: 2023/08/29 15:19:28 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextlinee/get_next_line.h"

void	value_check(mapinfo *map)
{
	int	i;

	i = 1;
	if (map->player != i)
		ft_exit(map, 4);
	if (map->exit != i)
		ft_exit(map, 2);
	if (map->coin <= 0)
		ft_exit(map, 3);
}

char	*ft_strnstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			if (!*(needle + j + 1))
			{
				if (i == 0)
					return (NULL);
				else
					return ((char *)(haystack + i - 1));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

void	checkmap(mapinfo *map)
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
				map->player++;
			else if (map->map[i][j] == 'C')
				map->coin++;
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				ft_exit(map, 1);
			j++;
		}
		i++;
	}
	value_check(map);
}

void	freemap(mapinfo *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	wallcheck(mapinfo *map)
{
	int	i;
	i = 0;
	while (i < map->column)
	{
		if (map->map[0][i] != '1' && map->map[map->row - 1][i] != '1')
		{
			ft_exit(map, 5);
		}
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		if (map->map[i][0] != '1' && map->map[i][map->column - 1] != '1')
			ft_exit(map, 5);
		i++;
	}
}
