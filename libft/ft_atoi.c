/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 03:26:58 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/04 18:29:24 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	convert_nbr(const char *str, int i)
{
	int		nbr;
	int		tmp;

	nbr = 0;
	tmp = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr + (str[i] - 48) * tmp;
		i--;
		tmp = tmp * 10;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		signe;
	int		i;

	i = 0;
	signe = 1;
	while ((str[i] != '\0') && ((str[i] == ' ') || (str[i] == '\t')
				|| (str[i] == '\n') || (str[i] == '\v')
				|| (str[i] == '\f') || (str[i] == '\r')))
		i++;
	if (str[i] == '-')
	{
		signe = signe * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (convert_nbr(str, i - 1) * signe);
}
