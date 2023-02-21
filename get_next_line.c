/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabib-a <mhabib-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:53:52 by mhabib-a          #+#    #+#             */
/*   Updated: 2023/02/15 20:39:24 by mhabib-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_read1(int fd, char *s)
{
	ssize_t	sz;
	char	*buff;
	char	*tmp;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	sz = 1;
	while (!ft_strchr(s, '\n') && sz != 0)
	{
		sz = read(fd, buff, BUFFER_SIZE);
		if (sz == -1)
		{
			free(buff);
			free(s);
			return (NULL);
		}
		buff[sz] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		free(tmp);
	}
	free(buff);
	return (s);
}

char	*ft_ol(char *ltr)
{
	size_t	i;

	i = 0;
	if (ltr[i] == '\0')
	{	
		free(ltr);
		return (NULL);
	}
	if (!ft_strchr(ltr, '\n'))
		return (ltr);
	while (ltr[i] != '\n')
		i++;
	i++;
	return (ft_substr(ltr, 0, i));
}

char	*ft_left(char *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!ft_strchr(s, '\n'))
		return (NULL);
	while (s[i] != '\n')
		i++;
	if (s[i + 1] == '\0')
	{
		free(s);
		return (NULL);
	}
	i++;
	tmp = ft_substr(s, i, ft_strlen(s) - i);
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*ltr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(ltr);
		ltr = NULL;
		return (NULL);
	}
	ltr = ft_read1(fd, ltr);
	if (!ltr)
		return (NULL);
	line = ft_ol(ltr);
	ltr = ft_left(ltr);
	return (line);
}
