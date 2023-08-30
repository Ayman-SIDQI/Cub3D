/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/30 16:26:17 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_2d(char **str)
{
	int	o;

	o = 0;
	while (str[o])
		free(str[o++]);
	free(str);
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

void	keys(void *name)
{
	t_pov	*all;

	all = name;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
	if (mlx_is_key_down(all->mlx, MLX_KEY_W))
	{
		if (all->big_map[(int)(all->map_info.bpy + sin(all->map_info.angle * M_PI / 180))][(int)(all->map_info.bpx + cos(all->map_info.angle * M_PI / 180))] == '1')
			return ;
		all->map_info.bpy += sin(all->map_info.angle * M_PI / 180);
		all->map_info.bpx += cos(all->map_info.angle * M_PI / 180);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_S))
	{
		if (all->big_map[(int)(all->map_info.bpy - sin(all->map_info.angle * M_PI / 180))][(int)(all->map_info.bpx - cos(all->map_info.angle * M_PI / 180))] == '1')
			return ;
		all->map_info.bpy -= sin(all->map_info.angle * M_PI / 180);
		all->map_info.bpx -= cos(all->map_info.angle * M_PI / 180);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_A))
	{
		if (all->big_map[(int)(all->map_info.bpy + sin((all->map_info.angle * M_PI / 180) - M_PI / 2))][(int)(all->map_info.bpx + cos((all->map_info.angle * M_PI / 180) - M_PI / 2))] == '1')
			return ;
		all->map_info.bpy += sin((all->map_info.angle * M_PI / 180) - M_PI / 2);
		all->map_info.bpx += cos((all->map_info.angle * M_PI / 180) - M_PI / 2);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_D))
	{
		if (all->big_map[(int)(all->map_info.bpy - sin((all->map_info.angle * M_PI / 180) - M_PI / 2))][(int)(all->map_info.bpx - cos((all->map_info.angle * M_PI / 180) - M_PI / 2))] == '1')
			return ;
		all->map_info.bpy -= sin((all->map_info.angle * M_PI / 180) - M_PI / 2);
		all->map_info.bpx -= cos((all->map_info.angle * M_PI / 180) - M_PI / 2);
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
		all->map_info.angle -= 2;
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
		all->map_info.angle += 2;
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
	while (++j < 1024)
	{
		xofwall = all->map_info.bpx;
		yofwall = all->map_info.bpy;
		printf ("%d\n", all->map_info.angle);
		distance = 0;
		while (all->big_map[(int)yofwall][(int)xofwall] != '1')
		{
			xofwall += cos((angle - 30 + j * 0.05859375) * M_PI / 180);
			yofwall += sin((angle - 30 + j * 0.05859375) * M_PI / 180);
			distance += sqrt(xofwall * xofwall + yofwall * yofwall);
			//printf("[%f]\n", distance);
			if (all->big_map[(int)yofwall][(int)(xofwall - cos((angle - 30 + j * 0.05859375) * M_PI / 180))] == '1' \
				&& all->big_map[(int)(yofwall - sin((angle - 30 + j * 0.05859375) * M_PI / 180))][(int)xofwall] == '1')
				break ;
			if (xofwall < 0 || xofwall > 1920 || yofwall < 0 || yofwall > 1080)
				break ;
			mlx_put_pixel(all->img, xofwall, yofwall, 0xBBBBDD00);
		}
		// distance = sqrt((xofwall - all->map_info.bpx) * (xofwall - all->map_info.bpx)
		// 			+ (yofwall - all->map_info.bpy) * (yofwall - all->map_info.bpy));
		// distance = distance * cos(((angle - 30 + j * 0.05859375) - angle) * M_PI / 180);
		line_print(all, j * 2, 540, distance/10);
	}
}
void	cf_background(void *name)
{
	t_pov	*all;
	int		x;
	int		y;

	all = name;
	y = -1;
	while (++y < 1080)
	{
		x = -1;
		while (++x < 1920)
		{
			if (y < 540)
				mlx_put_pixel(all->img, x, y, all->map_info.cn);
			else
				mlx_put_pixel(all->img, x, y, all->map_info.fn);
		}
	}
}

int	main(int ac, char **av)
{
	t_pov	all;

	if (ac != 2)
		return (1);
	parse(av[1], &all);
	all.mlx = mlx_init(1920, 1080, "cub3D", false);
	all.img = mlx_new_image(all.mlx, 1920, 1080);
	mlx_image_to_window(all.mlx, all.img, 0, 0);
	mlx_loop_hook(all.mlx, cf_background, &all);
	mlx_loop_hook(all.mlx, minimap, &all);
	mlx_loop_hook(all.mlx, keys, &all);
	mlx_loop_hook(all.mlx, graphic, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
