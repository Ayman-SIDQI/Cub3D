/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtractfunc_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:25:48 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/14 15:47:10 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	find_zeros(int i, char **map)
{
	int	o;

	o = 0;
	while (map[i][o] != '\0')
	{
		if (map[i][o] == '0' && 
			(((!(map[i - 1][o]) || map[i - 1][o] <= ' '))
			|| ((!(map[i + 1][o]) || map[i + 1][o] <= ' '))
			|| ((!(map[i][o + 1]) || map[i][o + 1] <= ' '))
			|| ((!(map[i][o - 1]) || map[i][o - 1] <= ' '))))
			return (true);
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

char	*big_strdup(char *s1, size_t n)
{
	char	*new;
	size_t	i;
	size_t	o;
	size_t	t;

	i = 0;
	o = -1;
	t = -1;
	new = (char *)malloc (sizeof(char) * ((ft_strlen(s1) * n) + 1));
	if (!new)
		return (0);
	new[(ft_strlen(s1) * n)] = '\0';
	while (++o != ft_strlen(s1))
	{
		t = -1;
		while (++t != n)
		{
			new[i] = map_char(s1[o]);
			i++;
		}
	}
	return (new);
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
	int	i = 0;
	int	j = 0;
	int	w = ft_strlen(all->map[0]);
	while (all->map[++i])
	{
		if(ft_strlen(all->map[i]) > w)
			w = ft_strlen(all->map[i]);
	}
	return (w);
}

void	link_toarr(t_list *lst, int n, t_pov *all)
{
	char	**array;
	char	**big_array;
	int		i;
	int		big_i;
	t_list *tmp;

	i = -1;
	big_i = 0;
	tmp = lst;
	array = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	big_array = (char **)malloc(sizeof(char *) * ((ft_lstsize(lst) * n) + 1));
	if (!array || !big_array)
		return ;
	while (tmp->next)
	{
		array[++i] = ft_strdup(tmp->content);
		if (big_i % n == 0)
			big_array = repeated(big_array, n, big_i, \
			big_strdup(tmp->content, n));
		tmp = tmp->next;
		big_i += N;
	}
	array[i + 1] = NULL;
	big_array[big_i] = NULL;
	all->map = array;
	all->big_map = big_array;
	all->map_info.hmap = (ft_lstsize(lst) - 1);//will cause pain
	all->map_info.wmap = which_width(all);
	printf ("the bigger width is %d\n", all->map_info.wmap);
	// printf("big_array[%zu]	array[%zu]", ft_strlen(*big_array), ft_strlen(*array));
	//printf("hmap[%d]	wmap[%zu]", all->map_info.hmap, ft_strlen(lst->content));
}
