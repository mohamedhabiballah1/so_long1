/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:38:22 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/28 11:14:51 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void    free_struct(t_data *data)
{
    free(data);
}

void    player_position(t_data *data)
{
    int k;
    int l;

    k = 0;
    l = 0;
    while (data->tmp[k])
    {
        l = 0;
        while (data->tmp[k][l])
        {
            if (data->tmp[k][l] == 'P')
            {
                data->x = k;
                data->y = l;
                break;
            }
            l++;
        }
        k++;
    }
}

void    ft_top(t_data *data)
{
    player_position(data);
    if (data->tmp[data->x - 1][data->y] == 'E' && ft_check_character(data->tmp, 'C') == 0)
    {
        data->tmp[data->x - 1][data->y] = 'P';
    }
    else if (data->tmp[data->x - 1][data->y] == 'N')
    {
        ft_free(data->tmp);
        free_struct(data);
        write(1, "Lmoooot a bouya", 16);
        exit(1);
    }
    else if (data->tmp[data->x - 1][data->y] == '1' || data->tmp[data->x - 1][data->y] == 'E')
        return;
    else
    {
        data->tmp[data->x][data->y] = '0';
        data->tmp[data->x - 1][data->y] = 'P';
    }
}

void    ft_right(t_data *data)
{
    player_position(data);
    if (data->tmp[data->x][data->y + 1] == 'E' && ft_check_character(data->tmp, 'C') == 0)
    {
        data->tmp[data->x][data->y+1] = 'P';
    }
    else if (data->tmp[data->x][data->y + 1] == 'N')
    {
        ft_free(data->tmp);
        free_struct(data);
        write(1, "Lmoooot a bouya", 16);
        exit(1);
    }
    else if (data->tmp[data->x][data->y + 1] == '1' || data->tmp[data->x][data->y + 1] == 'E')
        return;
    else
    {
        data->tmp[data->x][data->y] = '0';
        data->tmp[data->x][data->y + 1] = 'P';
    }
}

void    ft_bottom(t_data *data)
{
    player_position(data);
    if (data->tmp[data->x + 1][data->y] == 'E' && ft_check_character(data->tmp, 'C') == 0)
    {
        data->tmp[data->x + 1][data->y] = 'P';
    }
    else if (data->tmp[data->x + 1][data->y] == 'N')
    {
        ft_free(data->tmp);
        free_struct(data);
        write(1, "Lmoooot a bouya", 16);
        exit(1);
    }
    else if (data->tmp[data->x + 1][data->y] == '1' || data->tmp[data->x + 1][data->y] == 'E')
        return;
    else
    {
        data->tmp[data->x][data->y] = '0';
        data->tmp[data->x + 1][data->y] = 'P';
    }
}

void    ft_to_left(t_data *data)
{
    player_position(data);
    if (data->tmp[data->x][data->y - 1] == 'E' && ft_check_character(data->tmp, 'C') == 0)
    {
        data->tmp[data->x][data->y - 1] = 'P';
    }
    else if (data->tmp[data->x][data->y - 1] == 'N')
    {
        ft_free(data->tmp);
        free_struct(data);
        write(1, "Lmoooot a bouya", 16);
        exit(1);
    }
    else if (data->tmp[data->x][data->y - 1] == '1' || data->tmp[data->x][data->y - 1] == 'E')
        return;
    else
    {
        data->tmp[data->x][data->y] = '0';
        data->tmp[data->x][data->y - 1] = 'P';
    }
}

int key_hook(int keycode, t_data *data)
{
    if (ft_check_character(data->tmp, 'E') == 0)
    {
        ft_free(data->tmp);
        mlx_destroy_window(data->mlx, data->window);
        exit(0);
    }
    if (keycode == ESC)
        exit(0);
    else if (keycode == W_key)
        ft_top(data);
    else if (keycode == D_key)
        ft_right(data);
    else if (keycode == S_key)
        ft_bottom(data);
    else if (keycode == A_key)
        ft_to_left(data);
    return (0);
}