/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:00:44 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/04 14:53:51 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char		*fs;
	size_t		i;
	size_t		j;
	size_t		len1;
	size_t		len2;

	i = 0;
	j = 0;
	len1 = (ft_strlen(str1));
	len2 = (ft_strlen(str2));
	if (!str1 || !str2)
		return (NULL);
	fs = malloc (sizeof(char) * (len1 + len2 + 1));
	if (!fs)
		return (NULL);
	while (i < len1)
	{
		fs[i] = str1[i];
		i++;
	}
	while (i < len1 + len2)
		fs[i++] = str2[j++];
	fs[i] = '\0';
	return (fs);
}
