/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:48:16 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/07 15:39:57 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			get_newline(char **stack, char **line)
{
	int		len;
	char	*strchr_stack;

	len = 0;
	strchr_stack = *stack;
	while (strchr_stack[len++] != '\n')
	{
		if (strchr_stack[len] == '\0')
			return (0);
	}
	*line = ft_strdup(ft_substr(strchr_stack, 0, len - 1));
	*stack = ft_strdup(ft_substr(strchr_stack, len, ft_strlen(strchr_stack)));
	return (1);
}


static int			ft_read_line(int fd, char *buff, char **stack, char **line)
{
	int				rd;
	char			*tmp_stack;

	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, buff);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(buff);
		if (get_newline(stack, line))
			break ;
	}
	return (READ(rd));
}


int					get_next_line(int const fd, char **line)
{
	static char		*stack[1000];
	char			*buff;
	int				rd;
	int				i;

	if (!line || (fd < 0 || fd >= 1000) || (read(fd, stack[fd], 0) < 0) \
			|| !(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (stack[fd])
	{
		if (get_newline(&stack[fd], line))
			return (1);
	}
	i = 0;
	while (i < BUFFER_SIZE)
		buff[i++] = '\0';
	rd = ft_read_line(fd, buff, &stack[fd], line);
	free(buff);
	if (rd != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!rd && *line)
			*line = NULL;
		return (rd);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}

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
