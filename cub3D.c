/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/26 15:31:24 by asidqi           ###   ########.fr       */
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



// char	**expander(t_pov *all)
// {
// 	// all->big_map = create_bigmap(all->big_map, 16);
// 	while (all->map)
// 	{
// 	}
// 	free_2d(all->map);
// }

void	initializer(t_pov	*all)
{
	// all->big_map = expander(all);
	all->img = mlx_new_image(all->mlx, 256, 450);
	mlx_put_pixel(all->img, 300, 50, 0xFF0000FF);
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
	mlx_image_to_window(all.mlx, all.img, 0, 0);
	mlx_loop_hook(all.mlx, keys, &all);
	mlx_loop(all.mlx);
	mlx_terminate(all.mlx);
	return (0);
}
