# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboussau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 17:41:56 by cboussau          #+#    #+#              #
#    Updated: 2016/11/08 15:07:57 by cboussau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	   ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	   ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c\
	   ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c\
	   ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c\
	   ft_toupper.c ft_isspace.c ft_putendl.c ft_strsplit.c ft_strsub.c\
	   ft_strnew.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_putchar_fd.c\
	   ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strclr.c ft_striter.c\
	   ft_striteri.c ft_strmap.c ft_strequ.c ft_strnequ.c ft_memalloc.c\
	   ft_memdel.c ft_strdel.c ft_strmapi.c ft_strsub.c ft_strjoin.c\
	   ft_strnjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_isspace.c\
	   ft_reverse.c ft_lstadd.c ft_lstdelone.c ft_lstiter.c ft_lstdel.c\
	   ft_lstnew.c ft_lstmap.c ft_nbrlen.c ft_itoa_base.c ft_swap.c\
	   ft_tablen.c get_next_line.c ft_strsplit_ws.c ft_print_tab.c\
	   ft_strlen_char.c ft_putchar_int.c ft_chardup.c ft_strccmp.c\
	   ft_wipespace.c ft_free_tab.c ft_strclen.c ft_strchr_int.c ft_tabdup.c \
	   join_tab.c print_memory.c

OBJS = $(SRCS:.c=.o)
INCLUDE = ./include/
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
	
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re
