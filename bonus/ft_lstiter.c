/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:39:35 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/24 22:20:01 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_lstiter(t_list *lst, void (*f)(char *, t_fil *), t_fil *fil)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		(*f)(tmp->content, fil);
		tmp = tmp->next;
	}
}
