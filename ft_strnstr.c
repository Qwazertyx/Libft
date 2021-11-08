/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:59:35 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/04 14:04:52 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	n;

	n = 0;
	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i + n < len)
	{
		if (haystack[i + n] == needle[n])
		{
			n++;
			if (!needle[n])
				return ((char *)haystack + i);
		}
		else
		{
			i++;
			n = 0;
		}
	}
	return (0);
}
