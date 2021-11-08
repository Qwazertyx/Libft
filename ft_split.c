/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:28:01 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/07 15:04:07 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_words(const char *str, char sep)
{
	int	nbwords;
	int	cs;
	int	lenword;

	nbwords = 0;
	cs = 0;
	lenword = 0;
	while (str[cs])
	{
		if (str[cs] == sep || (!str[cs + 1] && str[cs] != sep))
		{
			if (lenword != 0 || (!str[cs + 1] && str[cs] != sep))
				nbwords++;
			lenword = 0;
		}
		else
			lenword++;
		cs++;
	}
	return (nbwords);
}

int	lenword(const char *str, char sep, int whichword)
{
	int	cs;
	int	lenword;

	cs = 0;
	while (whichword != 0 && str[cs])
	{
		lenword = 0;
		while (str[cs] == sep && str[cs])
			cs++;
		while (str[cs] != sep && str[cs])
		{
			cs++;
			lenword++;
		}
		whichword--;
	}
	return (lenword);
}

void	ft_split2(char const *s, char c, char **split)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < c_words(s, c) && s[k])
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			split[i][j++] = s[k++];
		split[i++][j] = 0;
	}
	split[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;

	if (!s)
		return (0);
	i = 0;
	split = malloc((c_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (i < c_words(s, c))
	{
		split[i] = malloc((lenword(s, c, i) + 1) * sizeof(char));
		if (!split[i])
		{
			i = 0;
			while (split[i])
				free(split[i++]);
			free(split);
			return (0);
		}
		i++;
	}
	ft_split2(s, c, split);
	return (split);
}
