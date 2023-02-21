/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:27:37 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/16 14:48:54 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int ft_check_collectible(char **map)
{
    int i;
    int j;
    int count;
    
    count = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int ft_check_player(char **map)
{
    int i;
    int j;
    int count;
    
    count = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int ft_check_exit(char **map)
{
    int i;
    int j;
    int count;
    
    count = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}