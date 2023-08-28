/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 00:35:04 by hyalcink          #+#    #+#             */
/*   Updated: 2023/08/29 01:40:50 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextlinee/get_next_line.h"
#include <stdio.h>

void    allocatemap(mapinfo *array)
{
    int i;
    i = 0;
    array->map = malloc(sizeof(char*)*array->row);
    while(i < array->row)
    {
        array->map[i]=malloc(sizeof(char)*array->column);
        array->map[i][array->column-1]='\0';
        i++;
    }
    i = 0;
    while(array->map[1][i]!='\0')
    {
        array->map[1][i]='A';
        i++;
    }
    printf("%s",array->map[1]);
}

void getrow(mapinfo *map)
{
    int tmprow;
    int fd;
    tmprow = 0;
    map->row = 0;
    fd = open("map.ber",O_RDONLY);
    if(fd < 0)
    {
        close(fd);
        exit(1);
    }
    while(get_next_line(fd))
    tmprow++;
    close(fd);
    map->row = tmprow;
}
void getcolumn(mapinfo *map)
{
    int fd;
    char *line;
    int i = 1;
    fd = open("map.ber",O_RDONLY);
    if(fd < 0)
    {
        close(fd);
        exit(1);
    }
    line = get_next_line(fd);
    map->column = ft_strlen(line);
    while(i < map->row)
    {
        line = get_next_line(fd);
        if(map->column != ft_strlen(line) && i != map->row-1 )
           map->isvalid = 0;
        else if(map->column != ft_strlen(line)+1 && i == map->row-1)
            map->isvalid = 0;
        i++;
    }
    close(fd);
}
void countmap(mapinfo *map)
{
    getrow(map);
    getcolumn(map);
    allocatemap(map);
 
}

int main()
{
    mapinfo map;
    map.isvalid = 1;
    countmap(&map);
    printf("\n%d\n%d\n%d",map.column,map.row,map.isvalid);
}