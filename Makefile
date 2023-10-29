NAME            = pipex

BONUS           = pipex_bonus

LIBFT_DIR       = libftprintf

LIBFT           = libftprintf.a
 
INCLUDE         = include/
 
SRC_DIR         = src/
 
OBJ_DIR         = obj/
 
SRC_FILES       = path utils pipex error
B_FILES       	= utils_bonus pipex_bonus path error
CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -g3 -fsanitize=address -I $(INCLUDE)
AR              = ar rcs
 
SRC             =   $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ             =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_B           =   $(addprefix $(SRC_DIR), $(addsuffix .c, $(B_FILES)))
OBJ_B           =   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_FILES)))

$(NAME)         :   $(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) -o $@ $^
					@echo "Program Created!"

all:                $(NAME) $(BONUS)

bonus			:	$(BONUS)

$(BONUS)		:	$(OBJ_B) $(LIBFT)
					@$(CC) $(CFLAGS) -o $(BONUS) $^
					@echo "Bonus Created!"
$(LIBFT):              
					@make -C $(LIBFT_DIR)
					@cp $(LIBFT_DIR)/$(LIBFT) .

$(OBJ_DIR)%.o   :   $(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

clean:             
					@$(RM) $(OBJ)
					@rm -rf $(OBJ_DIR)
					@make -C $(LIBFT_DIR) clean
					@echo "Clean Boys!"
 
fclean:				clean
					@make -C $(LIBFT_DIR) fclean
					@$(RM) $(LIBFT)
					@$(RM) $(NAME)
					@$(RM) $(BONUS)
					@echo "Super Clean Boys Forever!"
 
re:                 fclean $(NAME)

re-bonus:           fclean $(BONUS)

re-all:          	fclean all
 
norm:          
					@norminette $(SRC_DIR) $(INCLUDE) $(LIBFT_DIR) | grep -v Norme -B1 || true
 
 
.PHONY:				all clean fclean re norm bonus re-bonus re-all
