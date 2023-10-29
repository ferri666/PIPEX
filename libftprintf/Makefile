NAME 			= libftprintf.a

SRC_DIR 		= srcs/

LIBFT			= libft


OBJ_DIR			= obj/

INCLUDE 		= include
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I
AR				= ar rcs

SRC_FILES		=	ft_format ft_printf ft_printnbr ft_printhex ft_printptr

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))



all:			$(NAME)

$(NAME):		$(OBJ)
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@mv libft.a $(NAME)
					@$(AR) $(NAME) $(OBJ)
					@echo "Printf.a created!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus:				$(OBJ)

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C $(LIBFT)
					@$(RM) $(OBJ)

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)/libft.a
					@echo "Clean Boys Indeed!"

re:					fclean $(NAME)

norm:			
					@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true


.PHONY:				all bonus clean fclean re norm