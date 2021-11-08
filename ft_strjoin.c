/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:25:06 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/05 12:25:21 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s;
	char	*t;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	s = ft_strlen(s1) + ft_strlen(s2);
	t = malloc(1 + s * sizeof(char));
	if (!t)
		return (0);
	i = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		t[i + j] = s2[j];
		j++;
	}
	t[i + j] = 0;
	return (t);
}
