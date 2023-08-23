/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:07 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/23 20:46:32 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

struct s_pov
{
	int			px;
	int			py;
	int			mwidth;
	int			mheight;
	int			fd;
	char		*tmp;
	char		*elem[6];
	t_list		*map_2d;
	mlx_image_t	*img;
	mlx_t		*mlx;
};

// init_map(mlx_t *mlx);
typedef struct s_pov	t_pov;
void	checkname(char *filename);
bool	parse(char *fmap, t_pov *all);
void	exit_perror(void);


#endif