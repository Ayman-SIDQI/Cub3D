/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:25:27 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/18 17:37:12 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*big_strdup(char *s1, size_t n)
{
	char	*new;
	size_t	i;
	size_t	o;
	size_t	t;

	i = 0;
	o = -1;
	t = -1;
	new = (char *)malloc (sizeof(char) * ((ft_strlen(s1) * n) + 1));
	if (!new)
		return (0);
	new[(ft_strlen(s1) * n)] = '\0';
	while (++o != ft_strlen(s1))
	{
		t = -1;
		while (++t != n)
		{
			new[i] = map_char(s1[o]);
			i++;
		}
	}
	return (new);
}

void	cog(t_pov *all, int j)
{
	int	i;

	all->yinc = (float)(all->hs - all->line_start)
		/ all->wal[all->compus]->height;
	if (all->map_info.direct == 'h')
		all->xt = (int)(all->map_info.xhwall \
		* (all->wal[all->compus]->width / N)) % all->wal[all->compus]->width;
	else
		all->xt = (int)(all->map_info.yvwall \
		* (all->wal[all->compus]->width / N)) % all->wal[all->compus]->width;
	all->temp = all->line_start;
	while (all->temp < all->line_start + all->yinc)
	{
		i = all->idx * all->wal[all->compus]->width + all->xt;
		if (all->temp >= 0 && all->temp < SHEIGH)
			mlx_put_pixel(all->img, j, all->temp, all->tc[all->compus][i]);
		all->temp++;
	}
	all->idx++;
	all->line_start += all->yinc;
}

void	drawline(t_pov *all, float xwall, float ywall)
{
	int		dx;
	int		dy;
	int		i;
	float	x;
	float	y;

	i = -1;
	dx = xwall - all->map_info.bpx;
	dy = ywall - all->map_info.bpy;
	if (abs(dx) > abs(dy))
		all->steps = abs(dx);
	else
		all->steps = abs(dy);
	all->xstep = (float) dx / all->steps;
	all->ystep = (float) dy / all->steps;
	x = all->map_info.bpx;
	y = all->map_info.bpy;
	while (++i <= all->steps)
	{
		if (y < SHEIGH && y >= 0 && x >= 0 && x < SWIDTH)
			mlx_put_pixel(all->img, (int)x, (int)y, 0x000000);
		x += all->xstep;
		y += all->ystep; 
	}
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

int	israyfacingright(float angle)
{
	if (angle > (0.5 * M_PI) && angle < (1.5 * M_PI))
		return (0);
	else
		return (1);
}
