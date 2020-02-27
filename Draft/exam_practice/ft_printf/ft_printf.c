/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:27:56 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/27 16:57:35 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_print
{
	va_list	ap;
	char *format;
	int precision;
	int flag;
	int i;
	char type;
	int len;
}	t_print;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i = 0;

	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char *ft_strdup(char *s)
{
	int i;
	char *str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strndup(char *s, int n)
{
	int i;
	char *str;

	i = 0;
	while (s[i] && i < n)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_itoa(long nbr)
{
	char *ret;
	long n;
	int i;

	i = 0;
	n = nbr;
	while (n / 10 > 0)
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	n = nbr;
	ret[i] = '\0';
	i--;
	while (i > 0)
	{
		ret[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (ret);
}

char *convert_hexa(long nbr)
{
	char *ret;
	long n;
	char *mask_hex = "0123456789abcdef";
	int i;

	i = 0;
	n = nbr;
	while (n / 16 > 0)
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	n = nbr;
	ret[i] = '\0';
	i--;
	while (i > 0)
	{
		ret[i] = mask_hex[n % 16];
		n = n / 16;
		i--;
	}
	return (ret);
}
int display(t_print *parser)
{
	char *str;
	char *tmp_s;
	int tmp_d;
	int len;
	int sign = 0;

	if (parser->type == 's')
	{
		tmp_s = va_arg(parser->ap, char *);
		if (!tmp_s)
			str = ft_strdup("(null)");
		if (parser->precision != -1)
			str = ft_strndup(tmp_s, parser->precision);
		len = ft_strlen(str);
		parser->len += len;
		if (parser->flag > 0)
		{
			while (parser->flag - len >= 0)
			{
				ft_putchar(' ');
				parser->flag++;
				parser->len++;
			}
		}
		ft_putstr(str);
	}
	if (parser->type == 'd')
	{
		tmp_d = va_arg(parser->ap, int);
		if (tmp_d < 0)
		{
			tmp_d *= -1;
			sign = 1;
		}
		str = ft_itoa(tmp_d);
		len = ft_strlen(str);
		parser->len += len;/*
							  if (parser->flag > parser->precision)
							  {
							  while (parser->flag - parser->precision > 0)
							  {
							  ft_putchar(' ');
							  parser->flag++;
							  parser->len++;
							  }
							  }
							  if (sign == 1)
							  {
							  ft_putchar('-');
							  parser->len++;
							  }
							  while (parser->precision - len > 0)
							  {
							  ft_putchar('0');
							  parser->len++;
							  parser->precision++;
							  }*/
		ft_putstr(str);
	}
	/*	if (parser->type == 'x')
		{
		tmp_d = va_arg(parser->ap, unsigned int);
		if (tmp_d < 0)
		{
		tmp_d *= -1;
		str = convert_hexa(tmp_d);
		}
		str = convert_hexa(tmp_d);
		len = ft_strlen(str);
		parser->len += len;
		if (parser->flag > parser->precision)
		{
		while (parser->flag - parser->precision > 0)
		{
		ft_putchar(' ');
		parser->flag++;
		parser->len++;
		}
		}
		while (parser->precision - len > 0)
		{
		ft_putchar('0');
		parser->len++;
		parser->precision++;
		}
		ft_putstr(str);
		}*/
	free(str);
	return (1);
}	



int parsing(t_print *parser)
{

	if (ft_strcmp(parser->format, "%") == 0)
		return (0);
	while (parser->format[parser->i])
	{
		if (parser->format[parser->i] == '%')
		{
			parser->i++;
			while (ft_isdigit(parser->format[parser->i]))
			{
				parser->flag = parser->flag + (parser->format[parser->i] - 48);
				parser->i++;
			}
			while (parser->format[parser->i] == '.')
			{
				parser->precision = 0;
				parser->i++;
				while (ft_isdigit(parser->format[parser->i]))
				{
					parser->precision = parser->precision + (parser->format[parser->i] - 48);
					parser->i++;
				}
			}
			parser->type = parser->format[parser->i];
			parser->i++;
			if (!display(parser))
				return (0);
		}
		else
		{
			ft_putchar(parser->format[parser->i]);
			parser->i++;
			parser->len++;
		}
	}

	return (1);
}





int ft_printf(char *format, ...)
{
	t_print *parser;
	int len;
	if (!(parser = (t_print*)malloc(sizeof(t_print))))
		return (-1);
	parser->precision = 0;
	parser->flag = 0;
	parser->i = 0;
	parser->type = '\0';
	parser->len = 0;
	len = 0;
	parser->format = format;

	if (format)
	{
		printf("fff");
		va_start(parser->ap, format);
		len = parsing(parser);
		va_end(parser->ap);
	}
	free(parser);
	return (len);
}


