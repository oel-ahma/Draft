/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:23:20 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/12/06 16:27:49 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] && i < n)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
