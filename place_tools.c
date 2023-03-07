/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:02:38 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 18:55:15 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_error(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_free(data->tmp);
	write(2, "{Something Wrong}\n", 19);
	exit (1);
}

void	place_first_wall(t_data *data, int j, int i)
{
	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->mlx, "./wall/left.xpm",
				&data->w, &data->h);
		if (data->img == NULL)
			ft_error(data);
		mlx_put_image_to_window(data->mlx, data->window,
			data->img, j * 50, 0);
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./wall/midlle.xpm", &data->w, &data->h);
		if (data->img == NULL)
			ft_error(data);
		mlx_put_image_to_window(data->mlx, data->window,
			data->img, j * 50, 2);
	}
}

void	first_wall(t_data *data, char *map)
{
	int	j;

	j = 0;
	while (map[j + 2])
	{
		if (j == 0)
			place_first_wall(data, j, 0);
		else
			place_first_wall(data, j, 1);
		j++;
	}
	data->img = mlx_xpm_file_to_image(data->mlx, "./wall/right.xpm",
			&data->w, &data->h);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->img, j * 50, 0);
}

void	place_last_wall(t_data *data, int j, int m, int i)
{
	if (i == 0)
	{
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./wall/last_first.xpm", &data->w, &data->h);
		if (data->img == NULL)
			ft_error(data);
		mlx_put_image_to_window(data->mlx,
			data->window, data->img, j * 50, m);
	}
	else
	{
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./wall/last_mid.xpm", &data->w, &data->h);
		if (data->img == NULL)
			ft_error(data);
		mlx_put_image_to_window(data->mlx,
			data->window, data->img, j * 50, m);
	}
}

void	last_wall(t_data *data, char *map, int m)
{
	int	j;

	j = 0;
	while (map[j + 1])
	{
		if (j == 0)
			place_last_wall(data, j, m, 0);
		else
			place_last_wall(data, j, m, 1);
		j++;
	}
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./wall/last_right.xpm", &data->w, &data->h);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->img, j * 50, m);
}
