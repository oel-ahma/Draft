/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:01:45 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/12 21:34:31 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdio.h>

int main()
{
	int fd;
	int ret;
	char **line;

	fd = open("text.txt", O_RDONLY);

	ret = get_next_line(fd, line);
	printf("%d | %s\n", ret, *line);
	//free(*line);
	*line = NULL;
	ret = get_next_line(fd, line);
	printf("%d | %s\n", ret, *line);
	//	free(*line);
	*line = NULL;
	ret = get_next_line(fd, line);
	printf("%d | %s\n", ret, *line);
	//	free(*line);
	*line = NULL;
	ret = get_next_line(fd, line);
	printf("%d | %s\n", ret, *line);
	//	free(*line);
	*line = NULL;

}

