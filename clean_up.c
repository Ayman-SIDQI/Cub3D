/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:29:14 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/16 22:04:39 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_2d(char **str)
{
	int	o;

	o = 0;
	while (str[o])
		free(str[o++]);
	free(str);
}

void	nullification(t_pov *all)
{
	all->tc[0] = NULL;
	all->tc[1] = NULL;
	all->tc[2] = NULL;
	all->tc[3] = NULL;
	all->big_map = NULL;
	all->map = NULL;
	all->swg = NULL;
}
