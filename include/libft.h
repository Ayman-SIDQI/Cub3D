/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:21:36 by asidqi            #+#    #+#             */
/*   Updated: 2023/09/21 15:14:38 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	struct s_list	*prv;
}				t_list;

// char	*ft_strchr(char *s, int c);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
short	ft_isdigit(char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_itoa(int n);
t_list	*ft_lstnew(char *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif
