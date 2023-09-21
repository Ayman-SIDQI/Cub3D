/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:56 by hcharia           #+#    #+#             */
/*   Updated: 2023/09/21 10:00:21 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	israyfacingup(float angle)
{
	if (angle > 0 && angle < M_PI)
		return (0);
	else
		return (1);
}

float	calcdistance(t_pov	*all, float x, float y)
{
	float	distance;

	distance = sqrt((x / N - all->map_info.bpx / N) \
	* (x / N - all->map_info.bpx / N) + (y / N - all->map_info.bpy / N) \
	* (y / N - all->map_info.bpy / N));
	return (distance);
}

float	raycast(t_pov	*all, float angle)
{
	float	hor;
	float	vert;

	horzontal(all, angle);
	vertical(all, angle);
	hor = calcdistance(all, all->map_info.xhwall, all->map_info.yhwall);
	vert = calcdistance(all, all->map_info.xvwall, all->map_info.yvwall);
	if (hor > vert)
		return (all->map_info.direct = 'v', vert);
	else
		return (all->map_info.direct = 'h', hor);
}

void	rc(t_pov *all, int j)
{
	all->agl = all->njm + j * all->angin;
	if (all->agl > 2 * M_PI)
		all->agl -= 2 * M_PI;
	if (all->agl < 0)
		all->agl += 2 * M_PI;
	all->line_high = SHEIGH / (raycast(all, all->agl) \
	* cos(all->agl - all->map_info.angle));
	all->hs = SHEIGH / 2 + (all->line_high / 2);
	all->line_start = SHEIGH / 2 - (all->line_high / 2);
	all->yt = 0;
}

void	graphic(void *name)
{
	t_pov	*all;
	int		j;

	j = -1;
	all = name;
	all->njm = all->map_info.angle - FOV / 2.0;
	all->angin = (float)FOV / (float)SWIDTH;
	while (++j < SWIDTH)
	{
		rc(all, j);
		if (israyfacingright(all->agl) && all->map_info.direct == 'v')
			all->compus = 0;
		else if (!israyfacingright(all->agl) && all->map_info.direct == 'v')
			all->compus = 1;
		else if (!israyfacingup(all->agl) && all->map_info.direct == 'h')
			all->compus = 2;
		else if (israyfacingup(all->agl) && all->map_info.direct == 'h')
			all->compus = 3;
		all->yinc = (float)(all->hs - all->line_start)
			/ all->wal[all->compus]->height;
		while (all->yt < all->wal[all->compus]->width)
			cog(all, j);
		coor_fill(all, j);
	}
}
