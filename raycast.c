/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:56 by hcharia           #+#    #+#             */
/*   Updated: 2023/09/02 17:47:26 by hcharia          ###   ########.fr       */
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

void	line_print(t_pov *all, int x, int pxl)
{
	int				o;
	int				down;
	static int 		right;
	static int		b;
	int			a;

	o = SCREENHIGH / 2 - pxl / 2;
	a = 0;
	down = -1;
	while (++o < SCREENHIGH / 2 + pxl / 2)
	{
		down ++;
		if (down == pxl / 16)
		{
			down = -1;
			a++;	
		}
		if (o < SCREENHIGH && o > 0)
			mlx_put_pixel(all->img, x, o, 
			ft_pixel(all->wal[0]->pixels[x % pxl / 16 + 0 + (a % pxl / 16) * all->wal[0]->width], 
					all->wal[0]->pixels [x % pxl / 16 + 1 + (a % pxl / 16) * all->wal[0]->width], 
					all->wal[0]->pixels [x % pxl / 16 + 2 + (a % pxl / 16) * all->wal[0]->width], 
					all->wal[0]->pixels [x % pxl / 16 + 3 + (a % pxl / 16) * all->wal[0]->width]));
	}
	right++;
	if (right == pxl / 16)
	{
		b++;
		right = 0;
	}
}

// void	graphic(void *name)
// {
// 	t_pov	*all;
// 	int		j;
// 	double	xofwall;
// 	double	yofwall;
// 	double	distance;
// 	double	angle;
// 	double	wallheight;
	
// 	all = name;
// 	j = -1;
// 	angle = all->map_info.angle;
// 	while (++j < 1920)
// 	{
// 		xofwall = all->map_info.bpx;
// 		yofwall = all->map_info.bpy;
// 		distance = 0;
// 		while (all->big_map[(int)yofwall][(int)xofwall] != '1')
// 		{
// 			xofwall += cos((angle - 30 + j * 0.03125) * M_PI / 180) * 0.06;
// 			yofwall += sin((angle - 30 + j * 0.03125) * M_PI / 180) * 0.06;
			
// 			if (all->big_map[(int)yofwall][(int)(xofwall - cos((angle - 30 + j * 0.03125) * M_PI / 180))] == '1' \
// 				&& all->big_map[(int)(yofwall - sin((angle - 30 + j * 0.03125) * M_PI / 180))][(int)xofwall] == '1')
// 				break ;
// 			if (xofwall < 0 || xofwall > 1920 || yofwall < 0 || yofwall > 1080)
// 				break ;
// 			mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
// 		}
// 		distance = sqrt((xofwall - all->map_info.bpx) * (xofwall - all->map_info.bpx) + (yofwall - all->map_info.bpy) * (yofwall - all->map_info.bpy)) * cos((- 30 + j * 0.03125) * M_PI / 180);
// 		// wallheight = -(64 / distance) * 540 / tan(30);
// 		wallheight = (16 * 1080) / distance;
// 		printf("%f\n", wallheight);
// 		// line_print(all, j, 540, wallheight);
// 	}
// }

float raycast(t_pov *all,float xofwall,float yofwall, int screenpos)
{
	while (all->big_map[(int)yofwall][(int)xofwall] != '1')
		{
			xofwall += cos((all->map_info.angle - FOV / 2 +
			 screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180) * 0.5;
			yofwall += sin((all->map_info.angle - FOV / 2 +
			 screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180) * 0.5;
			if (all->big_map[(int)yofwall][(int)(xofwall - cos((all->map_info.angle \
			- FOV / 2 + screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180))] == '1' \
				&& all->big_map[(int)(yofwall - sin((all->map_info.angle - FOV / 2 + \
				screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180))][(int)xofwall] == '1')
				break ;
			if (xofwall < 0 || xofwall > SCREENWIDTH || yofwall < 0 || yofwall > 1080)
				break ;
			mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
		}
		return (sqrt((xofwall - all->map_info.bpx) * (xofwall - all->map_info.bpx) 
		+ (yofwall - all->map_info.bpy) * (yofwall - all->map_info.bpy)) 
		* cos((- 30 + screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180));
}

void	graphic(void *name)
{
	t_pov	*all;
	int		screenpos;
	double	xofwall;
	double	yofwall;
	double	distance;
	double	wallheight;
	
	all = name;
	screenpos = -1;
	while (++screenpos < SCREENWIDTH)
	{
		xofwall = all->map_info.bpx;
		yofwall = all->map_info.bpy;
		distance = raycast(all, xofwall, yofwall, screenpos);
		//wallheight = -(64 / distance) * 540 / tan(30);
		 wallheight = (16 * 1080) / distance;
		//printf("%f\n", wallheight);
		line_print(all, screenpos, wallheight);
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

// void	example(void *name)
// {
// 	t_pov		*all;
// 	static int	pop;
// 	// static int 	s;

// 	all = name;
// 	pop++;
// 	if (all->wal_img)
// 		mlx_delete_image(all->mlx, all->wal_img);
// 	all->wal_img = mlx_texture_to_image(all->mlx, all->wal[pop]);
// 	mlx_image_to_window(all->mlx, all->wal_img, 300, 300);
// 	if (pop == 3)
// 		pop -= 3;
// }
