/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:39:29 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 15:52:53 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*init(t_print *tmp)
{
	tmp->len = 0;
	tmp->i = 0;
	tmp->type_mask = "cspdiuxX%";
	tmp->precision = 0;
	tmp->flags[0] = 0;
	tmp->flags[1] = 0;
	tmp->flags[2] = 0;
	tmp->b = 0;
	return (tmp);
}
