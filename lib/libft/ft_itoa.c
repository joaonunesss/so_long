/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:54:45 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/20 15:55:00 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_aux(char *str, long number, int i)
{
	if (number < 0)
	{
		str[0] = '-';
		number = number * -1;
	}
	while (number > 0)
	{
		str[i] = 48 + (number % 10);
		number = number / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		i;

	number = n;
	i = len(number);
	if (number == 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (NULL);
	str[i--] = '\0';
	if (number == 0)
	{
		str[0] = 48;
		return (str);
	}
	str = ft_itoa_aux(str, number, i);
	return (str);
}
