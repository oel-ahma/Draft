/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:53:50 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/04 13:55:22 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct	s_print
{
	const char	*format;
	int			flags[3];
	int			precision;
	char		type;
	size_t		len;
	size_t		i;
	size_t		b;
	char		*type_mask;
	va_list		ap;
}				t_print;

int				ft_printf(const char *format, ...);
int				parsers(t_print *parser);

int				display_d(t_print *parser);
int				display(t_print *parser);
int				display_u(t_print *parser);
int				display_c(t_print *parser);
int				display_s(t_print *parser);
int				display_x(t_print *parser);
int				display_p(t_print *parser);
int				display_percent(t_print *parser);

char			*signed_hexa(size_t num, char *base);
char			*signed_u(size_t num, char *base);
void			reset(t_print *parser);
t_print			*init(t_print *parser);
int				parsing(t_print *parser);
void			parse_type(t_print *parser);
void			parse_flags(t_print *parser);
void			parse_width(t_print *parser);
void			parse_precision(t_print *parser);

void			display_case1(t_print *parser, char *str, int len);
void			display_case2(t_print *parser, char *str, int tmp, int len);
void			display_case3(t_print *parser, char *str, int len);
void			display_case1_d(t_print *parser, char *str, int len, int sign);
void			display_case2_d(t_print *parser, char *str, int tmp, int len);
void			display_case3_d(t_print *parser, char *str, int len, int sign);
void			display_case1_p(t_print *parser, char *str, int len);
void			display_case2_p(t_print *parser, char *str, int tmp, int len);
void			display_case3_p(t_print *parser, char *str, int len);
int				parse_case1(t_print *parse, int j);
int				parse_case2(t_print *parse, int j);
int				parse_case3(t_print *parse, int j);

#endif
