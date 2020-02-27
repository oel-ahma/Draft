/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:35:13 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 15:49:04 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display(t_print *parser)
{
	if (parser->type == 'd' || parser->type == 'i')
		return (display_d(parser));
	if (parser->type == 'u')
		return (display_u(parser));
	if (parser->type == 's')
		return (display_s(parser));
	if (parser->type == 'c')
		return (display_c(parser));
	if (parser->type == 'x' || parser->type == 'X')
		return (display_x(parser));
	if (parser->type == 'p')
		return (display_p(parser));
	if (parser->type == '%')
		return (display_percent(parser));
	return (0);
}
