/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:15:10 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/24 19:07:22 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	totallen;
	size_t	destlen;
	size_t	i;
	size_t	orgdest;

	destlen = ft_strlen(dest);
	totallen = ft_strlen(src) + destlen;
	orgdest = destlen;
	if ((size == 0) && (src == NULL))
		return (0);
	if (size > 0)
	{
		i = 0;
		while (destlen < (size - 1) && src[i] != '\0')
		{
			dest[destlen] = src[i];
			i++;
			destlen++;
		}
		dest[destlen] = '\0';
	}
	if (orgdest >= size)
		return (size + ft_strlen(src));
	return (totallen);
}
