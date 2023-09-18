/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonufication.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:09:00 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/18 15:24:32 by asidqi           ###   ########.fr       */
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
	while (all->bm[++i])
	{
		o = -1;
		while (all->bm[i][++o])
		{
			if (all->bm[i][o] == '1')
				mlx_put_pixel(all->img, o, i, 0xC35B00FF);
			else if (all->bm[i][o] == '0')
			{
				if (i % N == 0 || o % N == 0)
					mlx_put_pixel(all->img, o, i, 0x00000000);
				else
					mlx_put_pixel(all->img, o, i, 0xBBBBBBFF);
			}
		}
	}
	i = -1;
	while (++i < SWIDTH)
		drawline(all, all->map_info.xwall[i], all->map_info.ywall[i]);
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
	if (!all->wal[*j])
	{
		printf("Error\n");
		system("leaks cub3D");
		exit(1);
	}
	all->tc[*j] = malloc(all->wal[*j]->width \
	* all->wal[*j]->height * sizeof(int));
	if (!all->tc[*j])
		exit_perror(all);
}

char	*sns(char **elem, char *s)
{
	int	i;

	i = -1;
	while (elem[++i] && ft_strncmp(elem[i], s, 3))
		;
	return (elem[i] + 3);
}

void	init_frm(t_pov *all)
{
	int		j;
	char	*joined;

	j = -1;
	load_wall_and_allocate_tc(all, &j, sns(all->elem, "NO "));
	load_wall_and_allocate_tc(all, &j, sns(all->elem, "SO "));
	load_wall_and_allocate_tc(all, &j, sns(all->elem, "WE "));
	load_wall_and_allocate_tc(all, &j, sns(all->elem, "EA "));
	colorize_swg(all, joined);
}
