/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_practice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:05:08 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/13 16:17:27 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int parsing(t_printf *parser)
{
	if (ft_strcmp(parser->format, "%") == 0)
		return (0);
	while (parser->format[parser->i])
	{
		if (parser->format[parser->i] == '%')
		{
			parser->i++;
			reset(parser);
			if (!(parsering(parser)))
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

int ft_printf(char *format, ...)
{
	t_printf *parser;
	int len;

	len = 0;
	if (!(parser = (t_printf)malloc(sizeof(t_printf))))
		return (-1);	
	parser->format = format;
	parser = init
		if (format)
		{
			parser->ap = va_start(ap, format);
			len = parsing(parser);
			va_end(parser->ap);
		}
	free(parser);
	return (len);
}

