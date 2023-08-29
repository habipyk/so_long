/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:30:56 by hyalcink          #+#    #+#             */
/*   Updated: 2023/08/29 14:58:35 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct mapinfo{
    char **map;
    char *mapname;
    int row;
    int column;
    int isvalid;
    int fd;
    int coin;
    int player;
    int exit;
    int px;
    int py;
}mapinfo;

int		ft_n(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_get_line(char *str);
char	*ft_update_str(char *str);
char	*get_next_line(int fd);
char	*ft_strnstr(char *haystack, char *needle);
void    ft_exit(mapinfo *map,int errno);
void    wallcheck(mapinfo *map);
void    freemap(mapinfo *map);
void    checkmap(mapinfo *map);
void    start(mapinfo *map);
void    getmap(mapinfo *map);
void    openmap(mapinfo *map);
void    structinit(mapinfo *map);
void	getplayer(mapinfo *map);
#endif