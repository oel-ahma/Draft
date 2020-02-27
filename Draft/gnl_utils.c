/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:50:15 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/12 19:39:43 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

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
