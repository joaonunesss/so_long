/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:17:56 by gamoreir          #+#    #+#             */
/*   Updated: 2023/06/27 16:41:37 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	char	*new;
	char	*original;

	if (!str)
		return (NULL);
	if (len > (unsigned int)ft_strlen(str) - start)
		len = (ft_strlen(str) - start);
	if (start >= (unsigned int)ft_strlen(str))
	{
		new = (char *) malloc(sizeof(*new));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	new = (char *) malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	original = new;
	while (str[start] && len--)
		*new++ = str[start++];
	*new = '\0';
	return (original);
}

char	*ft_strdup_gnl(const char *str)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *) malloc(sizeof(*new) * ft_strlen((char *)str) + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = (char)str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *) malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	while (*str)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*(unsigned char *)str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
