/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:31:09 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/13 15:28:56 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = 0;
	k = 0;
	j = ft_strlen((char *)s1);
	if (!*s1)
		return (ft_calloc(1, 1));
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strrchr(set, s1[j - 1]) && j > i)
		j--;
	res = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!res)
		return (NULL);
	while (j > i)
		res[k++] = s1[i++];
	res[k] = '\0';
	return (res);
}
