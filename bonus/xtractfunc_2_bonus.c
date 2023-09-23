/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtractfunc_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:25:48 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/21 17:14:44 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	find_zeros(int i, char **map)
{
	int	o;

	o = 0;
	while (map[i][o] != '\0')
	{
		if (map[i][o] == '0' || map[i][o] == 'N' || map[i][o] == 'E' \
		|| map[i][o] == 'W' || map[i][o] == 'S')
		{
			if (i == 0 || (ft_strlen(map[i - 1]) < o) \
			|| (!(map[i - 1][o]) || map[i - 1][o] <= ' '))
				return (true);
			if ((ft_strlen(map[i + 1]) < o) || (!(map[i + 1][o]) \
			|| map[i + 1][o] <= ' '))
				return (true);
			if ((!(map[i][o + 1]) || map[i][o + 1] <= ' '))
				return (true);
			if ((!(map[i][o - 1]) || map[i][o - 1] <= ' '))
				return (true);
		}
		o++;
	}
	return (false);
}

char	map_char(char input)
{
	if (input == 'S' || input == 'N' || input == 'E' || input == 'W')
		return ('0');
	else
		return (input);
}

char	**repeated(char **r, int n, int big_i, char *rep)
{
	int	i;

	i = 0;
	while (i != n)
	{
		r[big_i] = rep;
		i++;
		big_i++;
	}
	return (r);
}

int	which_width(t_pov *all)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	j = 0;
	w = ft_strlen(all->map[0]);
	while (all->map[++i])
	{
		if (ft_strlen(all->map[i]) > w)
			w = ft_strlen(all->map[i]);
	}
	return (w);
}

void	link_toarr(t_list *lst, int n, t_pov *all)
{
	char	**array;
	int		i;
	int		big_i;
	t_list	*tmp;

	i = -1;
	big_i = 0;
	tmp = lst;
	all->map = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	all->bm = (char **)malloc(sizeof(char *) * ((ft_lstsize(lst) * n) + 1));
	if (!all->map || !all->bm)
		return ;
	while (tmp->next)
	{
		all->map[++i] = ft_strdup(tmp->content);
		if (big_i % n == 0)
			all->bm = repeated(all->bm, n, big_i, big_strdup(tmp->content, n));
		tmp = tmp->next;
		big_i += N;
	}
	all->map[i + 1] = NULL;
	all->bm[big_i] = NULL;
	all->map_info.hmap = (ft_lstsize(lst) - 1);
	all->map_info.wmap = which_width(all);
}
