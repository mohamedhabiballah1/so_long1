/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:19 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/21 12:31:11 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

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
    int x;
    int y;
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
#endif