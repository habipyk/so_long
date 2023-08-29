/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:15:46 by hyalcink          #+#    #+#             */
/*   Updated: 2023/08/29 14:18:03 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextlinee/get_next_line.h"

int	main(int ac, char *av[])
{
	mapinfo	map;

	map.mapname = av[1];
	start(&map);
}
