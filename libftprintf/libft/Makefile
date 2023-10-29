# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 19:24:41 by ffons-ti          #+#    #+#              #
#    Updated: 2023/02/25 12:24:30 by ffons-ti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

HDRS			= libft.h

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_calloc.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strdup.c \
					ft_tolower.c ft_bzero.c   ft_isascii.c ft_strnstr.c \
					ft_memmove.c ft_strlen.c  ft_strrchr.c ft_substr.c \
					ft_toupper.c ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_strjoin.c ft_itoa.c    ft_strtrim.c ft_split.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c
					
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c
		  
BONUS_OBJS = ${BONUS:.c=.o}

ifdef WITH_BONUS
OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
OBJ_FILES = $(OBJS)
endif

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

.c.o: 			$(SRCS)
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				
$(NAME):		$(OBJ_FILES)
				@ar rc  $@ $^
				@echo "Libft.a created!"
				
bonus:
				$(MAKE) WITH_BONUS=1 all
				
clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			bonus all clean fclean re 

