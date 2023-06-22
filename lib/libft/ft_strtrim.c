/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:55:08 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/24 20:47:53 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1);
	while (i <= size && ft_strchr(set, s1[i]))
		i++;
	if (i > size)
		return (ft_strdup(s1 + size));
	while (size >= 0 && ft_strchr(set, s1[size - 1]))
		size--;
	trim = malloc(sizeof(char) * (size - i + 1));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, &s1[i], size - i + 1);
	return (trim);
}
