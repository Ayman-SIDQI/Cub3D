/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:07 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/07 17:12:21 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define N 16
# define SCREENWIDTH 1920
# define SCREENHIGH 1080
# define FOV 60

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
	mlx_image_t			*wal_img;
	mlx_texture_t		*wal[4];
	mlx_t				*mlx;
	mlx_texture_t		*frm[97];
	int					*tc[4];
};
//	ft_pixel(all.wal[0].pixels[0], all.wal[0], all.wal[0], all.wal[0]) 
typedef struct s_pov	t_pov;


void			ft_lstiter(t_list *lst, void (*f)(char *, t_fil *), t_fil *fil);
void			checkname(char *filename);
bool			parse(char *fmap, t_pov *all);
void			exit_perror(void);
bool			xelem(t_pov *all);
bool			xmap(t_pov *all);
bool			nasa(char *line);
void			filter_m(t_pov *all);
void			cf_ext(t_pov *all);
void			link_toarr(t_list *lst, int n, t_pov *all);
void			check_borders(t_list *map_info, t_pov *all);
void			pov(char c, t_fil *all);
void			graphic(void *name);
void			minimap(void *name);
void			sprite_dance(void *name);
void			check_borders(t_list *map_info, t_pov *all);
void			free_2d(char **str);
void			line_print(t_pov *all, int x, int xwall, int pxl);
bool			xmap(t_pov *all);
bool			find_zeros(int i, char **map);
char			*s_spc(char *l);
unsigned int	ft_pixel(int r, int g, int b, int a);

void			example(void *name);

#endif