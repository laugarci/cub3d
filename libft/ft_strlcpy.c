/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:10:55 by laugarci          #+#    #+#             */
/*   Updated: 2022/09/21 12:13:48 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		++i;
	}
	if (size != 0)
	{
		while (src[j] && j < (size - 1))
		{
			dest[j] = src[j];
			++j;
		}
		dest[j] = '\0';
	}
	return (i);
}
