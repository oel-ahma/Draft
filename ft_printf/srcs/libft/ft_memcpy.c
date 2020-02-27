/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:28:32 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/05 12:46:43 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dest;
	char			*sourc;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (char *)dst;
	sourc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dst);
}
