/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:12:36 by jmarinho          #+#    #+#             */
/*   Updated: 2023/05/30 11:22:27 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_var_type(va_list args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == '%')
		return (ft_print_percent());
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));
	else if (c == 'u')
		return (ft_print_unint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), c));
	else
	{
		write(1, "Invalid Input", 13);
		return (-1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		return_value;

	va_start(args, format);
	return_value = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			return_value += ft_var_type(args, *format);
		}
		else
			return_value += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (return_value);
}
