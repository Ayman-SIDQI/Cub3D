/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:41:59 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/24 11:22:43 by asidqi           ###   ########.fr       */
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

void	jm3str(char *av, t_pov *all)
{
	int	i;

	i = 0;
	all->fd = open(av, O_RDONLY);
	if (xelem(all) || xmap(all) || filter_m(all))
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
