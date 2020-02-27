/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:18:29 by jfreitas          #+#    #+#             */
/*   Updated: 2020/01/03 15:11:44 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <fcntl.h> // open

int		main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	int		ret;
	int 	j;

	line = NULL;
	argc = 3;
	if ((open(argv[1], O_RDONLY)) == -1)
		printf("file > %s < does not exist\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	printf("-------------------------------------> fd=%d\n", fd);
	j = 1;
	while ((ret =get_next_line(fd, &line)) == 1 && j < 1000)
	{
		if (j < 10)
			printf("[0%d] %s\n", j, line);
		else
			printf("[%d] %s\n", j, line);
		j++;
		free(line);
	}
	if (*line)
	{
		if (j < 10)
			printf("[*0%d] %s\n", j, line);
		else
			printf("[*%d] %s\n", j, line);
	}
	free(line);
	close(fd);

	line = NULL;
	fd2 = open(argv[2], O_RDONLY);
	printf("-------------------------------------> fd2=%d\n", fd2);
	j = 1;
	while ((ret =get_next_line(fd, &line)) == 1 && j < 1000)
	{
		if (j < 10)
			printf("[0%d] %s\n", j, line);
		else
			printf("[%d] %s\n", j, line);
		j++;
		free(line);
	}
	if (*line)
	{
		if (j < 10)
			printf("[*0%d] %s\n", j, line);
		else
			printf("[*%d] %s\n", j, line);
	}
	free(line);
	close(fd2);

	if (ret == -1)
		return (0);
	printf("-------------------------------------> leaks\n");
	system("leaks a.out");
	return (0);
}
