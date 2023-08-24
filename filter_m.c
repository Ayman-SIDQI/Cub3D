/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:23:46 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/24 11:56:09 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dup_check(char *cnt)
{
	int	i;

	i = -1;
	while (cnt[++i])
	{
		
	}
}
// void	coors(char *cnt)
// {}

bool	filter_m(t_pov *all)
{
	t_pov	*tmp;

	tmp = all;
	while (tmp)
	{
		ft_lstiter(tmp, &dup_check);
		// ft_lstiter(tmp, &coors);
	}
}
