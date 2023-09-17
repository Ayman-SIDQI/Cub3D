/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonufication.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:09:00 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/16 22:36:29 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	minimap(void *name)
{
	t_pov	*all;
	int		i;
	int		o;

	all = name;
	i = -1;
	while (all->big_map[++i])
	{
		o = -1;
		while (all->big_map[i][++o])
		{
			if (all->big_map[i][o] == '1')
				mlx_put_pixel(all->img, o, i, 0xC35B00FF);
			else if (all->big_map[i][o] == '0')
			{
				if (i % N == 0 || o % N == 0)
					mlx_put_pixel(all->img, o, i, 0x00000000);
				else
					mlx_put_pixel(all->img, o, i, 0xBBBBBBFF);
			}
		}
	}
}

void	sprite_anim(void *name)
{
	t_pov		*all;
	static int	anima;

	all = name;
	anima++;
	if (all->swg)
		mlx_delete_image(all->mlx, all->swg);
	all->swg = mlx_texture_to_image(all->mlx, all->frm[(anima)]);
	mlx_image_to_window(all->mlx, all->swg, 940, 0);
	if (anima == 96)
		anima -= 96;
}

void	load_wall_and_allocate_tc(t_pov *all, int *j, char *wall_path)
{
	all->wal[++(*j)] = mlx_load_png(wall_path);
	all->tc[*j] = malloc(all->wal[*j]->width \
	* all->wal[*j]->height * sizeof(int));
	printf("tc[%d]:%p\n", *j, all->tc[*j]);
	if (!all->tc[*j] || all->wal[*j] == NULL)
		exit_perror(all);
}

void	init_frm(t_pov *all)
{
	int		i;
	int		j;
	char	*joined;

	i = -1;
	j = -1;
	load_wall_and_allocate_tc(all, &j, "./frames/walls/mages.png");
	load_wall_and_allocate_tc(all, &j, "./frames/walls/mages2.png");
	load_wall_and_allocate_tc(all, &j, "./frames/walls/mages3.png");
	load_wall_and_allocate_tc(all, &j, "./frames/walls/mages4.png");
	colorize_swg(all, joined);
}
