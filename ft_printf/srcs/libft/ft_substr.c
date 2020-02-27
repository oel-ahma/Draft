/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:11:26 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/10/28 14:10:36 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		dst[0] = '\0';
		return (dst);
	}
	i = 0;
	while (s[start] && i < len)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
