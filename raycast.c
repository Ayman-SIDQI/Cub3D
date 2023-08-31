/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:56 by hcharia           #+#    #+#             */
/*   Updated: 2023/08/31 15:03:29 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pov(char c, t_fil *all)
{
	if (c == 'N')
		all->angle = 270;
	if (c == 'W')
		all->angle = 180;
	if (c == 'E')
		all->angle = 0;
	if (c == 'S')
		all->angle = 90;
}

void	line_print(t_pov *all, int x, int y, int pxl)
{
	int	o;

	o = -1;
	while (++o < 100000 / pxl && o < 540)
		mlx_put_pixel(all->img, x, (y + o), 0xAAAAAAFF);
	while (o > 0)
	{
		mlx_put_pixel(all->img, x, (y - o), 0xAAAAAAFF);
		o--;
	}
}

void	graphic(void *name)
{
	t_pov	*all;
	int		j;
	double	xofwall;
	double	yofwall;
	double	distance;
	double	angle;

	all = name;
	j = -1;
	angle = all->map_info.angle;
	while (++j < 1920)
	{
		xofwall = all->map_info.bpx;
		yofwall = all->map_info.bpy;
		// printf ("%d\n", all->map_info.angle);
		distance = 0;
		while (all->big_map[(int)yofwall][(int)xofwall] != '1')
		{
			xofwall += cos((angle - 30 + j * 0.03125) * M_PI / 180);
			yofwall += sin((angle - 30 + j * 0.03125) * M_PI / 180);
			distance += sqrt(xofwall * xofwall + yofwall * yofwall);
			if (all->big_map[(int)yofwall][(int)(xofwall - cos((angle - 30 + j * 0.03125) * M_PI / 180))] == '1' \
				&& all->big_map[(int)(yofwall - sin((angle - 30 + j * 0.03125) * M_PI / 180))][(int)xofwall] == '1')
				break ;
			if (xofwall < 0 || xofwall > 1920 || yofwall < 0 || yofwall > 1080)
				break ;
			mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
		}
		//wallheight = (64 / distance) * 540 / tan(30);
		line_print(all, j, 540, distance / 10);
	}
}

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
				mlx_put_pixel(all->img, o, i, 0xBBBBBBFF);
		}
	}
}

void	sprite_dance(void *name)
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
