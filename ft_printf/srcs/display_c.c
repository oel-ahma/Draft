/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:04:52 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/31 15:21:56 by oel-ahma         ###   ########.fr       */
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

int			display_c(t_print *parser)
{
	int	c;
	int i;

	i = 1;
	c = va_arg(parser->ap, int);
	parser->len++;
	if (parser->flags[0] == 1)
	{
		ft_putchar(c);
		display_width(parser, ' ', i);
	}
	else if (parser->flags[1] == 1)
	{
		display_width(parser, '0', i);
		ft_putchar(c);
	}
	else
	{
		display_width(parser, ' ', i);
		ft_putchar(c);
	}
	return (1);
}
