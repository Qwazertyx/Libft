/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:47:43 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/06 22:40:29 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parsing(const char *str)
{
	int	i;

	i = 0;
	while ((((((str[i] == '\f' || str[i] == '\r')
						|| str[i] == ' ')
					|| str[i] == '\t')
				|| str[i] == '\n')
			|| str[i] == '\v') && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (i);
}

int	sign(const char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] == '+')
			sign = 1;
		i++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	int long	res;

	if (!str)
		return (0);
	i = parsing(str);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign(str));
}
