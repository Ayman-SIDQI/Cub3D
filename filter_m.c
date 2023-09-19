/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:23:46 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/19 21:55:07 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dup_check(char *cnt, t_fil *fil)
{
	int			i;

	i = -1;
	while (cnt[++i])
	{
		if ((cnt[i] == 'N' || cnt[i] == 'E' || cnt[i] == 'W' || cnt[i] == 'S'))
		{
			fil->count++;
			fil->px = i;
			fil->bpx = fil->px * N + (N / 2);
		}
		if (cnt[i] != 'N' && cnt[i] != 'E' && cnt[i] != 'W' 
			&& cnt[i] != 'S' && cnt[i] != ' ' && cnt[i] != '0'
			&& cnt[i] != '1' && cnt[i] != '\n')
			fil->errflag = 1;
	}
	if (fil->mwidth < i)
		fil->mwidth = i;
}

void	initialize(t_fil *info)
{
	info->count = 0;
	info->mwidth = 0;
	info->mheight = 0;
	info->errflag = 0;
	info->px = 0;
	info->py = 0;
}

void	filter_m(t_pov *all, int fd)
{
	t_list	*tmp;

	tmp = all->map_2d;
	initialize(&all->map_info);
	ft_lstiter(tmp, &dup_check, &all->map_info);
	if (all->map_info.count != 1)
		all->map_info.errflag = 1;
	if (all->map_info.errflag == 1 || all->map_info.mwidth > 69)
	{
		system("leaks cub3D");
		printf("Error\n Map not going to function well");
		close(fd);
		exit(1);
	}
}

void	fillcolors(t_pov *all)
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
			all->tc[i][k++] = ft_pixel(all->wal[i]->pixels[j], \
			all->wal[i]->pixels[j + 1], all->wal[i]->pixels[j + 2], \
			all->wal[i]->pixels[j + 3]);
			j += all->wal[i]->bytes_per_pixel;
		}
	}
}

void	colorize_swg(t_pov *all, char *joined)
{
	int	i;

	fillcolors (all);
	i = 0;
	while (++i < 98)
	{
		joined = ft_strjoin("./frames/", ft_itoa(i));
		all->frm[i - 1] = mlx_load_png(joined);
		free(joined);
		if (!all->frm[i - 1])
			exit_perror(all);
	}

}
