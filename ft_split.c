/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:28:01 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/09 10:52:35 by vsedat           ###   ########lyon.fr   */
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

char	**mallocerror(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;
	int		j;
	int		k;

	if (!s)
		return (0);
	split = malloc((c_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	k = 0;
	i = 0;
	while (i < c_words(s, c))
	{
		split[i] = malloc((lenword(s, c, i)) * sizeof(char));
		if (!split[i])
			return (0);
		j = 0;
		while (s[k] == c)
			k++;
		while (j < lenword(s, c, i + 1))
			split[i][j++] = s[k++];
		split[i++][j] = 0;
	}
	split[i] = 0;
	return (split);
}
