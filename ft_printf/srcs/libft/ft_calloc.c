/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:24:42 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/10/30 17:07:42 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*p;
	size_t	size;

	size = elementcount * elementsize;
	if (size == 0)
		size = 1;
	if ((p = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_memset(p, 0, size);
	return (p);
}
