/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:10:55 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/05 16:18:56 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	int		i;

	if (!s)
		return (0);
	t = (char *)malloc(ft_strlen(s) + 1);
	if (!t)
		return (0);
	i = 0;
	i = (unsigned int)i;
	while (s[i])
	{
		t[i] = (*f)(i, ((char)s[i]));
		i++;
	}
	t[i] = 0;
	return (t);
}
