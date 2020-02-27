# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 13:16:25 by oel-ahma          #+#    #+#              #
#    Updated: 2020/02/05 15:37:39 by oel-ahma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I srcs/libft/

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	srcs/libft/

CFILE =		ft_printf.c \
			parsers.c \
			parser_utils.c \
			parser_utils2.c \
			init.c \
			display.c \
			display_percent.c \
			display_c.c \
			display_u.c \
	  		display_s.c \
	  	    signed_hexa.c \
			signed_u.c \
			display_d.c \
	  		display_x.c \
			display_p.c \
			display_utils.c \
			display_utils_d.c \
			display_utils_p.c \

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory

$(NAME): $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FT_PRINTF COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean fclean re
