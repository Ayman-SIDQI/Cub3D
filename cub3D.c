/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/28 15:56:45 by hcharia          ###   ########.fr       */
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
	while (++o < pxl)
		mlx_put_pixel(all->img, x, (y + o), 0xAAAAAAFF);
	while (o > 0)
	{
		mlx_put_pixel(all->img, x, (y - o), 0xAAAAAAFF);
		o--;
	}
}

void	initializer(t_pov	*all)
{
	int	i;
	int	o;

	i = -1;
	all->img = mlx_new_image(all->mlx, 1920, 1080);
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
	line_print(all, 960, 540, 500);
}

void	keys(void *name)
{
	t_pov	*all;

	all = name;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
	if (mlx_is_key_down(all->mlx, MLX_KEY_UP))
		all->map_info.py -= 5;
	if (mlx_is_key_down(all->mlx, MLX_KEY_DOWN))
		all->map_info.py += 5;
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
		all->map_info.px -= 5;
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
		all->map_info.px += 5;
}

int	main(int ac, char **av)
{
	t_pov	all;

	if (ac != 2)
		return (1);
	parse(av[1], &all);
	all.mlx = mlx_init(1920, 1080, "cub3D", false);
	initializer(&all);
	for (int i = 0;all.big_map[i]; i++)
		printf("%s\n", all.big_map[i]);
	mlx_image_to_window(all.mlx, all.img, 0, 0);
	mlx_loop_hook(all.mlx, keys, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
