/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:42:29 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 14:49:00 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_getnbr(const char *nb, const char *base, int len)
{
	int			is_neg;
	long long	total;
	int			i;

	total = 0;
	is_neg = 1;
	if (*nb == '-')
	{
		is_neg = -1;
		nb++;
	}
	while (*nb)
	{
		i = 0;
		while (base[i] && base[i] != *nb)
			i++;
		total = total * len + i;
		nb++;
	}
	return (total * is_neg);
}

static void			ft_convert_base_2_fill(long nb, const char *base, \
		int new_len, char *new)
{
	int			i;
	long long	tmp;
	long long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb < 0)
	{
		new_len--;
		*new = '-';
		nb *= -1;
		new++;
	}
	while (new_len)
	{
		i = 1;
		tmp = nb;
		while (i++ < new_len)
			tmp = tmp / base_len;
		*new = base[tmp % base_len];
		new++;
		new_len--;
	}
	*new = '\0';
}

static char			*ft_convert_base_2(long nb, const char *base, int len)
{
	char	*new;
	long	tmp;
	int		new_len;

	if (nb < 0)
		new_len = 3;
	else
		new_len = 2;
	tmp = nb;
	if (tmp < 0)
		tmp *= -1;
	while (tmp >= len)
	{
		tmp = tmp / len;
		new_len++;
	}
	if (!(new = malloc(new_len)))
		return (NULL);
	ft_convert_base_2_fill(nb, base, new_len - 1, new);
	return (new);
}

char				*ft_convert_base(const char *nbr, const char *base_from, \
		const char *base_to)
{
	long	nb;
	int		from_len;
	int		to_len;

	to_len = 0;
	from_len = 0;
	while (base_from[from_len])
		from_len++;
	while (base_to[to_len])
		to_len++;
	nb = ft_getnbr(nbr, base_from, from_len);
	return (ft_convert_base_2(nb, base_to, to_len));
}
