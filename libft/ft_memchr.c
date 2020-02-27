/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:53:35 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/05 12:48:12 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (void *)s;
	while (i < n)
	{
		if (t[i] == (char)c)
			return (t + i);
		i++;
	}
	return (NULL);
}
