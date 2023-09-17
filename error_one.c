/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:14:21 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/16 22:07:34 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_perror(t_pov *all)
{
	int i;

	i = -1;
	if (all == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	while (++i < 4)
		free(all->tc[i]);
	free_2d(all->big_map);
	free_2d(all->map);
	free_2d(all->map);
	ft_lstclear(&all->map_2d, &free);
	perror("Error\nInvalid map ¯\\_(ツ)_/¯\n");
	exit(1);
}
