/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:46:19 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/31 14:37:54 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			display_u(t_print *parser)
{
	char	*str;
	int		len;
	int		tmp;

	tmp = (int)va_arg(parser->ap, int);
	if (tmp < 0)
		str = signed_u(-tmp, "0123456789");
	else
		str = ft_itoa(tmp);
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
