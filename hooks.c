/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:38:22 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/05 18:53:33 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == 0)
		return ;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		n = n * (-1);
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putchar((n % 10) + 48);
	}
}

void	ft_destroy(t_data *data, int i)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	ft_free(data->tmp);
	free_struct(data);
	if (i == 1)
		write (1, "{MISSION PASSED}\n", 18);
	exit (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_destroy(data, 0);
	if (ft_check_character(data->tmp, 'E') == 0)
		ft_destroy(data, 1);
	if (keycode == W_KEY)
		ft_top(data);
	if (keycode == D_KEY)
		ft_right(data);
	if (keycode == S_KEY)
		ft_bottom(data);
	if (keycode == A_KEY)
		ft_to_left(data);
	return (0);
}
