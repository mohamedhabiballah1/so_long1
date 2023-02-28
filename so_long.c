/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:10 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/28 11:21:35 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int lines(int fd)
{
    char *str;
    int i;

    i = 0;
    str = get_next_line(fd);
    while(str[0] != '1')
        str = get_next_line(fd);
    while(str && str[0] == '1')
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

void    first_wall(t_data *data, char *map)
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
            data->img = mlx_xpm_file_to_image(data->mlx, "./wall/left.xpm", &data->w, &data->h);
            mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
        }
        else
        {
            data->img = mlx_xpm_file_to_image(data->mlx, "./wall/midlle.xpm", &data->w, &data->h);
            mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
        }
        k = k + 50;
        j++;
    }
    data->img = mlx_xpm_file_to_image(data->mlx, "./wall/right.xpm", &data->w, &data->h);
    mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void    last_wall(t_data *data, char *map, int m)
{
    int j;
    int k;

    j = 0;
    k = 0;
    while (map[j + 1])
    {
        if (j == 0)
        {
            data->img = mlx_xpm_file_to_image(data->mlx, "./wall/last_first.xpm", &data->w, &data->h);
            mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
        }
        else
        {
            data->img = mlx_xpm_file_to_image(data->mlx, "./wall/last_mid.xpm", &data->w, &data->h);
            mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
        }
        k = k + 50;
        j++;
    }
    data->img = mlx_xpm_file_to_image(data->mlx, "./wall/last_right.xpm", &data->w, &data->h);
    mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void    wall(t_data *data, int k, int m, int j)
{
    if (j == 0)
    {
        data->img = mlx_xpm_file_to_image(data->mlx, "./wall/first.xpm", &data->w, &data->h);
        mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
    }
    else
    {
        data->img = mlx_xpm_file_to_image(data->mlx, "./wall/wall.xpm", &data->w, &data->h);
        mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
    }
}

void    place_player(t_data *data, int k, int m)
{
    //
    data->img = mlx_xpm_file_to_image(data->mlx, "./player/right_ghost.xpm", &data->w, &data->h);
    mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void    place_coin(t_data *data, int k, int m)
{
    data->img = mlx_xpm_file_to_image(data->mlx, "coin.xpm", &data->w, &data->h);
    mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void    place_exit(t_data *data, int k, int m)
{
    if (ft_check_character(data->tmp, 'C') == 0)
        data->img = mlx_xpm_file_to_image(data->mlx, "./door/opened.xpm", &data->w, &data->h);
    else
        data->img = mlx_xpm_file_to_image(data->mlx, "./door/closed.xpm", &data->w, &data->h);
    mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void    enemy(t_data *data, int k, int m)
{
    data->img = mlx_xpm_file_to_image(data->mlx, "./enemy/enemy.xpm", &data->w, &data->h);
    mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void    places(t_data *data, int k, int m, int i, int j)
{
    if (data->tmp[i][j] == 'N')
        enemy(data, k, m);
    if (data->tmp[i][j] == '1')
        wall(data, k, m, j);
    else if (data->tmp[i][j] == 'P')
        place_player(data, k, m);
    else if (data->tmp[i][j] == 'C')
        place_coin(data, k, m);
    else if (data->tmp[i][j] == 'E')
        place_exit(data, k, m);
}

void    place_map(t_data *data)
{
    int i = 0;
    int m = 0;
    int k = 0;
    int j = 0;

    while (data->tmp[i])
    {
        k = 0;
        j = 0;
        if (i == 0)
            first_wall(data, data->tmp[i]);
        else if (data->tmp[i + 1] == NULL)
            last_wall(data, data->tmp[i], m);
        else
        {
            while (data->tmp[i][j])
            {
                places(data, k, m, i, j);
                j++;
                k += 50;
            }
            data->img = mlx_xpm_file_to_image(data->mlx, "./wall/right.xpm", &data->w, &data->h);
            mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
        }
        i++;
        m += 50;
    }
}

int   place_loop(t_data *data)
{
    mlx_clear_window(data->mlx, data->window);
    place_map(data);
    return (0);
}

void    ft_place(t_data *data)
{
    //place_map(data);
    data->height = height(data->tmp);
    data->width = width(data->tmp);
    int k;
    int m = 0;
    int i = 0;
    int j = 0;
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx, data->width, data->height, "So_long");
    place_map(data);
    mlx_loop_hook(data->mlx, &place_loop, data);
    mlx_key_hook(data->window, &key_hook, data);
    mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
    char str[] = "map3.ber";
    char **map;
    t_data *data;

    map = ft_open(str);
    if (ft_check(map) != 0)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    if (ft_way(str) != 0)
    {
        write(2, "No way to some collectibles", 27);
        exit (1);
    }
    data = malloc(sizeof(t_data));
    data->tmp = ft_open(str);
    ft_place(data);
}