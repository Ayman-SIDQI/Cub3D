/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:41:59 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/26 20:13:36 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	skip_empty(t_pov *all)
{
	t_list	*tmp;

	tmp = all->map_2d;
	while (tmp && (nasa(tmp->content)))
		tmp = tmp->next;
	while (tmp && (!nasa(tmp->content) || !tmp->content[0]))
		tmp = tmp->next;
	if (tmp && tmp->next)
		exit_perror();
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
	skip_empty(all);
	filter_m(all);
	close(all->fd);
}

char	**retrieve_py(char **map, t_fil *all)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'E') 
			|| ft_strchr(map[i], 'W') || ft_strchr(map[i], 'S'))
		{
			all->py = i;
			map[i][all->px] = '0';
			break ;
		}
	}
	return (map);
}

bool	parse(char *fmap, t_pov *all)
{
	checkname(fmap);
	jm3str(fmap, all);
	check_borders(all->map_2d, all);
	all->map = retrieve_py(all->map, &all->map_info);
	int i = -1;
	while (all->map[++i])
		printf("%s\n", all->big_map[i]);
	return (true);
}
