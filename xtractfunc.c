/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtractfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:18:05 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/30 00:53:42 by asidqi           ###   ########.fr       */
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

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

bool	filtr(char **arr)
{
	int	i;


	i = -1;
	while (++i < 3)
	{
		//is digit
		if (ft_atoi(arr[i]) == 0 && ft_strncmp(arr[i], "0", ft_strlen(arr[i])))
			return (true);
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
			return (true);
	}
	return (false);
}

char	*s_spc(char *l)
{
	while (*l && *l <= ' ')
		l++;
	return (l);
}

void	cf_ext(t_pov *all)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (ft_strnstr(s_spc(all->elem[i]), "F ", 2))
			all->map_info.f = ft_split(ft_strnstr(s_spc(all->elem[i]), "F ", 2) + 1, ',');
		else if (ft_strnstr(s_spc(all->elem[i]), "C ", 2))
			all->map_info.c = ft_split(ft_strnstr(s_spc(all->elem[i]), "C", 2) + 1, ',');
	}
	if (filtr(all->map_info.f) || filtr(all->map_info.c))
	{
		exit_perror();
		return ;
	} //free 2d arrays here
	all->map_info.fn = ft_pixel(ft_atoi(all->map_info.f[0]), \
	ft_atoi(all->map_info.f[1]), ft_atoi(all->map_info.f[2]), 0);
	all->map_info.cn = ft_pixel(ft_atoi(all->map_info.c[0]), \
	ft_atoi(all->map_info.c[1]), ft_atoi(all->map_info.c[2]), 0);
}

bool	xelem(t_pov *all)
{
	int	i;

	i = 0;
	all->elem[i] = get_next_line(all->fd);
	while (i < 6 && (all->elem[i] != NULL))
	{
		if (ft_strnstr(s_spc(all->elem[i]), "NO ", 3) \
		|| ft_strnstr(s_spc(all->elem[i]), "SO ", 3) \
		|| ft_strnstr(s_spc(all->elem[i]), "WE ", 3) \
		|| ft_strnstr(s_spc(all->elem[i]), "EA ", 3) \
		|| ft_strnstr(s_spc(all->elem[i]), "F ", 2) \
		|| ft_strnstr(s_spc(all->elem[i]), "C ", 2))
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
