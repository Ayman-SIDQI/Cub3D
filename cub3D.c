/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:01 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/23 21:57:24 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	initializer(char *fmap, t_pov	*all)
// {

// 	mlx = mlx_init(500, 500, "cub3D", false);
// }


int	main(int ac, char **av)
{
	t_pov	all;


	if (ac != 2)
		return (1);
	parse(av[1], &all);
	printf("[%s]", all.elem[0]);
	printf("	[%s]", all.elem[1]);
	printf("	[%s]", all.elem[2]);
	printf("	[%s]", all.elem[3]);
	printf("	[%s]", all.elem[4]);
	printf("	[%s]\n", all.elem[5]);
	// all = initializer(&all);
	// mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	// mlx_image_to_window(mlx, img, 0, 0);
	// mlx_put_pixel(img, 50, 50, 0xFF0000FF);
	// // mlx_is_key_down(mlx, MLX_KEY_ESCAPE)
	// // 	mlx_terminate(mlx);
	
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (0);
}
