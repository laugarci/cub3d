/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:03:39 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/18 14:31:25 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = flag * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10;
		j = j + str[i] - 48;
		i++;
	}
	return (j * flag);
}
