/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:10:24 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/11/08 17:33:06 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_list
{
	char			flag;
	char			width;
	char			precision;
	char			type;
	struct s_list	*next;
}				t_list;

static t_list	*ft_lstnew(char content)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	return (list);
}

static int fill_occur(const char *str, t_list *occur)
{
	int i;
	int ret;
	//	t_list;
	i = 0;
	ret = 0;

	printf("Hello");
	while (str)
	{
		if (str[i] == '%')
		{

			printf("Hello");
			occur = ft_lstnew('c');
			i++;
			if (str[i] == 'd')
			{
				occur->type = 'd';
				ret++;
			}
			else if (str[i] == 'c')
			{
				occur->type = 'c';
				ret++;
			}
		}
		i++;
		occur = occur->next;
	}
	return (ret);
}

int ft_printf(const char *format)
{
	const char 	*tmp = NULL;
	int 		i = 0;
	t_list		*occur = NULL;

	printf("hw");
	i = fill_occur(format, occur);
	printf("Number of occurences is\t:\t%d\n", i);

	return (1);
}

int main()
{
	ft_printf("aaaaa%deeee%c");
}
