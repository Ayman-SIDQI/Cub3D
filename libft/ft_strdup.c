/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:25:27 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/17 12:21:03 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	new = (char *)malloc (sizeof(char) * (len + 1));
	// printf("dup new:%p\n", new);
	if (!new)
		return (0);
	new[len] = '\0';
	while (i != len)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}
