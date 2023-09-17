/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:23:40 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/16 22:40:57 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*copy;

	copy = (void *)malloc(size * count);
	printf("copy:%p\n", copy);
	if (!copy)
		return (NULL);
	ft_bzero(copy, count * size);
	return (copy);
}
