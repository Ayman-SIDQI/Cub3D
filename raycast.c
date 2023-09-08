/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:56 by hcharia           #+#    #+#             */
/*   Updated: 2023/09/08 18:52:36 by hcharia          ###   ########.fr       */
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

void    graphic(void *name)
{
	t_pov	*all;
	int		j;
	float	angle;
	float	xofwall;
	float	yofwall;
	float	old_x_w;
	float	old_y_w;
	float	distance;
	float	lineH;
	int		y;
	int		line_start;
	
	j = -1;
	all = name;
	while (++j < SWIDTH)
	{
		xofwall = all->map_info.px;
		yofwall = all->map_info.py;
		angle = all->map_info.angle - 30 + j * FOV / SWIDTH; 
		while (all->map[(int)yofwall][(int)xofwall] != '1')
		{
			old_x_w = xofwall;
			old_y_w = yofwall;
			xofwall += cos(angle * M_PI / 180) * 0.01;
			yofwall += sin(angle * M_PI / 180) * 0.01;
			if ((all->map[(int)yofwall][(int)old_x_w] == '1' \
			&& all->map[(int)old_y_w][(int)xofwall] == '1') || xofwall < 0 \
				|| xofwall > 1920 || yofwall < 0 || yofwall > 1080)
				break;
			else
				mlx_put_pixel(all->img, xofwall * 16 + (int)xofwall % 16, yofwall * 16 + (int)yofwall % 16, 0xBBBBDD00);	
		}
		distance = sqrt((xofwall - all->map_info.px) * (xofwall - all->map_info.px) \
		+ (yofwall - all->map_info.py) * (yofwall - all->map_info.py));
		lineH = SHIGH / distance;
		y = -1;
		line_start = SHIGH / 2 - lineH / 2;
		while (++y < (int)lineH)
		{
			if (line_start + y >= SHIGH)
				break;
			else if (line_start + y >= 0)
			{
				if ((int)angle % 360 >= 0 && (int)angle % 360 < 90)
					mlx_put_pixel(all->img, j, y + (int)line_start, 0xda6d56);
				else if ((int)angle % 360 >= 90 && (int)angle % 360 < 180)
					mlx_put_pixel(all->img, j, y + (int)line_start, 0xAAAAAA);
				else if ((int)angle % 360 >= 180 && (int)angle % 360 < 270)
					mlx_put_pixel(all->img, j, y + (int)line_start, 0xBBBBBB);
				else if ((int)angle % 360 >= 270 && (int)angle % 360 < 360)
					mlx_put_pixel(all->img, j, y + (int)line_start, 0xCCCCCC);
			}
				
		}
		
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








// void    graphic(void *name)
// {
// 	t_pov	*all;
// 	int		j;
// 	float	xofwall;
// 	float	yofwall;
// 	float	distance;
// 	double	angle;
// 	float	wallheight;
// 	int		start_point;
// 	double	x_percentage;
// 	double	old_x_ray, old_y_ray;

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
// 			old_x_ray = xofwall;
// 			old_y_ray = yofwall;
// 			xofwall += cos((angle - 30 + j * 0.03125) * M_PI / 180) * 0.03;
// 			yofwall += sin((angle - 30 + j * 0.03125) * M_PI / 180) * 0.03;
			
// 			if (all->big_map[(int)yofwall][(int)(xofwall - cos((angle - 30 + j * 0.03125) * M_PI / 180))] == '1' \
// 				&& all->big_map[(int)(yofwall - sin((angle - 30 + j * 0.03125) * M_PI / 180))][(int)xofwall] == '1')
// 				break ;
// 			if (xofwall < 0 || xofwall > 1920 || yofwall < 0 || yofwall > 1080)
// 				break ;
// 			if ((int)(j * 0.03125) == 30)
// 				mlx_put_pixel(all->img, xofwall, yofwall, 0xff000000);
// 			else
// 				mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
// 		}

// 		xofwall /= 16;
// 		yofwall /= 16;
// 		old_x_ray /= 16;
// 		old_y_ray /= 16;
		
// 		{
// 			if ((int)xofwall != (int)old_x_ray)
// 			{
// 				xofwall = (int)xofwall;
// 				yofwall = (old_y_ray / old_x_ray) * (xofwall - old_x_ray) + old_y_ray;
// 				x_percentage = yofwall - (int)yofwall;
// 			}
// 			else
// 			{
// 				yofwall = (int)yofwall;
// 				xofwall = (old_x_ray / old_y_ray) * (yofwall - old_y_ray) + old_x_ray;
// 				x_percentage = xofwall - (int)xofwall;
// 			}
// 		}
// 		// distance = sqrt((xofwall - all->map_info.px) * (xofwall - all->map_info.px) 
// 		// + (yofwall - all->map_info.py) * (yofwall - all->map_info.py)) * cos((- 30 + j * 0.03125) * M_PI / 180);
		
// 		distance = sqrt((xofwall - all->map_info.bpx / 16) * (xofwall - all->map_info.bpx / 16) 
// 		+ (yofwall - all->map_info.bpy / 16) * (yofwall - all->map_info.bpy / 16)) * cos((- 30 + j * 0.03125) * M_PI / 180);
// 		wallheight = (1080 / distance);
// 		// printf(" dist %f\n", all->map_info.bpy);
// 		start_point = SCREENHIGH / 2 - wallheight / 2;

// 		double	slop = 256.0 / wallheight;
// 		double	b = - slop * start_point;
// 		int		x_pos = (int)(x_percentage * 256);
// 		int	y = -1;
// 		while (++y < (int)wallheight)
// 		{
// 			if (start_point + y >= SCREENHIGH)
// 				break ;
// 			else if (start_point + y >= 0)
// 			{
// 				int	y_pos = slop * (double)(start_point + y) + b;
// 				//mlx_put_pixel(all->img, j, y + start_point, all->tc[0][y_pos * 256 + x_pos]);
// 				mlx_put_pixel(all->img, j, y + start_point, 0xda6d56);
// 			}
// 		}
// 	}
// }