/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:19:28 by jfreitas          #+#    #+#             */
/*   Updated: 2019/12/30 14:14:12 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh_str;
	int		lens1;
	int		lens2;
	int		len;

	lens1 = 0;
	lens2 = 0;
	while (s1[lens1] != '\0')
		lens1++;
	while (s2[lens2] != '\0')
		lens2++;
	len = lens1 + lens2;
	if (!(fresh_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	lens1 = 0;
	while (lens1 < (len + 1))
		fresh_str[lens1++] = '\0';
	lens2 = 0;
	while (*s1 != '\0')
		fresh_str[lens2++] = *s1++;
	while (*s2 != '\0')
		fresh_str[lens2++] = *s2++;
	fresh_str[lens2] = '\0';
	return (fresh_str);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return (str);
}

int		check_line(char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (tmp[i] != '\n')
		if (!(tmp[i++]))
			return (0);
	return (1);
}

char	*read_file(int fd, char **str, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	char	*tmp;
	int		i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (NULL);
	if (!*str)
	{
		if (!(*str = ft_strnew(BUFFER_SIZE + 1)))
			return (NULL);
	}
	i = 0;
	while ((check_line(*str) == 0) && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(tmp, buff)))
			return (NULL);
		free(tmp);
	}
	return (*str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;

	*line = NULL;
	if (read_file(fd, &str, line) == NULL)
		return (-1);
	else
		str = read_file(fd, &str, line);
	if (!*str)
		*line = ft_strdup("");
	else
		*line = ft_substr(str, 0, ft_strclen(str, '\n'));
	if (check_line(str) == 1)
	{
		ft_memmove(str, ft_strchr(str, '\n') + 1, ft_strclen(str, '\0'));
		return (1);
	}
	free(str);
	str = NULL;
	return (0);
}
