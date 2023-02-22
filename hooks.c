/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:38:22 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/22 16:41:11 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void    player_position(t_map map)
{
    int k;
    int l;
    int x;
    int y;

    x = 0;
    y = 0;
    k = 0;
    l = 0;
    while (map.tmp[k])
    {
        l = 0;
        while (map.tmp[k][l])
        {
            if (map.tmp[k][l] != 'P')
            {
                x = k;
                y = l;
                break;
            }
            l++;
        }
        k++;
    }
    //map->tmp[x][y] = '0';
    //map->tmp[x - 1][y] = 'P';
}

void    ft_top(t_data data, t_map map)
{
    int i;

    //player_position(map);
    //i = mlx_clear_window(data.mlx, data.window);
    place_map(map.tmp, data);
}

int key_hook(int keycode, t_data *data, t_map *map)
{
    int i = 0;
    while (map->tmp[i])
    {
        printf("%s", map->tmp[i]);
        i++;
    }
    
    if (keycode == ESC)
        exit(0);
    //else if (keycode == W_key)
    //    ft_top(*data, *map);
    return (0);
}