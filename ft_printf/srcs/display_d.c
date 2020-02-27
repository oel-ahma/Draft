/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:46:19 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/03 16:02:48 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*get_str(int tmp)
{
	char *str;

	str = NULL;
	if (tmp < 0 && tmp != INT_MIN)
		tmp = -tmp;
	if (!(str = ft_itoa(tmp)))
		return (NULL);
	if (tmp == INT_MIN)
	{
		free(str);
		str = ft_strdup("2147483648");
	}
	return (str);
}

static	int		sign_check(int tmp)
{
	if (tmp < 0)
		return (1);
	return (0);
}

int				display_d(t_print *parser)
{
	char	*str;
	int		len;
	int		sign;
	int		tmp;

	tmp = (int)va_arg(parser->ap, int);
	sign = sign_check(tmp);
	if (!(str = get_str(tmp)))
		return (-1);
	len = (size_t)ft_strlen(str);
	if (parser->precision == 0 && ft_strncmp(str, "0", 1) == 0)
		len = 0;
	parser->len += len;
	tmp = 0;
	if (parser->precision == -1)
		display_case1_d(parser, str, len, sign);
	else
	{
		if (parser->precision > len)
			display_case2_d(parser, str, tmp + sign, len);
		else
			display_case3_d(parser, str, len, sign);
	}
	free(str);
	return (1);
}
