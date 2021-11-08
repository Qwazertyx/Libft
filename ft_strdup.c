/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:25:57 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/06 18:58:42 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		c;

	c = 0;
	dup = malloc((1 + ft_strlen(s1)) * sizeof(char));
	if (!dup)
		return (0);
	while (s1[c])
	{
		dup[c] = s1[c];
		c++;
	}
	dup[c] = '\0';
	return (dup);
}
