/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:35:46 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/01/30 16:39:11 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*min_maj(char c)
{
	if (c == 'a')
		return ("0123456789abcdef");
	else if (c == 'A')
		return ("0123456789ABCDEF");
	else
		return (NULL);
}

char	*calcul(char *str, size_t *tmp, size_t base, char *tab)
{
	while (tmp[1] > tmp[0])
	{
		str[tmp[1] - 1] = tab[ft_abs(tmp[2] % base)];
		tmp[1]--;
		tmp[2] /= base;
	}
	return (str);
}

char	*ft_itoa_base(size_t value, size_t base, char c)
{
	char		*str;
	size_t		tmp[4];
	char		*tab;

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = value;
	tab = min_maj(c);
	if (base < 2 || base > 16)
		return (NULL);
	if (tmp[2] < 0 && base == 10)
		tmp[0] = 1;
	tmp[3] = tmp[2];
	while (tmp[3] /= base)
		tmp[1]++;
	tmp[1] = tmp[1] + tmp[0] + 1;
	str = (char *)malloc(sizeof(char) * tmp[1] + 1);
	str[tmp[1]] = '\0';
	if (tmp[0] == 1)
		str[0] = '-';
	str = calcul(str, tmp, base, tab);
	return (str);
}
