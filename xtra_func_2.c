/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:25:10 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/17 21:35:11 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pov(char c, t_fil *all)
{
	if (c == 'N')
		all->angle = 270 * M_PI / 180;
	if (c == 'W')
		all->angle = 180 * M_PI / 180;
	if (c == 'E')
		all->angle = 2 * M_PI;
	if (c == 'S')
		all->angle = 90 * M_PI / 180;
}

void	horzontal(t_pov	*all, float angle)
{
	float	nextx;
	double	nexty;
	int		ystep;
	float	xstep;

	nexty = floor(all->map_info.bpy / N) * N ;
	if (!israyfacingup(angle))
		nexty += N;
	else
		nexty -= 0.000024;
	nextx = all->map_info.bpx + (nexty - all->map_info.bpy) / tan (angle);
	ystep = N;
	xstep = N / tan(angle);
	if (israyfacingup(angle))
		ystep *= -1;
	if ((!israyfacingright(angle) && xstep > 0) \
	|| (israyfacingright(angle) && xstep < 0))
		xstep *= -1;
	while (!wallhit(all, nextx, nexty))
	{
		if (wallhit(all, nextx, nexty + N) && israyfacingup(angle))
			break ;
		nextx += xstep;
		nexty += ystep;
	}
	all->map_info.xhwall = nextx;
	all->map_info.yhwall = nexty;
}

void	vertical(t_pov *all, float angle)
{
	int		xstep;
	float	ystep;

	all->nx = floor(all->map_info.bpx / N) * N;
	if (israyfacingright(angle))
		all->nx += N;
	else
		all->nx -= 0.000024;
	all->ny = all->map_info.bpy + (all->nx - all->map_info.bpx) * tan(angle);
	xstep = N;
	if (!israyfacingright(angle))
		xstep *= -1;
	ystep = N * tan(angle);
	if ((ystep > 0 && israyfacingup(angle)) \
	|| (ystep < 0 && !israyfacingup(angle)))
		ystep *= -1;
	while (!wallhit(all, all->nx, all->ny))
	{
		if (wallhit(all, all->nx + N, all->ny) && !israyfacingright(angle))
			break ;
		all->nx += xstep;
		all->ny += ystep;
	}
	all->map_info.xvwall = all->nx;
	all->map_info.yvwall = all->ny;
}
