/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:31:25 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/05 11:53:47 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	compt1;
	unsigned int	compt2;

	compt1 = 0;
	compt2 = 0;
	while (src[compt1])
		compt1++;
	if (size != 0)
	{
		while (src[compt2] && compt2 < size - 1)
		{
			dest[compt2] = src[compt2];
			compt2++;
		}
		dest[compt2] = '\0';
	}
	return (compt1);
}
