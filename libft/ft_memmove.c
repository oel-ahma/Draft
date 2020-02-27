/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:57:43 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/05 12:47:33 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*sourc;
	int					i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	sourc = (const unsigned char *)src;
	i = 0;
	if (dest < sourc)
		while (i < (int)size)
		{
			dest[i] = sourc[i];
			i++;
		}
	else
	{
		i = (int)size - 1;
		while (i >= 0)
		{
			dest[i] = sourc[i];
			i--;
		}
	}
	return (dst);
}
