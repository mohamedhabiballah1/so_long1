/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:52:18 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/26 10:02:08 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check(char **map)
{
    if (ft_check_length_map(map) != 0)
        return (1);
    else if (ft_check_top_down(map) != 0)
        return (1);
    else if (ft_check_left_right(map) != 0)
        return (1);
    else if (ft_size(map) != 0)
        return (1);
    else if (ft_check_character(map, 'C') == 0)
        return (1);
    else if (ft_check_character(map, 'P') != 1)
        return (1);
    else if (ft_check_character(map, 'E') != 1)
        return (1);
    else if (ft_check_map(map) != 0)
        return (1);
    return (0);
}

int ft_check_map(char **map)
{
    int i;
    int j;
    int k;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] && map[i][j] != '\n')
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' 
                && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'N')
                return(1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_check_left_right(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        if (map[i][j] != '1')
            return (1);
        while (map[i][j] != '\n' && map[i][j])
            j++;
        j--;
        if (map[i][j] != '1')
            return (1);
        i++;
    }
    return (0);
}

int ft_check_top_down(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i][j] && map[i][j] != '\n')
    {
        if (map[i][j] != '1')
            return(1);
        j++;
    }
    while (map[i])
        i++;
    i--;
    j = 0;
    while (map[i][j] && map[i][j] != '\n')
    {
        if (map[i][j] != '1')
            return(1);
        j++;
    }
    return (0);
}

int ft_check_length_map(char **map)
{
    int i;
    int y;
    int k;

    i = 0;
    k = (ft_strlen(map[i]) - 1);
    while (map[i])
    {
        y = 0;
        while (map[i][y] && map[i][y] != '\n')
            y++;
        if (y != k)
            return (1);
        i++;
    }
    return (0);
}

int ft_size(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
        i++;
    while (map[0][j])
        j++;
    j--;
    if (i == j)
        return (1);
    return (0);
}