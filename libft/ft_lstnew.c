/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:02:09 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/16 22:43:53 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	printf("new new:%p\n", new);
	if (!new)
		return (0);
	new->content = ft_strdup(value);
	new->next = NULL;
	new->prv = NULL;
	return (new);
}
