/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:10 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/21 13:37:40 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int lines(int fd)
{
    char *str;
    int i;

    i = 0;
    str = get_next_line(fd);
    while (str)
    {
        i++;
        str = get_next_line(fd);
    }
    return (i);
}

void    ft_map(char **map, int fd)
{
    int i;
    int j;
    char *str;

    i = 0;
    str = get_next_line(fd);
    while(str[0] != '1')
        str = get_next_line(fd);
    while (str && str[0] == '1')
    {
        map[i] = str;
        str = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
}



char    **ft_open(char *str)
{
    int fd;
    int i;
    char **map;

    fd = open(str, O_RDONLY);
    i = lines(fd);
    map = malloc(sizeof(char *) * (i + 1));
    close(fd);
    fd = open(str, O_RDONLY);
    ft_map(map, fd);
    return (map);
}

int height(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i * 50);
}

int width(char **map)
{
    int i;
    
    i = ft_strlen(map[0]);
    return ((i - 1) * 50);
}

void    first_wall(t_data data, char *map)
{
    int j;
    int k;
    int m;

    j = 0;
    k = 0;
    m = 0;
    while (map[j + 2])
    {
        if (j == 0)
        {
            data.img = mlx_xpm_file_to_image(data.mlx, "./wall/left.xpm", &data.w, &data.h);
            mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
        }
        else
        {
            data.img = mlx_xpm_file_to_image(data.mlx, "./wall/midlle.xpm", &data.w, &data.h);
            mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
        }
        k = k + 50;
        j++;
    }
    data.img = mlx_xpm_file_to_image(data.mlx, "./wall/right.xpm", &data.w, &data.h);
    mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
}

void    last_wall(t_data data, char *map, int m)
{
    int j;
    int k;

    j = 0;
    k = 0;
    while (map[j + 1])
    {
        if (j == 0)
        {
            data.img = mlx_xpm_file_to_image(data.mlx, "./wall/last_first.xpm", &data.w, &data.h);
            mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
        }
        else
        {
            data.img = mlx_xpm_file_to_image(data.mlx, "./wall/last_mid.xpm", &data.w, &data.h);
            mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
        }
        k = k + 50;
        j++;
    }
    data.img = mlx_xpm_file_to_image(data.mlx, "./wall/last_right.xpm", &data.w, &data.h);
    mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
}

void    wall(t_data data, int k, int m, int j)
{
    if (j == 0)
    {
        data.img = mlx_xpm_file_to_image(data.mlx, "./wall/first.xpm", &data.w, &data.h);
        mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
    }
    else
    {
        data.img = mlx_xpm_file_to_image(data.mlx, "./wall/wall.xpm", &data.w, &data.h);
        mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
    }
}

void    place_player(t_data data, int k, int m)
{
    data.img = mlx_xpm_file_to_image(data.mlx, "./player/right_ghost.xpm", &data.w, &data.h);
    mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
}

void    place_coin(t_data data, int k, int m)
{
    data.img = mlx_xpm_file_to_image(data.mlx, "coin.xpm", &data.w, &data.h);
    mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
}

void    place_exit(t_data data, int k, int m)
{
    data.img = mlx_xpm_file_to_image(data.mlx, "./door/closed.xpm", &data.w, &data.h);
    mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
}

void    place_map(char **map)
{
    t_data data;
    t_map maps;

    maps.x = height(map);
    maps.y = width(map);
    int k;
    int m = 0;
    int i = 0;
    int j = 0;
    data.mlx = mlx_init();
    data.window = mlx_new_window(data.mlx, maps.y, maps.x, "So_long");
    while (map[i])
    {
        k = 0;
        j = 0;
        if (i == 0)
            first_wall(data, map[i]);
        else if (map[i + 1] == NULL)
            last_wall(data, map[i], m);
        else
        {
            while (map[i][j + 2])
            {
                if (map[i][j] == '1')
                    wall(data, k, m, j);
                else if (map[i][j] == 'P')
                    place_player(data, k, m);
                if (map[i][j] == 'C')
                    place_coin(data, k, m);
                if (map[i][j] == 'E')
                    place_exit(data, k, m);
                k = k + 50;
                j++;
            }
            data.img = mlx_xpm_file_to_image(data.mlx, "./wall/last.xpm", &data.w, &data.h);
            mlx_put_image_to_window(data.mlx, data.window, data.img, k, m);
        }
        m = m + 50;
        i++;
    }
    mlx_loop(data.mlx);
}

int main(int ac, char **av)
{
    char str[] = "map2.ber";
    char **map;
    int i;

    map = ft_open(str);
    i = ft_check(map);
    if (i != 0)
        write(2, "Error\n", 6);
    if (ft_way(str) != 0)
        write(2, "", 0);
    place_map(map);
}