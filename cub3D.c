/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/18 12:27:42 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	if (all->map_info.angle < 0)
		all->map_info.angle += 2 * M_PI;
	if (all->map_info.angle > 2 * M_PI)
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
			if (y < (SHEIGH / 2))
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
	all->map_info.angle += (x - 960) / 400;
}

int	main(int ac, char **av)
{
	t_pov	all;

	if (ac != 2)
		return (1);
	nullification(&all);
	parse(av[1], &all);
	init_frm(&all);
	all.swg = NULL;
	all.mlx = mlx_init(SWIDTH, SHEIGH, "cub3D", false);
	all.img = mlx_new_image(all.mlx, SWIDTH, SHEIGH);
	mlx_image_to_window(all.mlx, all.img, 0, 0);
	mlx_loop_hook(all.mlx, sprite_anim, &all);
	mlx_cursor_hook(all.mlx, sway, &all);
	mlx_loop_hook(all.mlx, cf_background, &all);
	mlx_loop_hook(all.mlx, keys, &all);
	mlx_loop_hook(all.mlx, graphic, &all);
	mlx_loop_hook(all.mlx, minimap, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
