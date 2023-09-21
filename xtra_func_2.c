/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:25:10 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/21 12:43:07 by asidqi           ###   ########.fr       */
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
	int		ystep;
	float	xstep;

	all->hny = floor(all->map_info.bpy / N) * N ;
	if (!israyfacingup(angle))
		all->hny += N;
	else
		all->hny -= 0.00008;
	all->hnx = all->map_info.bpx + (all->hny - all->map_info.bpy) / tan (angle);
	ystep = N;
	xstep = N / tan(angle);
	if (israyfacingup(angle))
		ystep *= -1;
	if ((!israyfacingright(angle) && xstep > 0) \
	|| (israyfacingright(angle) && xstep < 0))
		xstep *= -1;
	while (!wallhit(all, all->hnx, all->hny))
	{
		if (wallhit(all, all->hnx, all->hny + N) && israyfacingup(angle))
			break ;
		all->hnx += xstep;
		all->hny += ystep;
	}
	all->map_info.xhwall = all->hnx;
	all->map_info.yhwall = all->hny;
}

void	vertical(t_pov *all, float angle)
{
	int		xstep;
	float	ystep;

	all->v_nx = floor(all->map_info.bpx / N) * N;
	if (israyfacingright(angle))
		all->v_nx += N;
	else
		all->v_nx -= 0.00008;
	all->vny = all->map_info.bpy + (all->v_nx - all->map_info.bpx) * tan(angle);
	xstep = N;
	if (!israyfacingright(angle))
		xstep *= -1;
	ystep = N * tan(angle);
	if ((ystep > 0 && israyfacingup(angle)) \
	|| (ystep < 0 && !israyfacingup(angle)))
		ystep *= -1;
	while (!wallhit(all, all->v_nx, all->vny))
	{
		if (wallhit(all, all->v_nx + N, all->vny) && !israyfacingright(angle))
			break ;
		all->v_nx += xstep;
		all->vny += ystep;
	}
	all->map_info.xvwall = all->v_nx;
	all->map_info.yvwall = all->vny;
}

void	coor_fill(t_pov *all, int j)
{
	if (all->map_info.direct == 'v')
	{
		all->map_info.xwall[j] = all->map_info.xvwall;
		all->map_info.ywall[j] = all->map_info.yvwall;
	}
	if (all->map_info.direct == 'h')
	{
		all->map_info.xwall[j] = all->map_info.xhwall;
		all->map_info.ywall[j] = all->map_info.yhwall;
	}
}
