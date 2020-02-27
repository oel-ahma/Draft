/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:31:36 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/07 19:27:23 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		display_width(t_print *parser, char c, int len, int b)
{
	if (b == 1)
	{
		ft_putchar('-');
		parser->len++;
		return (len);
	}
	else if (b == -1)
		while ((parser->flags[2] - len) > 0)
		{
			ft_putchar(c);
			len++;
			parser->len++;
		}
	return (len);
}

static	int		display_precision(t_print *parser, int b, int tmp)
{
	if (b == 1)
	{
		while ((parser->flags[2] - (parser->precision + tmp)) > 0)
		{
			ft_putchar(' ');
			tmp++;
			parser->len++;
		}
		return (tmp);
	}
	while (parser->precision - tmp > 0)
	{
		ft_putchar('0');
		tmp++;
		parser->len++;
	}
	return (tmp);
}

void			display_case1_d(t_print *parser, char *str, int len, int sign)
{
	if (parser->flags[0] == 1)
	{
		display_width(parser, '1', len + sign, sign);
		ft_putstr(str);
		len = display_width(parser, ' ', len + sign, -1);
	}
	else if (parser->flags[1] == 1)
	{
		display_width(parser, '2', len + sign, sign);
		len = display_width(parser, '0', len + sign, -1);
		ft_putstr(str);
	}
	else
	{
		len = display_width(parser, ' ', len + sign, -1);
		display_width(parser, '3', len + sign, sign);
		ft_putstr(str);
	}
}

void			display_case2_d(t_print *parser, char *str, int tmp, int len)
{
	int sign;

	sign = 0;
	if (tmp == 1)
		sign = 1;
	if (parser->precision > len)
	{
		if (parser->flags[0] == 0)
		{
			tmp = display_precision(parser, 1, tmp);
			display_width(parser, '4', len + sign, sign);
			len = display_precision(parser, 0, len);
			ft_putstr(str);
		}
		if (parser->flags[0] == 1)
		{
			display_width(parser, '5', len + sign, sign);
			len = display_precision(parser, 0, len);
			ft_putstr(str);
			tmp = display_precision(parser, 1, tmp);
		}
	}
}

void			display_case3_d(t_print *parser, char *str, int len, int sign)
{
	if (parser->flags[0] == 1)
	{
		display_width(parser, ' ', len + sign, sign);
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
		len = display_width(parser, ' ', len + sign, -1);
	}
	else if ((parser->flags[1] == 1 && parser->precision > len) \
			|| (parser->flags[1] == 1 && parser->precision < 0))
	{
		display_width(parser, ' ', len + sign, sign);
		len = display_width(parser, '0', len + sign, -1);
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
	}
	else
	{
		len = display_width(parser, ' ', len + sign, -1);
		display_width(parser, ' ', len + sign, sign);
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
	}
}
