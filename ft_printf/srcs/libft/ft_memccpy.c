/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:27:49 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/05 12:47:07 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sourc;
	unsigned char	a;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		dest[i] = sourc[i];
		if (sourc[i] == a)
			return ((unsigned char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
