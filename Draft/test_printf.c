/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:33:32 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/13 18:18:47 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	const char 		*format;
	char			flag;
	char			width;
	char			precision;
	char			type;
	size_t			count;
	size_t			i;
	va_list			ap;

}				t_list;

int ft_printf(char *format)
{
	t_list	*tmp;

	if(!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	tmp->format = format;
	tmp = init(tmp);
	if (format)
	{
		va_start(tmp->ap, format);
		tab->len = parsers(tmp);
		va_end(tab->args);
	}
	free(tmp);
	return (tmp->count);
}
