/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:40:21 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/05 16:55:17 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		write(fd, "-", 1);
		nbl *= -1;
	}
	if (nbl > 9)
	{
		ft_putnbr_fd(nbl / 10, fd);
		ft_putnbr_fd(nbl % 10, fd);
	}
	if (nbl <= 9)
	{
		nbl += '0';
		write(fd, &nbl, 1);
	}
}
