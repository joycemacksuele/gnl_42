/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:26:12 by jfreitas          #+#    #+#             */
/*   Updated: 2019/12/27 15:22:04 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char const *s1)
{
	char	*dest;
	int		lens1;
	int		i;
	int		j;

	lens1 = 0;
	while (s1[lens1] != '\0')
		lens1++;
	dest = (char*)malloc(sizeof(char) * (lens1 + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		dest[i++] = s1[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fresh_sub_str;

	i = 0;
	if (!s)
		return (NULL);
	if (!(fresh_sub_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < (len + 1))
		fresh_sub_str[i++] = '\0';
	i = 0;
	while (i < len)
		fresh_sub_str[i++] = s[start++];
	fresh_sub_str[i] = '\0';
	return (fresh_sub_str);
}

size_t	ft_strclen(char const *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	while (dst != NULL || src != NULL)
	{
		if ((char const*)src < (char*)dst)
			while (len-- > 0)
				*((char*)dst + len) = *((char const*)src + len);
		else
			while (i < len)
			{
				*((char*)dst + i) = *((char const*)src + i);
				i++;
			}
		return (dst);
	}
	return (NULL);
}

char	*ft_strchr(char const *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char*)s);
}
