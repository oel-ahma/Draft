/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:08:59 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 16:46:52 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		compare(char c, char const *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && compare(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && compare(s1[end], set) == 1)
		end--;
	return (ft_substr(s1, start, abs((end - start + 1))));
}
