/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:03:41 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 15:49:33 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print *parser;
	size_t	len;

	len = 0;
	if (!(parser = (t_print *)malloc(sizeof(t_print))))
		return (-1);
	parser->format = format;
	parser = init(parser);
	if (format)
	{
		va_start(parser->ap, format);
		len = parsers(parser);
		va_end(parser->ap);
	}
	free(parser);
	return (len);
}
