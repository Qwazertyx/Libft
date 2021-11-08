/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:05:30 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/05 18:49:17 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*d;

	i = 0;
	d = (char *)s;
	if (!s)
		return (0);
	while (i < n)
	{
		if (d[i] == (char)c)
			return (&d[i]);
		i++;
	}
	return (0);
}
