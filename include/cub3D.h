/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:06:07 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/17 16:32:19 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define N			16
# define SHEIGH		1080
# define SWIDTH		1920
# define FOV		1.0471975511965976

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
	float			angle;
	int				mwidth;
	int				mheight;
	int				errflag;
	int				count;
	char			**c;
	char			**f;
	unsigned int	fn;
	unsigned int	cn;
	float			xhwall;
	float			yhwall;
	float			xvwall;
	float			yvwall;
	int				wmap;
	int				hmap;
	float			dist;
	char			direct;
}t_fil;

struct s_pov
{
	int					fd;
	char				*tmp;
	char				*elem[6];
	char				**map;
	char				**bm;
	t_list				*map_2d;
	t_fil				map_info;
	mlx_image_t			*img;
	mlx_image_t			*swg;
	mlx_image_t			*wal_img;
	mlx_texture_t		*wal[4];
	mlx_t				*mlx;
	mlx_texture_t		*frm[97];
	int					*tc[4];
	int					compus;
};
typedef struct s_pov	t_pov;

void			ft_lstiter(t_list *lst, void (*f)(char *, t_fil *), t_fil *fil);
void			checkname(char *filename);
bool			parse(char *fmap, t_pov *all);
void			exit_perror(t_pov *all);
bool			xelem(t_pov *all);
bool			xmap(t_pov *all);
bool			nasa(char *line);
void			filter_m(t_pov *all);
void			cf_ext(t_pov *all);
void			link_toarr(t_list *lst, int n, t_pov *all);
void			check_borders(t_list *map_info, t_pov *all);
void			pov(char c, t_fil *all);
void			graphic(void *name);
void			free_2d(char **str);
bool			find_zeros(int i, char **map);
char			*s_spc(char *l);
unsigned int	ft_pixel(int r, int g, int b, int a);
int				israyfacingup(float angle);
void			changeoriginal(t_pov *all);
void			moveup(t_pov *all);
void			movedown(t_pov *all);
void			moveleft(t_pov *all);
void			moveright(t_pov *all);
void			init_frm(t_pov *all);
void			check_comma(t_pov	*all);
void			minimap(void *name);
void			sprite_anim(void *name);
void			colorize_swg(t_pov *all, char *joined);
void			nullification(t_pov *all);
char			map_char(char input);
char			*big_strdup(char *s1, size_t n);

#endif