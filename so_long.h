/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:19 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/22 16:16:55 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define ESC 53
# define A_key 0
# define S_key 1
# define D_key 2
# define W_key 13

typedef struct so_long
{
    void *mlx;
    void *window;
    void *img;
    int w;
    int h;
}   t_data;

typedef struct map
{
    char **tmp;
    int x;
    int y;
    int i;
    int j;
}   t_map;

# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<mlx.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_check_length_map(char **map);
int     ft_check(char **map);
int     ft_check_top_down(char **map);
int     ft_check_left_right(char **map);
int     ft_check_collectible(char **map);
int     ft_check_player(char **map);
int     ft_check_exit(char **map);
int     ft_size(char **map);
int     ft_way(char *str);
char    **ft_open(char *str);
void    ft_map(char **map, int fd);
int     lines(int fd);
void    ft_free(char **str);
int     ft_check_path(char **tmp);
void    flood_fill(char **map, int x, int y, int lst, int len);
int     key_hook(int keycode, t_data *data, t_map *map);
void    place_coin(t_data data, int k, int m);
void    place_exit(t_data data, int k, int m);
void    place_player(t_data data, int k, int m);
void    wall(t_data data, int k, int m, int j);
void    last_wall(t_data data, char *map, int m);
void    first_wall(t_data data, char *map);
void    place_map(char **map, t_data data);
#endif