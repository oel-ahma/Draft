/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:12:47 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/02/05 17:14:16 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sign(long long a)
{
	if (a < 0)
		return (1);
	return (0);
}

char	*convert_number(int i, long long nb, char *nbr, long long n)
{
	while (i > 0)
	{
		nbr[i + sign(n) - 1] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
		if (i == 0 && sign(n) == 1)
		{
			nbr[0] = '-';
			break ;
		}
	}
	return (nbr);
}

char	*ft_itoa(long long n)
{
	int			i;
	long long	nb;
	char		*nbr;

	i = 0;
	nb = n;
	while ((nb = nb / 10) != 0)
		i++;
	i = i + 1;
	if (!(nbr = (char *)malloc((i + 1 + sign(n)) * sizeof(char))))
		return (NULL);
	nb = n;
	if (sign(n) == 1)
		nb = -nb;
	nbr[i + sign(n)] = '\0';
	return (convert_number(i, nb, nbr, n));
}
