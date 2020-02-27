/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:06:40 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/13 14:45:14 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset(t_print *parser)
{
	parser->type = '\0';
	parser->flags[0] = 0;
	parser->flags[1] = 0;
	parser->flags[2] = 0;
	parser->b = 0;
	parser->precision = -1;
}

int		parsing(t_print *parser)
{
	parse_flags(parser);
	parse_precision(parser);
	parse_type(parser);
	return (display(parser));
}

int		parsers(t_print *parser)
{
	if (ft_strcmp((char *)parser->format, "%") == 0)
		return (0);
	while (parser->format[parser->i])
	{
		if (parser->format[parser->i] == '%')
		{
			parser->i++;
			reset(parser);
			if (!parsing(parser))
				return (0);
		}
		else
		{
			ft_putchar(parser->format[parser->i]);
			parser->len++;
		}
		parser->i++;
	}
	return (parser->len);
}
