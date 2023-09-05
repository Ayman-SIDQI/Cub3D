/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia <hcharia@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/05 19:35:08 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	sway(double x, double y, void *name)
{
	t_pov	*all;

	all = name;
	(void)y;
	mlx_set_cursor_mode(all->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(all->mlx, 960, 540);
	all->map_info.angle += (x - 960) / 2;
}

void	fillcolors (t_pov *all)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < 4)
	{
		while (k < 256 * 256)
		{
			all->tc[i][k++] = ft_pixel(all->wal[i]->pixels[j], 
									all->wal[i]->pixels[j + 1],
									all->wal[i]->pixels[j + 2],
									all->wal[i]->pixels[j + 3]);
			j += 4;
		}
	}
}

void	init_frm(t_pov *all)
{
	int		i;
	char	*joined;

	i = -1;
	while (++i < 4)
	{
		if (all->elem[i][0] == 'N')
		{
			all->wal[i] = mlx_load_png("./frames/walls/mages.png");
			all->tc[i] = malloc(256 * 256 * sizeof(int));
		}
		if (all->elem[i][0] == 'S')
		{
			all->wal[i] = mlx_load_png("./frames/walls/mages.png");
			all->tc[i] = malloc(256 * 256 * sizeof(int));
		}
		if (all->elem[i][0] == 'W')
		{
			all->wal[i] = mlx_load_png("./frames/walls/mages.png");
			all->tc[i] = malloc(256 * 256 * sizeof(int));
		}
		if (all->elem[i][0] == 'E')
		{
			all->wal[i] = mlx_load_png("./frames/walls/mages.png");
			all->tc[i] = malloc(256 * 256 * sizeof(int));
		}
		fillcolors (all);
		if (!all->wal[i])
			exit_perror();
	}
	i = 0;
	while (++i < 98)
	{
		joined = ft_strjoin("./frames/", ft_itoa(i));
		all->frm[i - 1] = mlx_load_png(joined);
		free(joined);
		if (!all->frm[i - 1])
			exit_perror();
	}
}

int	main(int ac, char **av)
{
	t_pov	all;

	if (ac != 2)
		return (1);
	parse(av[1], &all);
	init_frm(&all);
	all.mlx = mlx_init(1920, 1080, "cub3D", false);
	all.img = mlx_new_image(all.mlx, 1920, 1080);
	mlx_image_to_window(all.mlx, all.img, 0, 0);
	// mlx_cursor_hook(all.mlx, sway, &all);
	mlx_loop_hook(all.mlx, cf_background, &all);
	mlx_loop_hook(all.mlx, sprite_dance, &all);
	mlx_loop_hook(all.mlx, keys, &all);
	mlx_loop_hook(all.mlx, minimap, &all);
	mlx_loop_hook(all.mlx, graphic, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
