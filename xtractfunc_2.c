/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtractfunc_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:25:48 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/28 20:49:32 by asidqi           ###   ########.fr       */
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

void	link_toarr(t_list *lst, int n, t_pov *all)
{
	char	**array;
	char	**big_array;
	int		i;
	int		big_i;

	i = -1;
	big_i = 0;
	array = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	big_array = (char **)malloc(sizeof(char *) * ((ft_lstsize(lst) * n) + 1));
	if (!array || !big_array)
		return ;
	while (lst->next)
	{
		array[++i] = ft_strdup(lst->content);
		if (big_i % n == 0)
			big_array = repeated(big_array, n, big_i, \
			big_strdup(lst->content, n));
		lst = lst->next;
		big_i += N;
	}
	array[i + 1] = NULL;
	big_array[big_i] = NULL;
	all->map = array;
	all->big_map = big_array;
}

void	check_borders(t_list *map_info, t_pov *all)
{
	int	i;

	link_toarr(map_info, N, all);
	ft_lstclear(&all->map_2d, &free);
	i = 0;
	while (all->map[i])
	{
		if (find_zeros(i, all->map))
			exit_perror();
		i++;
	}
}
