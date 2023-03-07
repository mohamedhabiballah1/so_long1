/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:28:08 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 13:17:40 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_top(t_data *data)
{
	player_position(data);
	if (data->tmp[data->x - 1][data->y] == 'E'
			&& ft_check_character(data->tmp, 'C') == 0)
		ft_destroy(data, 1);
	else if (data->tmp[data->x - 1][data->y] == '1'
			|| data->tmp[data->x - 1][data->y] == 'E')
		return ;
	else
	{
		data->tmp[data->x][data->y] = '0';
		data->tmp[data->x - 1][data->y] = 'P';
		mlx_clear_window(data->mlx, data->window);
		data->mouves++;
		ft_putnbr(data->mouves);
		write(1, "\n", 1);
		place_map(data);
	}
}

void	ft_right(t_data *data)
{
	player_position(data);
	if (data->tmp[data->x][data->y + 1] == 'E'
			&& ft_check_character(data->tmp, 'C') == 0)
		ft_destroy(data, 1);
	else if (data->tmp[data->x][data->y + 1] == '1'
			|| data->tmp[data->x][data->y + 1] == 'E')
		return ;
	else
	{
		data->tmp[data->x][data->y] = '0';
		data->tmp[data->x][data->y + 1] = 'P';
		mlx_clear_window(data->mlx, data->window);
		data->mouves++;
		ft_putnbr(data->mouves);
		write(1, "\n", 1);
		place_map(data);
	}
}

void	ft_bottom(t_data *data)
{
	player_position(data);
	if (data->tmp[data->x + 1][data->y] == 'E'
			&& ft_check_character(data->tmp, 'C') == 0)
		ft_destroy(data, 1);
	else if (data->tmp[data->x + 1][data->y] == '1'
			|| data->tmp[data->x + 1][data->y] == 'E')
		return ;
	else
	{
		data->tmp[data->x][data->y] = '0';
		data->tmp[data->x + 1][data->y] = 'P';
		mlx_clear_window(data->mlx, data->window);
		data->mouves++;
		ft_putnbr(data->mouves);
		write(1, "\n", 1);
		place_map(data);
	}
}

void	ft_to_left(t_data *data)
{
	player_position(data);
	if (data->tmp[data->x][data->y - 1] == 'E'
			&& ft_check_character(data->tmp, 'C') == 0)
		ft_destroy(data, 1);
	else if (data->tmp[data->x][data->y - 1] == '1'
			|| data->tmp[data->x][data->y - 1] == 'E')
		return ;
	else
	{
		data->tmp[data->x][data->y] = '0';
		data->tmp[data->x][data->y - 1] = 'P';
		mlx_clear_window(data->mlx, data->window);
		data->mouves++;
		ft_putnbr(data->mouves);
		write(1, "\n", 1);
		place_map(data);
	}
}
