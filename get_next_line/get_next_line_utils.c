/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:18:51 by laugarci          #+#    #+#             */
/*   Updated: 2023/02/02 11:13:54 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (ft_free(&str));
		str[0] = '\0';
	}
	s = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!s)
		return (ft_free(&str));
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		s[i] = str[i];
	while (buf[j] != '\0')
		s[i++] = buf[j++];
	s[i] = '\0';
	free(str);
	return (s);
}

char	*ft_find_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*ft_new_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(&str));
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (ft_free(&str));
	i++;
	j = 0;
	while (str[i] != '\0')
		s[j++] = str[i++];
	s[j] = '\0';
	ft_free(&str);
	return (s);
}
