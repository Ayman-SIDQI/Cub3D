/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/15 17:35:17 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	changeoriginal(t_pov *all)
{
	all->map_info.px = all->map_info.bpx / N;
	all->map_info.py = all->map_info.bpy / N;
}

void	moveup(t_pov *all)
{
	int		x;
	int		y;
	int		k;

	if (mlx_is_key_down(all->mlx, MLX_KEY_W))
	{
		y = all->map_info.bpy + sin(all->map_info.angle);
		x = all->map_info.bpx + cos(all->map_info.angle);

		if (all->big_map[y][(int)(all->map_info.bpx)] != '1' 
		&& all->big_map[y][x] != '1' && all->big_map[(int)(all->map_info.bpy)][x] != '1')
		{
			all->map_info.bpy += sin(all->map_info.angle);
			all->map_info.bpx += cos(all->map_info.angle);
		}
	}
}

void	movedown(t_pov *all)
{
	int		x;
	int		y;

	if (mlx_is_key_down(all->mlx, MLX_KEY_S))
	{
		y = all->map_info.bpy - sin(all->map_info.angle);
		x = all->map_info.bpx - cos(all->map_info.angle);
		
		if (all->big_map[y][(int)(all->map_info.bpx)] != '1' 
			&& all->big_map[y][x] != '1' && all->big_map[(int)(all->map_info.bpy)][x] != '1')
		{
			all->map_info.bpy -= sin(all->map_info.angle);
			all->map_info.bpx -= cos(all->map_info.angle);	
		}
	}
}

void	moveleft(t_pov *all)
{
	int		x;
	int		y;

	if (mlx_is_key_down(all->mlx, MLX_KEY_A))
	{
		y = all->map_info.bpy + sin((all->map_info.angle) - M_PI / 2);
		x = all->map_info.bpx + cos((all->map_info.angle) - M_PI / 2);
		if (all->big_map[y][(int)(all->map_info.bpx)] != '1' && all->big_map[y][x] != '1' 
		&& all->big_map[(int)(all->map_info.bpy)][x] != '1')
		{
			all->map_info.bpy += sin((all->map_info.angle) - M_PI / 2);
			all->map_info.bpx += cos((all->map_info.angle) - M_PI / 2);
		}
	}
}

void	moveright(t_pov *all)
{
	int		x;
	int		y;

	if (mlx_is_key_down(all->mlx, MLX_KEY_D))
	{
		y = all->map_info.bpy - sin((all->map_info.angle) - M_PI / 2);
		x = all->map_info.bpx - cos((all->map_info.angle) - M_PI / 2);
		if (all->big_map[y][(int)(all->map_info.bpx)] != '1' 
		&& all->big_map[y][x] != '1' && all->big_map[(int)(all->map_info.bpy)][x] != '1')
		{
			all->map_info.bpy -= sin((all->map_info.angle) - M_PI / 2);
			all->map_info.bpx -= cos((all->map_info.angle) - M_PI / 2);
		}
	}
}

void	keys(void *name)
{
	t_pov	*all;
	int		x;
	int		y;

	all = name;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);

	moveup(all);
	
	movedown(all);

	moveleft(all);
	
	moveright(all);
	
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
		all->map_info.angle -= 0.03;
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
		all->map_info.angle += 0.03;
	if(all->map_info.angle < 0)
		all->map_info.angle += 2 * M_PI;
	if(all->map_info.angle > 2 * M_PI)
		all->map_info.angle -= 2 * M_PI;
		
}

void	cf_background(void *name)
{
	t_pov	*all;
	int		x;
	int		y;

	all = name;
	y = -1;
	while (++y < SHEIGH)
	{
		x = -1;
		while (++x < SWIDTH)
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
	while (++i < 4)
	{
		j = 0;
		k = 0;
		while (k < all->wal[i]->width * all->wal[i]->height)
		{
			all->tc[i][k++] = ft_pixel(all->wal[i]->pixels[j], 
									all->wal[i]->pixels[j + 1],
									all->wal[i]->pixels[j + 2],
									all->wal[i]->pixels[j + 3]);
			j += all->wal[i]->bytes_per_pixel;
		}
	}
 }

void	init_frm(t_pov *all)
{
	int		i;
	int		j;
	char	*joined;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		if (all->elem[i][0] == 'N')
		{
			all->wal[++j] = mlx_load_png("./frames/walls/mages.png");
			all->tc[j] = malloc(all->wal[j]->width * all->wal[j]->height * sizeof(int));
		}
		if (all->elem[i][0] == 'S')
		{
			all->wal[++j] = mlx_load_png("./frames/walls/mages2.png");
			all->tc[j] = malloc(all->wal[j]->width * all->wal[j]->height * sizeof(int));
		}
		if (all->elem[i][0] == 'W')
		{
			all->wal[++j] = mlx_load_png("./frames/walls/mages3.png");
			all->tc[j] = malloc(all->wal[j]->width * all->wal[j]->height * sizeof(int));
		}
		if (all->elem[i][0] == 'E')
		{
			all->wal[++j] = mlx_load_png("./frames/walls/mages4.png");
			all->tc[j] = malloc(all->wal[j]->width * all->wal[j]->height * sizeof(int));
		}
		if (!all->wal[i])
			exit_perror();
	}
	fillcolors (all);
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
	all.mlx = mlx_init(SWIDTH, SHEIGH, "cub3D", false);
	all.img = mlx_new_image(all.mlx, SWIDTH, SHEIGH);
	mlx_image_to_window(all.mlx, all.img, 0, 0);
	//mlx_cursor_hook(all.mlx, sway, &all);
	mlx_loop_hook(all.mlx, cf_background, &all);
	// mlx_loop_hook(all.mlx, sprite_dance, &all);
	mlx_loop_hook(all.mlx, keys, &all);
	mlx_loop_hook(all.mlx, minimap, &all);
	mlx_loop_hook(all.mlx, graphic, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
