/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:15:23 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/31 15:29:24 by oel-ahma         ###   ########.fr       */
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

static	void	display_s2(t_print *parser, char *str, int len)
{
	if (parser->flags[0] == 1)
	{
		ft_putstr(str);
		display_width(parser, ' ', len);
	}
	else if (parser->flags[1] == 1)
	{
		display_width(parser, '0', len);
		ft_putstr(str);
	}
	else
	{
		display_width(parser, ' ', len);
		ft_putstr(str);
	}
}

int				display_s(t_print *parser)
{
	char	*str;
	int		len;
	char	*tmp;

	tmp = va_arg(parser->ap, char *);
	if (!tmp)
		tmp = ft_strdup("(null)");
	if (parser->precision > -1)
		str = ft_strndup(tmp, parser->precision);
	else
		str = tmp;
	len = (size_t)ft_strlen(str);
	parser->len += len;
	display_s2(parser, str, len);
	if (parser->precision > -1)
		free(str);
	return (1);
}
