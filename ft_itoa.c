/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:17:04 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/05 16:10:04 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size(int long ln)
{
	int	s;

	s = 1;
	if (ln < 0)
	{
		s++;
		ln *= -1;
	}
	while (ln >= 10)
	{
		ln /= 10;
		s++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*a;
	int			i;
	int long	ln;

	ln = n;
	i = 0;
	a = malloc((size(ln) + 1) * sizeof(char));
	if (!a)
		return (0);
	if (ln < 0)
	{
		a[0] = '-' + (0 * i++);
		ln *= -1;
	}
	i += size(ln) - 1;
	while (ln >= 10)
	{
		a[i] = (ln % 10) + '0';
		ln /= 10;
		i--;
	}
	a[i] = ln + '0';
	ln = n;
	a[size(ln)] = 0;
	return (a);
}
