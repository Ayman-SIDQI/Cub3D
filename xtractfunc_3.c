/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtractfunc_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:38:31 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/16 22:51:48 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_borders(t_list *map_info, t_pov *all)
{
	int	i;

	link_toarr(map_info, N, all);
	// printf("%p %s\n", all->map_2d, all->map_2d->content);
	ft_lstclear(&all->map_2d, &free);
	i = 0;
	while (all->map[i])
	{
		if (find_zeros(i, all->map))
			exit_perror(all);
		i++;
	}
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
	free(all->tmp);
	while (all->tmp != NULL)
	{
		all->tmp = get_next_line(all->fd);
		ft_lstadd_back(&all->map_2d, ft_lstnew(all->tmp));
		free(all->tmp);
	}
	return (false);
}

unsigned int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

char	*s_spc(char *l)
{
	while (*l && *l <= ' ')
		l++;
	return (l);
}

void	check_comma(t_pov	*all)
{
	int	i;
	int	o;
	int	counter;

	i = -1;
	while (all->elem[++i])
	{
		counter = 0;
		o = -1;
		while (all->elem[i][++o] \
		&& (ft_strnstr(&all->elem[i][0], "F ", 2) \
		|| ft_strnstr(&all->elem[i][0], "C ", 2)))
		{
			if (all->elem[i][o] == ',')
				counter++;
		}
		if (counter > 2)
			exit_perror(all);
	}
}
