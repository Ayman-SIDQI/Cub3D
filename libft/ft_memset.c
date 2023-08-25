/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:39:34 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/24 16:25:14 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;

	ret = (unsigned char *) b;
	while (len--)
	{
		*ret++ = (unsigned char)c;
	}
	return (b);
}
/*
int	main (void)
{
	char	al[6] = "Aymanm";
	ft_memset ((void *)al, 'z', 4);
	printf ("%s\n", al);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

   int	main (void)
   {
   char	al[] = "AYMAN";
   ft_memset ((void *)al, 'z', 3);
   printf ("%s\n", al);
   return (0);
   }*/
