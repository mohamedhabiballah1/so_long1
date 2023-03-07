/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:10 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/06 10:45:22 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i * 50);
}

int	width(char **map)
{
	int	i;

	i = ft_strlen(map[0]);
	return ((i - 1) * 50);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] == s2[i] && (s1[i] && s2[i]) != '\0')
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	check_param(char *str)
{
	int		i;
	char	**map;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strncmp(&str[i], ".ber", 5) != 0)
		return (1);
	map = ft_open(str);
	if (!map)
		return (1);
	if (ft_check(map) != 0)
	{
		ft_free(map);
		return (1);
	}
	ft_free(map);
	return (0);
}

int	main(int ac, char **av)
{
	char	*str;
	t_data	*data;

	if (ac == 2)
	{
		if (check_param(av[1]) != 0)
		{
			write(2, "Error : Something wrong.\n", 26);
			exit(1);
		}
		data = malloc(sizeof(t_data));
		if (!data)
			return (1);
		data->tmp = ft_open(av[1]);
		ft_place(data);
	}
	write(2, "Error : Where is the map?\n", 27);
	return (0);
}
