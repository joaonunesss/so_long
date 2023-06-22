/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:22:27 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/18 17:57:21 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	chr;

	chr = (unsigned char) c;
	s1 = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*s1 == chr)
			return (s1);
		i++;
		s1++;
	}
	return (NULL);
}
