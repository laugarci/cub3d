/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:15:30 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/19 11:31:34 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	c;

	i = 0;
	c = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' & i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && j + i < len)
			j++;
		while (little[c] != '\0')
			c++;
		if (j == c)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
