/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:56 by hcharia           #+#    #+#             */
/*   Updated: 2023/09/16 15:09:24 by asidqi           ###   ########.fr       */
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
		all->angle = 0;
	if (c == 'S')
		all->angle = 90 * M_PI / 180;
}

int	israyfacingup(float angle)
{
	if (angle > 0 && angle < M_PI)
		return (0);
	else
		return (1);
}

int	israyfacingright(float angle)
{
	if (angle > (0.5 * M_PI) && angle < (1.5 * M_PI))
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

int	wallhit(t_pov *all, float x, float y)
{
	if (y / N < 0 || y / N > all->map_info.hmap \
	|| x / N > ft_strlen(all->map[(int)y / N]) || x / N < 0)
		return (1);
	if (all->map[(int)y / N][(int)x / N] == '1')
		return (1);
	return (0);
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

void	drawline (t_pov *all, float xwall, float ywall)
{
	int		dx;
	int		dy;
	int		steps;
	float 	xstep;
	float 	ystep;
	int		i;
	float	x;
	float	y;

	i = -1;
	dx = xwall - all->map_info.bpx;
	dy = ywall - all->map_info.bpy;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xstep = (float) dx / steps;
	ystep = (float) dy / steps;
	x = all->map_info.bpx;
	y = all->map_info.bpy;
	while (++i <= steps)
	{
		if (y < SHEIGH && y >= 0 && x >= 0 && x < SWIDTH)
			mlx_put_pixel(all->img, (int)x, (int)y, 0x000000);
		x += xstep;
		y += ystep; 
	}
}

void	vertical(t_pov *all, float angle)
{
	float	nextx;
	float	nexty;
	int		xstep;
	float	ystep;

	nextx = floor(all->map_info.bpx / N) * N;
	if (israyfacingright(angle))
		nextx += N;
	else
		nextx -= 0.000024;
	nexty = all->map_info.bpy + (nextx - all->map_info.bpx) * tan(angle);
	xstep = N;
	if (!israyfacingright(angle))
		xstep *= -1;
	ystep = N * tan(angle);
	if ((ystep > 0 && israyfacingup(angle)) \
	|| (ystep < 0 && !israyfacingup(angle)))
		ystep *= -1;
	while (!wallhit(all, nextx, nexty))
	{
		if (wallhit(all, nextx + N, nexty) && !israyfacingright(angle))
			break ;
		nextx += xstep;
		nexty += ystep;
	}
	all->map_info.xvwall = nextx;
	all->map_info.yvwall = nexty;
}

float	raycast(t_pov	*all, float	angle)
{
	float	hor;
	float	vert;

	horzontal(all, angle);
	vertical(all, angle);
	hor = calcdistance(all, all->map_info.xhwall, all->map_info.yhwall);
	vert = calcdistance(all, all->map_info.xvwall, all->map_info.yvwall);
	if (hor > vert)
	{
		all->map_info.direct = 'v';
		drawline (all, all->map_info.xvwall, all->map_info.yvwall);
		return (vert);
	}
	else
	{
		all->map_info.direct = 'h';
		drawline (all, all->map_info.xhwall, all->map_info.yhwall);
		return (hor);
	}
}

void	graphic(void *name)
{
	t_pov	*all;
	int		j;
	float	angle; 
	float	star;
	float	angin;
	float	lineH;

	j = -1;
	all = name;
	star = all->map_info.angle - FOV / 2.0;
	angin = (float)FOV / (float)SWIDTH;
	while (++j < SWIDTH)
	{
		angle = star + j * angin;
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
		if (angle < 0)
			angle += 2 * M_PI;
		lineH = SHEIGH / (raycast(all, angle) * cos(angle - all->map_info.angle));
		float	hs = lineH + (SHEIGH / 2 - (lineH / 2));
		int y = -1;
		float	line_start = SHEIGH / 2 - (lineH / 2);
		float	yinc = (float) (hs - line_start) / all->wal[0]->height;
		float	idx = 0;
		int		xt;
		float	yt;
		float	temp;
		if (israyfacingright(angle) && all->map_info.direct == 'v')
			all->compus = 0;
		else if (!israyfacingright(angle) && all->map_info.direct == 'v')
			all->compus = 1;
		else if (!israyfacingup(angle) && all->map_info.direct == 'h')
			all->compus = 2;
		else if (israyfacingup(angle) && all->map_info.direct == 'h')
			all->compus = 3;
		while (idx < all->wal[all->compus]->width)
		{
			if( all->map_info.direct == 'h')
				xt = (int)(all->map_info.xhwall * (all->wal[all->compus]->width / N)) %  all->wal[all->compus]->width;
			else
				xt = (int)(all->map_info.yvwall * (all->wal[all->compus]->width / N)) %  all->wal[all->compus]->width;
			temp = line_start;
			while (temp < line_start + yinc)
			{
				int i = idx * all->wal[all->compus]->width + xt;
				if (temp >= 0 && temp <= SHEIGH)
					mlx_put_pixel(all->img, j, temp, all->tc[all->compus][i]);
				temp++;
			}
			idx++;
			line_start += yinc;
		}
	}
}
