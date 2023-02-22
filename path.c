/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:45:33 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/22 13:45:36 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void flood_fill(char **map, int x, int y, int lst, int len)
{
    if (x > lst || y > len || map[x][y] == '1' || map[x][y] == 'F')
        return;
    else if (map[x][y] == '0' || map[x][y] == 'P' 
        || map[x][y] == 'E' || map[x][y] == 'C')
        map[x][y] = 'F';
    flood_fill(map, x - 1, y, lst, len);
    flood_fill(map, x + 1, y, lst, len);
    flood_fill(map, x, y - 1, lst, len);
    flood_fill(map, x, y + 1, lst, len);
}

int    ft_check_path(char **tmp)
{
    int i;
    int j;

    i = 0;
    while (tmp[i])
    {
        j = 0;
        while (tmp[i][j] && tmp[i][j] != '\n')
        {
            if (tmp[i][j] == 'C' || tmp[i][j] == 'E')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int ft_way(char *str)
{
    char **tmp;
    int i;
    int j;
    int x;
    int y;

    tmp = ft_open(str);
    while (tmp[i])
    {
        j = 0;
        while(tmp[i][j])
        {
            if (tmp[i][j] == 'P')
            {
                x = i;
                y = j;
                break;
            }
            j++;
        }
        i++;
    }
    flood_fill(tmp, x, y, i, j);
    i = ft_check_path(tmp);
    ft_free(tmp);
    return (i);
}