/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:02:29 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/10/28 14:07:07 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	if (s && f)
	{
		while (s[i])
		{
			dest[i] = f(i, s[i]);
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
