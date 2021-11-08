/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsedat <vsedat@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:24:49 by vsedat            #+#    #+#             */
/*   Updated: 2021/11/07 15:41:11 by vsedat           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*saver;
	t_list	*todel;

	if (lst && del && *lst)
	{
		todel = *lst;
		while (todel)
		{
			saver = todel->next;
			del((todel)->content);
			free(todel);
			todel = saver;
		}
		*lst = 0;
	}
}
