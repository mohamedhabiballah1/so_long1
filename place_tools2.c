/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:04:04 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 12:06:20 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	place_player(t_data *data, int k, int m)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./player/right_ghost.xpm", &data->w, &data->h);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void	place_coin(t_data *data, int k, int m)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"coin.xpm", &data->w, &data->h);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx,
		data->window, data->img, k, m);
}

void	place_exit(t_data *data, int k, int m)
{
	if (ft_check_character(data->tmp, 'C') == 0)
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./door/opened.xpm", &data->w, &data->h);
	else
		data->img = mlx_xpm_file_to_image(data->mlx,
				"./door/closed.xpm", &data->w, &data->h);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void	enemy(t_data *data, int k, int m)
{
	data->img = mlx_xpm_file_to_image(data->mlx,
			"./enemy/enemy.xpm", &data->w, &data->h);
	if (data->img == NULL)
		ft_error(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, k, m);
}

void	places(t_data *data, int i, int j)
{
	if (data->tmp[i][j] == '1')
		wall(data, j * 50, i * 50, j);
	if (data->tmp[i][j] == 'P')
		place_player(data, j * 50, i * 50);
	if (data->tmp[i][j] == 'C')
		place_coin(data, j * 50, i * 50);
	if (data->tmp[i][j] == 'E')
		place_exit(data, j * 50, i * 50);
}
