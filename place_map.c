/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:05:01 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 14:04:15 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	last(t_data *data, int k, int m)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./wall/last.xpm",
			&data->w, &data->h);
	if (data->img == NULL)
		ft_destroy(data, 0);
	mlx_put_image_to_window(data->mlx, data->window,
		data->img, k, m);
}

void	wall(t_data *data, int k, int m, int j)
{
	if (j == 0)
	{
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./wall/first.xpm", &data->w, &data->h);
		if (data->img == NULL)
			ft_error(data);
		mlx_put_image_to_window(data->mlx,
			data->window, data->img, k, m);
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./wall/wall.xpm", &data->w, &data->h);
		if (data->img == NULL)
			ft_error(data);
		mlx_put_image_to_window(data->mlx,
			data->window, data->img, k, m);
	}
}

void	place_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	place_floor(data);
	while (data->tmp[i])
	{
		j = 0;
		if (i == 0)
			first_wall(data, data->tmp[i]);
		else if (data->tmp[i + 1] == NULL)
			last_wall(data, data->tmp[i], i * 50);
		else
		{
			while (data->tmp[i][j + 2])
			{
				places(data, i, j);
				j++;
			}
			last(data, j * 50, i * 50);
		}
		i++;
	}
}

int	mouse(t_data *data)
{
	ft_destroy(data, 0);
	return (0);
}

void	ft_place(t_data *data)
{
	data->height = height(data->tmp);
	data->width = width(data->tmp);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width,
			data->height, "So_long");
	data->mouves = 0;
	place_map(data);
	mlx_key_hook(data->window, &key_hook, data);
	mlx_hook(data->window, 17, 0, &mouse, data);
	mlx_loop(data->mlx);
}
