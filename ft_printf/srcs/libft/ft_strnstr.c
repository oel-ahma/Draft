/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:34:56 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/04 18:07:29 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	if (ft_strlen(small) == 0)
		return ((char *)big);
	while (len)
	{
		if (ft_strncmp(big, small, ft_strlen(small)) == 0 \
				&& len >= ft_strlen(small))
			return ((char *)big);
		else
			big++;
		len--;
	}
	return (NULL);
}
