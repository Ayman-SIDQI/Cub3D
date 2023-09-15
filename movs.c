/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:42:48 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/15 21:52:25 by asidqi           ###   ########.fr       */
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
		&& all->big_map[y][x] != '1' \
		&& all->big_map[(int)(all->map_info.bpy)][x] != '1')
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
			&& all->big_map[y][x] != '1' \
			&& all->big_map[(int)(all->map_info.bpy)][x] != '1')
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
		if (all->big_map[y][(int)(all->map_info.bpx)] != '1' \
		&& all->big_map[y][x] != '1' 
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
		&& all->big_map[y][x] != '1' \
		&& all->big_map[(int)(all->map_info.bpy)][x] != '1')
		{
			all->map_info.bpy -= sin((all->map_info.angle) - M_PI / 2);
			all->map_info.bpx -= cos((all->map_info.angle) - M_PI / 2);
		}
	}
}
