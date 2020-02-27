/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:46:43 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/07 19:22:31 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*positive_hexa(t_print *parser, size_t tmp)
{
	char *str;

	str = NULL;
	if (parser->type == 'x')
	{
		if (!(str = ft_itoa_base((size_t)tmp, 16, 'a')))
			return (NULL);
	}
	else if (parser->type == 'X')
	{
		if (!(str = ft_itoa_base((size_t)tmp, 16, 'A')))
			return (NULL);
	}
	return (str);
}

static	char	*negative_hexa(t_print *parser, size_t tmp)
{
	char *str;

	str = NULL;
	tmp = -tmp;
	if (parser->type == 'x')
	{
		if (!(str = signed_hexa((size_t)tmp, "0123456789abcdef")))
			return (NULL);
	}
	else if (parser->type == 'X')
	{
		if (!(str = signed_hexa((size_t)tmp, "0123456789ABCDEF")))
			return (NULL);
	}
	return (str);
}

static	char	*sign_check(t_print *parser, size_t tmp)
{
	char *str;

	str = NULL;
	if (tmp >= 0)
	{
		if (!(str = positive_hexa(parser, tmp)))
			return (NULL);
	}
	else
	{
		if (!(str = negative_hexa(parser, tmp)))
			return (NULL);
	}
	return (str);
}

int				display_x(t_print *parser)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = (unsigned int)va_arg(parser->ap, unsigned int);
	if (!(str = sign_check(parser, tmp)))
		return (-1);
	len = (size_t)ft_strlen(str);
	if (parser->precision == 0 && ft_strncmp(str, "0", 1) == 0)
		len = 0;
	parser->len += len;
	tmp = 0;
	if (parser->precision == -1)
		display_case1(parser, str, len);
	else
	{
		if (parser->precision > len)
			display_case2(parser, str, tmp, len);
		else
			display_case3(parser, str, len);
	}
	free(str);
	return (1);
}
