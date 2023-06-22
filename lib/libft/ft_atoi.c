/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:19 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/19 13:14:17 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_aux(int i, const char *str)
{
	int	atoi;

	atoi = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		atoi = atoi * 10 + str[i] - 48;
		i++;
	}
	return (atoi);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	result = ft_atoi_aux(i, str);
	return (result * signal);
}
