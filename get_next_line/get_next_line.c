/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:48:16 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/26 15:46:18 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUFFER_SIZE 128

static int	get_newline(char **stack, char **line)
{
	int		len;
	char	*tmp_stack;
	char	*tmp1;
	char	*tmp2;

	len = 0;
	tmp_stack = *stack;
	while (tmp_stack[len++] != '\n')
	{
		if (tmp_stack[len] == '\0')
			return (0);
	}
	tmp2 = ft_substr(tmp_stack, 0, len - 1);
	*line = ft_strdup(tmp2);
	tmp1 = ft_substr(tmp_stack, len, ft_strlen(tmp_stack) - len);
	*stack = ft_strdup(tmp1);
	free(tmp1);
	free(tmp2);
	free(tmp_stack);
	tmp1 = NULL;
	tmp2 = NULL;
	tmp_stack = NULL;
	return (1);
}

static void	fill_stack(int fd, char **stack, char *buff)
{
	char *tmp_stack;

	if (stack[fd])
	{
		tmp_stack = stack[fd];
		stack[fd] = ft_strjoin(tmp_stack, buff);
		free(tmp_stack);
		tmp_stack = NULL;
	}
	else
		stack[fd] = ft_strdup(buff);
}

static int	gnl(int fd, char *buff, char **stack, char **line)
{
	int		rd;

	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = '\0';
		fill_stack(fd, stack, buff);
		if (get_newline(&stack[fd], line))
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

int			get_next_line(int fd, char **line)
{
	static char		*stack[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1 \
			|| read(fd, buff, 0) < 0)
		return (-1);
	if (stack[fd])
	{
		if (get_newline(&stack[fd], line))
		{
			if (stack[fd])
				return (1);
			else
				return (0);
		}
	}
	return (gnl(fd, buff, stack, line));
}
