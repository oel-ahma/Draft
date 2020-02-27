/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:57:16 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 16:10:38 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*binary_one_addition(char *s)
{
	int		i;

	i = 31;
	while (s[i] == '1')
	{
		s[i] = '0';
		i--;
	}
	s[i] = '1';
	return (s);
}

static char	*binary_convert(size_t num)
{
	char	*bin;
	int		i;

	if (!(bin = (char *)malloc(sizeof(char) * 33)))
		return (NULL);
	i = 31;
	while (num > 0)
	{
		bin[i--] = 48 + (num % 2);
		num = num / 2;
	}
	while (i >= 0)
		bin[i--] = '0';
	bin[32] = '\0';
	i = 0;
	while (bin[i])
	{
		if (bin[i] == '0')
			bin[i] = '1';
		else
			bin[i] = '0';
		i++;
	}
	return (binary_one_addition(bin));
}

char		*signed_u(size_t num, char *base)
{
	char	*ret;
	char	*bin;

	if (!(ret = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	bin = (binary_convert(num));
	ret = ft_convert_base(bin, "01", base);
	free(bin);
	return (ret);
}
