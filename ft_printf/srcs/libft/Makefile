# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 17:05:17 by oel-ahma          #+#    #+#              #
#    Updated: 2020/02/05 17:49:41 by oel-ahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
OPTS	= -Wall -Wextra -Werror

SRCS	= ft_strlen.c ft_memset.c ft_bzero.c \
		  ft_strchr.c ft_strrchr.c ft_isalpha.c \
		  ft_isdigit.c ft_isalnum.c ft_isprint.c \
		  ft_toupper.c ft_tolower.c ft_strcmp.c ft_strncmp.c \
		  ft_calloc.c ft_atoi.c ft_strdup.c ft_strlcpy.c \
		  ft_strnstr.c ft_strlcat.c ft_memcpy.c \
		  ft_memccpy.c ft_memcmp.c ft_memchr.c \
		  ft_memmove.c ft_isascii.c ft_putchar.c ft_putchar_fd.c \
		  ft_putstr.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_strmapi.c ft_strjoin.c ft_strtrim.c \
		  ft_split.c ft_itoa.c ft_substr.c \
		  ft_convert_base.c ft_strndup.c ft_itoa_base.c

BONUS	= ft_lstadd_back.c ft_lstsize.c ft_lstadd_front.c\
		  ft_lstnew.c ft_lstclear.c ft_lstdelone.c\
		  ft_lstmap.c ft_lstiter.c ft_lstlast.c \

OBJS	= $(SRCS:.c=.o)

RM		= rm -rf
INC		= libft.h

all		: $(NAME) 

$(NAME)	:
	$(CC) $(OPTS) -I $(INC) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus	:
	$(CC) $(OPTS) -I $(INC) -c $(BONUS)
	ar rc $(NAME) $(BONUS:.c=.o)
	ranlib $(NAME)

clean	:
	rm -f $(OBJS) $(BONUS:.c=.o)

fclean	: clean
	rm -f $(NAME)

re		: fclean all

.PHONY:	all clean fclean re bonus
