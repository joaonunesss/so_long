/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:21:20 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/20 11:50:27 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	final_len;
	char	*final;

	final_len = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(sizeof(char) * final_len + 1);
	if (final == NULL)
		return (NULL);
	ft_strlcpy(final, s1, ft_strlen(s1) + 1);
	ft_strlcat(final + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (final);
}
