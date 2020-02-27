/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:31:36 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/07 19:22:55 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	display_width(t_print *parser, char c, int len)
{
	while ((parser->flags[2] - len) > 0)
	{
		ft_putchar(c);
		len++;
		parser->len++;
	}
	return (len);
}

static	int	display_precision(t_print *parser, int b, int tmp)
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

void		display_case1(t_print *parser, char *str, int len)
{
	if (parser->flags[0] == 1)
	{
		ft_putstr(str);
		len = display_width(parser, ' ', len);
	}
	else if (parser->flags[1] == 1)
	{
		len = display_width(parser, '0', len);
		ft_putstr(str);
	}
	else
	{
		len = display_width(parser, ' ', len);
		ft_putstr(str);
	}
}

void		display_case3(t_print *parser, char *str, int len)
{
	if (parser->flags[0] == 1)
	{
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
		len = display_width(parser, ' ', len);
	}
	else if (parser->flags[1] == 1 && parser->precision > len)
	{
		len = display_width(parser, '0', len);
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
	}
	else if (parser->flags[1] == 1 && parser->precision < 0)
	{
		len = display_width(parser, '0', len);
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
	}
	else
	{
		len = display_width(parser, ' ', len);
		if (parser->precision != 0 || (ft_strncmp(str, "0", 1) != 0))
			ft_putstr(str);
	}
}

void		display_case2(t_print *parser, char *str, int tmp, int len)
{
	if (parser->precision > len)
	{
		if (parser->flags[0] == 0)
		{
			tmp = display_precision(parser, 1, tmp);
			len = display_precision(parser, 0, len);
			ft_putstr(str);
		}
		if (parser->flags[0] == 1)
		{
			len = display_precision(parser, 0, len);
			ft_putstr(str);
			tmp = display_precision(parser, 1, tmp);
		}
	}
}
