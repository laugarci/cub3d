/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:57:09 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/06 17:06:40 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	i;
	char	*str;
	int		len;

	str = (char *)s;
	len = ft_strlen(s);
	i = (char)c;
	while (len >= 0)
	{
		if (str == NULL)
			return (str);
		if (str[len] == i)
			return (str + len);
		if (str == 0)
			return (NULL);
		len--;
	}
	return (NULL);
}
