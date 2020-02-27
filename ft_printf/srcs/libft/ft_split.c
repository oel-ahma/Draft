/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:44:27 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/10/28 14:08:35 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

int		count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s, c))
			s++;
		if (*s && !ft_isspace(*s, c))
		{
			count++;
			while (*s && !ft_isspace(*s, c))
				s++;
		}
	}
	return (count);
}

char	*malloc_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && !ft_isspace(s[i], c))
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && !ft_isspace(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s || !(arr = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_isspace(*s, c))
			s++;
		if (*s && !ft_isspace(*s, c))
		{
			arr[i] = malloc_word(s, c);
			i++;
			while (*s && !ft_isspace(*s, c))
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
