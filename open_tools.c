/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:00:22 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/03/06 10:45:39 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	lines(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	while (str[0] != '1')
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
	}
	while (str && str[0] == '1')
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (i);
}

void	ft_map(char **map, int fd)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	while (str[0] != '1')
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str && str[0] == '1')
	{
		map[i] = str;
		str = get_next_line(fd);
		i++;
	}
	free(str);
	map[i] = NULL;
}

char	**ft_open(char *str)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
	}	
	i = lines(fd);
	if (i == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	close(fd);
	fd = open(str, O_RDONLY);
	ft_map(map, fd);
	return (map);
}
