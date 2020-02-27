/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:49:49 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/26 16:04:17 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t length;

	if (!s)
		return (0);
	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp_s3;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;
	while (*s1 != '\0')
		*tmp_s3++ = *s1++;
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	j = 0;
	while (s[j])
		j++;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > j)
	{
		dst[0] = '\0';
		return (dst);
	}
	i = 0;
	while (i < len && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}

int get_newline(char **stack, char **line)
{
	int len;
	char *tmp_stack;
	char *tmp_line;
	char *tmp;

	len = 0;
	tmp_stack = *stack;
	while (tmp_stack[len++] != '\n')
	{
		if (tmp_stack[len] == '\0')
			return (0);
	}
	tmp_line = ft_substr(tmp_stack, 0, len - 1);
	*line = ft_strdup(tmp_line);
	tmp = ft_substr(tmp_stack, len, ft_strlen(tmp_stack) - len);
	*stack = ft_strdup(tmp);
	free(tmp);
	free(tmp_line);
	free(tmp_stack);
	tmp = NULL;
	tmp_line = NULL;
	tmp_stack = NULL;
	return (1);
}

int get_next_line(char **line)
{
	static char *stack[10];
	char buff[129];
	int rd;
	char *tmp;

	if (!line || read(0, buff, 0) < 0)
		return (-1);
	if (stack[0])
	{
		if (get_newline(&stack[0], line))
		{
			if (stack[0])
				return (1);
			else
				return (0);
		}
	}
	while ((rd = read(0, buff, 128)) > 0)
	{
		buff[rd] = '\0';
		if (stack[0])
		{
			tmp = stack[0];
			stack[0] = ft_strjoin(tmp, buff);
			free(tmp);
			tmp = NULL;
		}
		else
			stack[0] = ft_strdup(buff);
		if (get_newline(&stack[0], line))
		{
			if (rd == 128)
				return (1);
			if (stack[0])
				return (1);
			else
				return (0);
		}
	}
	if (stack[0])
	{
		*line = stack[0];
		stack[0] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}


