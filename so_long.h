/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:19 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 18:55:02 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# define ESC 53
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<mlx.h>

typedef struct so_long
{
	void	*mlx;
	void	*window;
	void	*img;
	char	**tmp;
	int		w;
	int		h;
	int		x;
	int		y;
	int		i;
	int		j;
	int		height;
	int		width;
	int		mouves;
}	t_data;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_check_length_map(char **map);
int		ft_check(char **map);
int		ft_check_top_down(char **map);
int		ft_check_left_right(char **map);
int		ft_check_character(char **map, char c);
int		ft_size(char **map);
int		ft_way(char **tmp);
char	**ft_open(char *str);
void	ft_map(char **map, int fd);
int		lines(int fd);
void	ft_free(char **str);
int		ft_check_path(char **tmp);
void	flood_fill(char **map, int x, int y, int lst);
int		key_hook(int keycode, t_data *data);
void	place_coin(t_data *data, int k, int m);
void	place_exit(t_data *data, int k, int m);
void	place_player(t_data *data, int k, int m);
void	wall(t_data *data, int k, int m, int j);
void	last_wall(t_data *data, char *map, int m);
void	first_wall(t_data *data, char *map);
void	place_map(t_data *data);
int		height(char **map);
int		width(char **map);
int		ft_check_map(char **map);
void	ft_destroy(t_data *data, int i);
void	ft_place(t_data *data);
void	places(t_data *data, int i, int j);
void	player_position(t_data *data);
void	free_struct(t_data *data);
void	ft_top(t_data *data);
void	ft_right(t_data *data);
void	ft_bottom(t_data *data);
void	ft_to_left(t_data *data);
void	ft_destroy(t_data *data, int i);
void	ft_putnbr(int n);
void	ft_error(t_data *data);
void	place_floor(t_data *data);
#endif
