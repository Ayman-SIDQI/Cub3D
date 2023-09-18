/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:29:14 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/18 10:39:35 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_2d(char **str)
{
	int	o;

	o = 0;
	if (!str)
		return ;
	while (str[o])
		free(str[o++]);
	free(str);
}

void	nullification(t_pov *all)
{
	int	i;

	i = -1;
	while (++i < 4)
		all->tc[i] = 0;
	i = -1;
	while (++i < 6)
		all->elem[i] = NULL;
	all->bm = NULL;
	all->map = NULL;
	all->swg = NULL;
}
