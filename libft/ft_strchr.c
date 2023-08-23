/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:40:28 by asidqi            #+#    #+#             */
/*   Updated: 2023/08/23 12:26:34 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Libft's strchr is commented just incase
// char	*ft_strchr(const char *s, int c)
// {
// 	char	*ts;
// 	char	tc;
// 	int		i;

// 	ts = (char *)s;
// 	tc = c;
// 	i = 0;
// 	while (ts[i] != tc)
// 	{
// 		if (ts[i] == '\0')
// 			return (NULL);
// 		i++;
// 	}
// 	return (ts + i);
// }

int	ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
