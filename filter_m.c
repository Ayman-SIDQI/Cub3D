/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:23:46 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/28 20:50:48 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dup_check(char *cnt, t_fil *fil)
{
	int			i;

	i = -1;
	while (cnt[++i])
	{
		if ((cnt[i] == 'N' || cnt[i] == 'E' || cnt[i] == 'W' || cnt[i] == 'S'))
		{
			fil->count++;
			fil->px = i;
		}
		if (cnt[i] != 'N' && cnt[i] != 'E' && cnt[i] != 'W' 
			&& cnt[i] != 'S' && cnt[i] != ' ' && cnt[i] != '0'
			&& cnt[i] != '1' && cnt[i] != '\n')
			fil->errflag = 1;
	}
	if (fil->mwidth < i)
		fil->mwidth = i;
}

void	initialize(t_fil *info)
{
	info->count = 0;
	info->mwidth = 0;
	info->mheight = 0;
	info->errflag = 0;
	info->px = 0;
	info->py = 0;
}

void	filter_m(t_pov *all)
{
	t_list	*tmp;

	tmp = all->map_2d;
	initialize(&all->map_info);
	ft_lstiter(tmp, &dup_check, &all->map_info);
	if (all->map_info.count != 1)
		all->map_info.errflag = 1;
	if (all->map_info.errflag == 1)
	{
		// ft_lstclear(&all, &free);
		exit_perror();
	}
}
