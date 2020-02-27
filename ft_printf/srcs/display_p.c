/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:25:53 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/05 17:45:31 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*get_str(t_print *parser, char *tmp2)
{
	char *str;

	str = ft_convert_base(tmp2, "0123456789", "0123456789abcdef");
	if (parser->precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	return (str);
}

int				display_p(t_print *parser)
{
	char	*str;
	int		len;
	size_t	tmp;
	char	*tmp2;

	tmp = va_arg(parser->ap, size_t);
	tmp2 = ft_itoa((size_t)tmp);
	if (!(str = get_str(parser, tmp2)))
		return (-1);
	len = (size_t)ft_strlen(str);
	parser->len += len;
	tmp = 0;
	if (parser->precision == -1)
		display_case1_p(parser, str, len);
	else
	{
		if (parser->precision > len)
			display_case2_p(parser, str, tmp, len);
		else
			display_case3_p(parser, str, len);
	}
	free(str);
	free(tmp2);
	return (1);
}
