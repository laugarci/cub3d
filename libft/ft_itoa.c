/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:58:34 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/18 14:47:45 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_maxnum(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	ft_itoa_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num;

	num = ft_itoa_len(n);
	str = (char *)malloc(sizeof(char) * (num + 1));
	if (!str)
		return (NULL);
	str[num] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		num--;
		str[num] = ft_maxnum(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
