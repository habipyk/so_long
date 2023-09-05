/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 04:07:00 by hyalcink          #+#    #+#             */
/*   Updated: 2023/09/05 09:42:55 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	openmap(t_mapinfo *map)
{
	map->fd = open(map->mapname, O_RDONLY);
	if (map->fd < 0)
	{
		close(map->fd);
		ft_exit(map, 1);
	}
}

void	allocatemap(t_mapinfo *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * (map->row + 1));
	if (map->map == 0)
		ft_exit(map, 2);
	map->map[map->row] = 0;
	while (i < map->row)
	{
		map->map[i] = malloc(sizeof(char) * map->column + 1);
		if (map->map[i] == 0)
			ft_exit(map, 1);
		i++;
	}
	map->tmpmap = malloc(sizeof(char *) * (map->row + 1));
	if (map->tmpmap == 0)
		ft_exit(map, 1);
	i = 0;
	while (i < map->row)
	{
		map->tmpmap[i] = malloc(sizeof(char) * map->column + 1);
		if (map->tmpmap[i] == 0)
			ft_exit(map, 1);
		i++;
	}
}

int	ft_exit(t_mapinfo *map, int a)
{
	if(a == 1)
	perror("dosya okunamadı");
	if(a == 2)
	perror("yer açılamadı");
	if(a == 3)
	perror("map okunamadı");
	if(a == 6)
	perror("map kare");
	exit(0);
	return (0);
}

int	size_calc(long nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb *= -1;
		counter++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		counter++;
	}
	counter++;
	return (counter);
}

void	convert_number(long nb, char *c, int *i)
{
	if (nb < 0)
	{
		nb *= -1;
		*c = '-';
		*i += 1;
	}
	if (nb >= 10)
	{
		convert_number(nb / 10, c, i);
		convert_number(nb % 10, c, i);
	}
	else
	{
		*(c + *i) = nb + '0';
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		size;
	int		i;

	i = 0;
	nb = n;
	size = size_calc(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	convert_number(nb, str, &i);
	str[i] = '\0';
	return (str);
}
