/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:56 by hcharia           #+#    #+#             */
/*   Updated: 2023/09/04 18:38:14 by hcharia          ###   ########.fr       */
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

void	line_print(t_pov *all, int x, int xwall, int pxl)
{
	int				y;
	int				a;
	 int			b;

	y = SCREENHIGH / 2 - pxl / 2;
	a = 0;
	b = 0;
	while (++y < SCREENHIGH / 2 + pxl / 2)
	{
		if (y < SCREENHIGH && y > 0)
		{
			if (b == 16)
			{
				a++;
				b = 0;
			}
			mlx_put_pixel(all->img, x, y, all->tc[0][xwall % pxl / 16 + a * 16]);
			b++;
		}
	}

}

void    graphic(void *name)
{
	t_pov	*all;
	int		j;
	double	xofwall;
	double	yofwall;
	double	distance;
	double	angle;
	int		wallheight;
	int		ytla3;	
	// int		a;
	// int		b;

	double	x_percentage;
	double	old_x_ray, old_y_ray;

	all = name;
	j = -1;
	angle = all->map_info.angle;// + 30 + j * 0.03125;
	
	while (++j < 1920)
	{
		xofwall = all->map_info.bpx;
		yofwall = all->map_info.bpy;
		distance = 0;
		while (all->big_map[(int)yofwall][(int)xofwall] != '1')
		{
			old_x_ray = xofwall;
			old_y_ray = yofwall;
			xofwall += cos((angle - 30 + j * 0.03125) * M_PI / 180) * 0.03;
			yofwall += sin((angle - 30 + j * 0.03125) * M_PI / 180) * 0.03;
			
			if (all->big_map[(int)yofwall][(int)(xofwall - cos((angle - 30 + j * 0.03125) * M_PI / 180))] == '1' \
				&& all->big_map[(int)(yofwall - sin((angle - 30 + j * 0.03125) * M_PI / 180))][(int)xofwall] == '1')
				break ;
			if (xofwall < 0 || xofwall > 1920 || yofwall < 0 || yofwall > 1080)
				break ;
			if ((int)(j * 0.03125) == 30)
				mlx_put_pixel(all->img, xofwall, yofwall, 0xff000000);
			else
				mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
		}

		distance = sqrt((xofwall - all->map_info.bpx) * (xofwall - all->map_info.bpx) + (yofwall - all->map_info.bpy) * (yofwall - all->map_info.bpy)) * cos((- 30 + j * 0.03125) * M_PI / 180);
		wallheight = (1080) / distance;
		
		{
			if ((int)xofwall != (int)old_x_ray)
			{
				xofwall = (int)xofwall;
				yofwall = (old_y_ray / old_x_ray) * (xofwall - old_x_ray) + old_y_ray;
				x_percentage = yofwall - (int)yofwall;
			}
			else
			{
				yofwall = (int)yofwall;
				xofwall = (old_x_ray / old_y_ray) * (yofwall - old_y_ray) + old_x_ray;
				x_percentage = xofwall - (int)xofwall;
			}
		}

		
		// printf("%lf - %lf  [%lf, %lf] {%lf, %lf}\n", xofwall, yofwall, old_x_ray, old_y_ray, all->map_info.bpx, all->map_info.bpy);
		
		ytla3 = SCREENHIGH / 2 - wallheight / 2;
		// a = 0;
		// b = 0;

		double	slop = 16.0 / wallheight;
		double	b = - slop * ytla3;
		int		x_pos = x_percentage * 16;
		// --ytla3;
		int	y = -1;
		while (++y < (int)wallheight)
		{
			if (ytla3 + y >= SCREENHIGH)
				break ;
			else if (ytla3 + y >= 0)
			{
				// printf("[%d -- %f]\n", y, wallheight);
				int	y_pos = slop * (double)(ytla3 + y) + b;
				(void)x_pos;(void)y_pos;
				// if (x_pos > 15 || y_pos > 15 || y == (int)wallheight - 1 || 1)
				// 	printf("[%d %d] {%u}\n", x_pos, y_pos, all->tc[0][y_pos * 16 + x_pos]);
				mlx_put_pixel(all->img, j, y + ytla3, all->tc[0][y_pos * 16 + x_pos]);
			}
		}
		//line_print(all, j, xofwall, wallheight);
	}
}

// float raycast(t_pov *all,float xofwall,float yofwall, int screenpos)
// {
// 	while (all->big_map[(int)yofwall][(int)xofwall] != '1')
// 		{
// 			xofwall += cos((all->map_info.angle - FOV / 2 +
// 			 screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180) * 0.5;
// 			yofwall += sin((all->map_info.angle - FOV / 2 +
// 			 screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180) * 0.5;
// 			if (all->big_map[(int)yofwall][(int)(xofwall - cos((all->map_info.angle \
// 			- FOV / 2 + screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180))] == '1' \
// 				&& all->big_map[(int)(yofwall - sin((all->map_info.angle - FOV / 2 + \
// 				screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180))][(int)xofwall] == '1')
// 				break ;
// 			if (xofwall < 0 || xofwall > SCREENWIDTH || yofwall < 0 || yofwall > 1080)
// 				break ;
// 			mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
// 		}
// 		return (sqrt((xofwall - all->map_info.bpx) * (xofwall - all->map_info.bpx) 
// 		+ (yofwall - all->map_info.bpy) * (yofwall - all->map_info.bpy)) 
// 		* cos((- 30 + screenpos * (float) FOV / SCREENWIDTH) * M_PI / 180));
// }

// void	graphic(void *name)
// {
// 	t_pov	*all;
// 	int		screenpos;
// 	double	xofwall;
// 	double	yofwall;
// 	double	distance;
// 	double	wallheight;
	
// 	all = name;
// 	screenpos = -1;
// 	while (++screenpos < SCREENWIDTH)
// 	{
// 		xofwall = all->map_info.bpx;
// 		yofwall = all->map_info.bpy;
// 		distance = raycast(all, xofwall, yofwall, screenpos);
// 		//wallheight = -(64 / distance) * 540 / tan(30);
// 		 wallheight = (16 * 1080) / distance;
// 		//printf("%f\n", wallheight);
// 		line_print(all, screenpos, wallheight);
// 	}
// }

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
