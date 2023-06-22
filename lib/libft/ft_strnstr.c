/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:16:11 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/19 12:49:17 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		k = 0;
		while (big[i + k] == little[k] && i + k < len)
		{
			if (little[k + 1] == '\0')
				return ((char *) big + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
