/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:28:30 by jmarinho          #+#    #+#             */
/*   Updated: 2023/06/27 16:33:58 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_and_join(int fd, char *temp)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr_gnl(temp, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!buffer)
			return (NULL);
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read_and_join(fd, temp);
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);
	temp = ft_new_temp(temp);
	if(!line)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	return (line);
}
