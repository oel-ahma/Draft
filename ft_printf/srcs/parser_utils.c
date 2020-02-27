/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:07:02 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/07 17:40:50 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	asterisk_check(t_print *parser, int j, int b)
{
	if (b == 1)
		b = parser->i;
	else
	{
		b = j;
		while (parser->format[b] == '0')
			b++;
	}
	if (parser->format[b] == '*')
	{
		parser->flags[2] = va_arg(parser->ap, int);
		if (parser->flags[2] < 0)
		{
			parser->flags[2] = -parser->flags[2];
			parser->flags[0] = 1;
		}
		b++;
	}
	return (b);
}

int			parse_case1(t_print *parser, int j)
{
	if (parser->format[j] == '-')
	{
		parser->flags[0] = 1;
		parser->flags[2] = 0;
		j++;
		if (parser->format[j] == '*')
		{
			parser->flags[2] = va_arg(parser->ap, int);
			if (parser->flags[2] < 0)
				parser->flags[2] = -parser->flags[2];
			j++;
		}
		while (ft_isdigit(parser->format[j]) == 1)
		{
			parser->flags[2] *= 10;
			parser->flags[2] += (parser->format[j] - 48);
			j++;
		}
		j--;
	}
	return (j);
}

int			parse_case2(t_print *parser, int j)
{
	if (parser->flags[0] == 0 && parser->b == 0)
	{
		if (parser->format[j] == '0')
		{
			parser->flags[1] = 1;
			parser->flags[2] = 0;
			parser->b = 1;
			j++;
			j = asterisk_check(parser, j, 0);
			while (ft_isdigit(parser->format[j]) == 1)
			{
				parser->flags[2] *= 10;
				parser->flags[2] += (parser->format[j] - 48);
				j++;
			}
			if (parser->flags[2] == 0)
			{
				j--;
				parser->b = 1;
			}
		}
	}
	return (j);
}

int			parse_case3(t_print *parser, int j)
{
	if (parser->flags[0] == 0 && parser->flags[1] == 0 && parser->b == 0)
	{
		parser->flags[2] = 0;
		j = asterisk_check(parser, j, 1);
		while (ft_isdigit(parser->format[j]) == 1)
		{
			parser->flags[2] *= 10;
			parser->flags[2] += (parser->format[j] - 48);
			j++;
		}
		if (parser->flags[2] == 0)
		{
			j--;
			parser->b = 1;
		}
		else
			parser->b = 1;
	}
	return (j);
}
