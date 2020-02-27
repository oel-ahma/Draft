/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:45:09 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/07 15:45:50 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	size_t line_count;
	char *line;
	int fd;

	line_count = 0;
	line = NULL;
	fd = open("test1.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR open file %s\n", "test.txt");
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		line_count++;
		printf("%zu\t|%s$\n", line_count, line);
		free(line);
	}
	fd = close(fd);
}
