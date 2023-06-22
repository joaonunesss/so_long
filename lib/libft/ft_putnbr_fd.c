/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:47:02 by jmarinho          #+#    #+#             */
/*   Updated: 2023/04/20 13:19:37 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printa(long longnb, int fd)
{
	int	x;

	if (longnb >= 0 && longnb < 10)
	{
		longnb = longnb + 48;
		write(fd, &longnb, 1);
	}
	else
	{
		ft_printa(longnb / 10, fd);
		x = longnb % 10 + 48;
		write(fd, &x, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	longnb;

	longnb = n;
	if (longnb < 0)
	{	
		longnb = -longnb;
		write(fd, "-", 1);
		ft_printa(longnb, fd);
	}
	else
		ft_printa(longnb, fd);
}
