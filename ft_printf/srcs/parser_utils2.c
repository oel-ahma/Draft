/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:30 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/04 13:02:21 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_check(char c)
{
	char	*type_mask;
	int		i;

	type_mask = "cspdiuxX%";
	i = 0;
	while (type_mask[i])
	{
		if (c == type_mask[i])
			return (1);
		i++;
	}
	return (0);
}

void	parse_flags(t_print *parser)
{
	size_t	j;

	j = parser->i;
	while (type_check(parser->format[j]) != 1 && parser->format[j])
	{
		j = parse_case1(parser, j);
		j = parse_case2(parser, j);
		j = parse_case3(parser, j);
		j++;
	}
}

void	parse_precision(t_print *parser)
{
	size_t	j;

	j = parser->i;
	while (type_check(parser->format[j]) != 1 && parser->format[j])
	{
		while (parser->format[j] == '.')
		{
			j++;
			parser->precision = 0;
			parser->b = 0;
			if (parser->format[j] == '*')
			{
				parser->precision = va_arg(parser->ap, int);
				j++;
				parser->b = 1;
			}
			while (ft_isdigit(parser->format[j]) == 1 && parser->b == 0)
			{
				parser->precision *= 10;
				parser->precision += (parser->format[j] - 48);
				j++;
			}
		}
		j++;
	}
}

void	parse_type(t_print *parser)
{
	size_t	j;

	j = parser->i;
	while (type_check(parser->format[j]) != 1 && parser->format[j])
		j++;
	parser->type = parser->format[j];
	parser->i = j;
}
