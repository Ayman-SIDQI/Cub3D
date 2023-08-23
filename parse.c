/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:41:59 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/23 22:30:53 by asidqi           ###   ########.fr       */
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

void	checkname(char *filename)
{
	int		i;
	int		j;
	char	*rstr;

	i = 0;
	j = 0;
	rstr = "buc.";
	if (!filename)
	{
		perror("Error\nwhere is the map my boi?\n");
		exit (1);
	}
	while (filename[i])
		i++;
	i--;
	while (filename[i] == rstr[j])
	{
		j++;
		i--;
	}
	if (j == 4)
		return ;
	exit_perror();
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
	// int i = 0;
	// while (all->map_2d)
	// {
	// 	printf("%s\n", all->map_2d->content);
	// }
	return (false);
}

void	jm3str(char *av, t_pov *all)
{
	int	i;

	i = 0;
	all->fd = open(av, O_RDONLY);
	if (xelem(all) || xmap(all))
	{
		close(all->fd);
		return ;
	}
	close(all->fd);
}

bool	parse(char *fmap, t_pov *all)
{
	checkname(fmap);
	jm3str(fmap, all);
	return (true);
}
