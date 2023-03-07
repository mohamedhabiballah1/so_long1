/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:27:37 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/03 11:25:51 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_check_character(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_size(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	j--;
	if (i == j)
		return (1);
	return (0);
}

void	free_struct(t_data *data)
{
	free(data);
}

void	player_position(t_data *data)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (data->tmp[k])
	{
		l = 0;
		while (data->tmp[k][l] && data->tmp[k][l] != '\n')
		{
			if (data->tmp[k][l] == 'P')
			{
				data->x = k;
				data->y = l;
			}
			l++;
		}
		k++;
	}
}
