/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:50:05 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/29 18:05:53 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer_len(unsigned long num)
{
	int	return_value;

	return_value = 0;
	while (num != 0)
	{
		num = num / 16;
		return_value++;
	}
	return (return_value);
}

void	ft_pointer_aux(unsigned long num)
{
	if (num >= 16)
	{
		ft_pointer_aux(num / 16);
		ft_pointer_aux(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
			ft_print_char((num - 10 + 'a'));
	}
}

int	ft_print_pointer(unsigned long p)
{
	int	return_value;

	return_value = 0;
	if (p == 0)
		return (write(1, "(nil)", 5));
	return_value = write(1, "0x", 2);
	ft_pointer_aux(p);
	return (return_value += ft_pointer_len(p));
}
