# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 23:28:32 by sklaokli          #+#    #+#              #
#    Updated: 2025/04/12 12:10:31 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libraries
NAME		:=	push_swap
GNL			:=	get_next_line

## Paths to files
SRC_DIR		:=	sources
OBJ_DIR		:=	objects
INC_DIR		:=	include
GNL_DIR		:=	$(addprefix $(INC_DIR)/, get_next_line)

## Source files
SRC			:=	$(addprefix $(SRC_DIR)/, $(FILES))
FILES		:=	main.c ft_split.c stack.c utils.c \
				action.c tiny.c butterfly.c sort.c

## Include files
INC			:=	-I $(INC_DIR)

## Object files
OBJ			:=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

## Total number of files
COMPILED	:=	0
TOTAL_FILES	:=	$(words $(OBJ))

## Commands
RM			:=	rm -f
CC			:=	cc
LIBC		:=	ar rcs
FLAGS		:=	-Wall -Wextra -Werror

## Color Codes
CYAN		:=	\033[0;36m
GREEN		:=	\033[0;32m
RED			:=	\033[0;31m
BLUE		:=	\033[0;34m
YELLOW		:=	\033[0;33m
RESET		:=	\033[0m

## Targets
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

all:		$(NAME)

$(NAME):	$(GNL) $(OBJ) Makefile
			@ $(CC) $(FLAGS) $(OBJ) $(INC) -o $(NAME)
			@ echo "$(GREEN)Done! $(NAME) is now ready.$(RESET)"

$(GNL):		Makefile
			@ $(MAKE) -sC $(GNL_DIR)

clean:
			@ $(MAKE) -sC $(GNL_DIR) clean
			@ $(RM) -rf $(OBJ_DIR)
			@ echo "$(CYAN)All $(NAME) object files have been cleaned.$(RESET)"

fclean:
			@ $(MAKE) -sC $(GNL_DIR) fclean
			@ $(RM) -rf $(OBJ_DIR) $(NAME)
			@ echo "$(CYAN)All $(NAME) executable files have been cleaned.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re