/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:49:52 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/18 16:50:10 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	save = 0;
	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		save = (*lst)->next;
		if (*lst && (*lst)->content)
			del((*lst)->content);
		(*lst)->content = NULL;
		free(*lst);
		*lst = save;
	}
}
