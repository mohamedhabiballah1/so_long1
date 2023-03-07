/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:45:33 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 14:08:32 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	flood_fill(char **map, int x, int y, int lst)
{
	if (x > lst || y > (ft_strlen(map[0]) - 1)
		|| map[x][y] == '1' || map[x][y] == 'F' || map[x][y] == 'N')
		return ;
	else if (map[x][y] == '0' || map[x][y] == 'P'
			|| map[x][y] == 'C')
		map[x][y] = 'F';
	else if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	flood_fill(map, x - 1, y, lst);
	flood_fill(map, x + 1, y, lst);
	flood_fill(map, x, y - 1, lst);
	flood_fill(map, x, y + 1, lst);
}

int	ft_check_path(char **tmp)
{
	int	i;
	int	j;

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

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_way(char **tmp)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'P')
			{
				x = i;
				y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	flood_fill(tmp, x, y, i);
	return (ft_check_path(tmp));
}

void	place_floor(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "floor.xpm",
			&data->width, &data->height);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
