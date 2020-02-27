/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:36:07 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/06 20:36:52 by oel-ahma         ###   ########.fr       */
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

void		fill_ret(char *tmp, char *ret, int i)
{
	if (ft_strlen(tmp) == 2)
	{
		ret[i] = tmp[0];
		ret[i + 1] = tmp[1];
	}
	else
	{
		ret[i] = '0';
		ret[i + 1] = tmp[0];
	}
}

char		*signed_hexa(size_t num, char *base)
{
	char	*ret;
	int		i;
	char	*bin;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	bin = (binary_convert(num));
	while (i < 8)
	{
		tmp2 = ft_substr(bin, (4 * i), 8);
		tmp = ft_convert_base(tmp2, "01", base);
		free(tmp2);
		fill_ret(tmp, ret, i);
		free(tmp);
		i = i + 2;
	}
	free(bin);
	return (ret);
}
