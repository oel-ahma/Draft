/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:31:36 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/07 18:42:55 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		display_width(t_print *parser, char c, int len)
{
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

void			display_case1_p(t_print *parser, char *str, int len)
{
	if (parser->flags[0] == 1)
	{
		ft_putstr("0x");
		parser->len += 2;
		ft_putstr(str);
		len = display_width(parser, ' ', len + 2);
	}
	else if (parser->flags[1] == 1)
	{
		ft_putstr("0x");
		parser->len += 2;
		len = display_width(parser, '0', len + 2);
		ft_putstr(str);
	}
	else
	{
		len = display_width(parser, ' ', len + 2);
		ft_putstr("0x");
		parser->len += 2;
		ft_putstr(str);
	}
}

void			display_case2_p(t_print *parser, char *str, int tmp, int len)
{
	if (parser->precision > len)
	{
		if (parser->flags[0] == 0)
		{
			tmp = display_precision(parser, 1, tmp + 2);
			ft_putstr("0x");
			parser->len += 2;
			len = display_precision(parser, 0, len);
			ft_putstr(str);
		}
		if (parser->flags[0] == 1)
		{
			ft_putstr("0x");
			parser->len += 2;
			len = display_precision(parser, 0, len);
			ft_putstr(str);
			tmp = display_precision(parser, 1, tmp + 2);
		}
	}
}

void			display_case3_p(t_print *parser, char *str, int len)
{
	if (parser->flags[0] == 1)
	{
		ft_putstr("0x");
		parser->len += 2;
		ft_putstr(str);
		len = display_width(parser, ' ', len + 2);
	}
	else if (parser->flags[1] == 1)
	{
		len = display_width(parser, '0', len + 2);
		ft_putstr("0x");
		parser->len += 2;
		ft_putstr(str);
	}
	else
	{
		len = display_width(parser, ' ', len + 2);
		ft_putstr("0x");
		parser->len += 2;
		ft_putstr(str);
	}
}
