/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:25:27 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/17 16:25:38 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*big_strdup(char *s1, size_t n)
{
	char	*new;
	size_t	i;
	size_t	o;
	size_t	t;

	i = 0;
	o = -1;
	t = -1;
	new = (char *)malloc (sizeof(char) * ((ft_strlen(s1) * n) + 1));
	if (!new)
		return (0);
	new[(ft_strlen(s1) * n)] = '\0';
	while (++o != ft_strlen(s1))
	{
		t = -1;
		while (++t != n)
		{
			new[i] = map_char(s1[o]);
			i++;
		}
	}
	return (new);
}
