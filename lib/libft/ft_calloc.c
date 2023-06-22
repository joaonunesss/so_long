/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:13:38 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/18 17:37:40 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbrelem, size_t elemsize)
{
	void	*mem;
	size_t	totalsize;

	totalsize = nbrelem * elemsize;
	mem = malloc(totalsize);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, totalsize);
	return (mem);
}
