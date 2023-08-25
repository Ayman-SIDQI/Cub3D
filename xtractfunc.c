/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtractfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:18:05 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/25 13:45:23 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	nasa(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] > ' ')
			return (true);
	}
	return (false);
}

bool	xelem(t_pov *all)
{
	int	i;

	i = 0;
	all->elem[i] = get_next_line(all->fd);
	while (i < 6 && (all->elem[i] != NULL))
	{
		if (ft_strnstr(all->elem[i], "NO ", 4) \
		|| ft_strnstr(all->elem[i], "SO ", 4) \
		|| ft_strnstr(all->elem[i], "WE ", 4) \
		|| ft_strnstr(all->elem[i], "EA ", 4) \
		|| ft_strnstr(all->elem[i], "F ", 4) \
		|| ft_strnstr(all->elem[i], "C ", 4))
			i++;
		else if (nasa(all->elem[i]))
		{
			free(all->elem[i]);
			exit_perror();
		}
		else
			free(all->elem[i]);
		all->elem[i] = get_next_line(all->fd);
	}
	if (i != 6)
		return (true);
	return (false);
}

bool	xmap(t_pov *all)
{
	all->map_2d = NULL;
	all->tmp = get_next_line(all->fd);
	while (!nasa(all->tmp))
	{
		free(all->tmp);
		all->tmp = get_next_line(all->fd);
	}
	ft_lstadd_back(&all->map_2d, ft_lstnew(all->tmp));
	while (all->tmp != NULL)
	{
		all->tmp = get_next_line(all->fd);
		ft_lstadd_back(&all->map_2d, ft_lstnew(all->tmp));
		free(all->tmp);
	}
	return (false);
}
