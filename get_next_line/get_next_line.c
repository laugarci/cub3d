/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:04 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/02 11:21:00 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char **pt)
{
	free(*pt);
	*pt = NULL;
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_free(&str);
		return (0);
	}
	while (str[i])
		i++;
	return ((size_t)i);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buf;
	int		rdbytes;

	rdbytes = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&str));
	while (!ft_strchr(str, '\n') && rdbytes > 0)
	{
		rdbytes = read(fd, buf, BUFFER_SIZE);
		if (rdbytes > 0)
		{
			buf[rdbytes] = '\0';
			str = ft_strjoin(str, buf);
		}
	}
	free(buf);
	if (rdbytes == -1)
	{
		return (ft_free(&str));
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (ft_free(&str));
	line = ft_find_line(str);
	if (!line)
		return (ft_free(&str));
	str = ft_new_line(str);
	return (line);
}
