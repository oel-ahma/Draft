/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:05:57 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/05 13:08:25 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	if (!(dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
