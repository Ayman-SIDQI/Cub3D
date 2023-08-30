/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:07 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/30 22:41:57 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define N 16

# include <MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include <math.h>

typedef struct s_fil
{
	float			px;
	float			py;
	float			bpx;
	float			bpy;
	int				angle;
	int				mwidth;
	int				mheight;
	int				errflag;
	int				count;
	char			**c;
	char			**f;
	unsigned int	fn;
	unsigned int	cn;
}t_fil;

struct s_pov
{
	int					fd;
	char				*tmp;
	char				*elem[6];
	char				**map;
	char				**big_map;
	t_list				*map_2d;
	t_fil				map_info;
	mlx_image_t			*img;
	mlx_image_t			*swg;
	mlx_t				*mlx;
	mlx_texture_t		*frm[97];
};
typedef struct s_pov	t_pov;

// init_map(mlx_t *mlx);
void	ft_lstiter(t_list *lst, void (*f)(char *, t_fil *), t_fil *fil);
void	checkname(char *filename);
bool	parse(char *fmap, t_pov *all);
void	exit_perror(void);
bool	xelem(t_pov *all);
bool	xmap(t_pov *all);
bool	nasa(char *line);
void	filter_m(t_pov *all);
void	cf_ext(t_pov *all);
void	link_toarr(t_list *lst, int n, t_pov *all);
void	check_borders(t_list *map_info, t_pov *all);
void	pov(char c, t_fil *all);

#endif