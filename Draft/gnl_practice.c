/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_practice.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:20:40 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/12 21:46:10 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdio.h>

static int 	get_newline(char **stack, char **line)
{
	int len;
	char *tmp;
	char *tmp1;
	char *tmp2;

	len = 0;
	tmp = *stack;
	while (tmp[len++] != '\n')
	{	
		if (tmp[len] == '\0')
			return (0);	
	}
	tmp2 = ft_substr(tmp, 0, len - 1);
	*line = ft_strdup(tmp2);
	tmp1 = ft_substr(tmp, len, ft_strlen(tmp) - len);
	*stack = ft_strdup(tmp1);
	free(tmp1);
	free(tmp2);
	free(tmp);
	tmp1 = NULL;
	tmp2 = NULL;
	tmp = NULL;
	return (1);
}

int get_next_line(int fd, char **line)
{
	char *stack[fd];
	char buff[BUFFER_SIZE + 1];
	int rd;
	char *tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (stack[fd])
	{
		if (get_newline(&stack[fd], line) == 1)
		{
			if (stack[fd])
				return (1);
			else
				return (0);
		}
	}
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (stack[fd])
		{
			tmp = stack[fd];
			stack[fd] = ft_strjoin(tmp, buff);
			free(tmp);
			tmp = NULL;
		}
		else
			stack[fd] = ft_strdup(buff);
		if (get_newline(&stack[fd], line) == 1)
		{
			if (rd == BUFFER_SIZE)
				return (1);
			if (stack[fd])
				return (1);
			else
				return (0);
		}
	}
	if (stack[fd])
	{
		*line = stack[fd];
		stack[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
