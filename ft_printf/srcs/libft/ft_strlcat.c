/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:33:36 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/05 13:08:57 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_end;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	dst_end = i;
	while (src[i - dst_end] && i < size - 1)
	{
		dst[i] = (const char)src[i - dst_end];
		i++;
	}
	if (dst_end < size)
		dst[i] = '\0';
	return (dst_end + ft_strlen(src));
}
