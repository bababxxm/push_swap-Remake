# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 23:28:32 by sklaokli          #+#    #+#              #
#    Updated: 2025/04/12 16:20:00 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libraries
NAME		=	push_swap
CHECKER		=	checker
GNL			=	$(GNL_DIR)/get_next_line

## Paths to files
SRC_DIR		:=	sources
OBJ_DIR		:=	objects
INC_DIR		:=	include
GNL_DIR		:=	get_next_line

## Subdirectories
MANDA_DIR	:=	mandatory
BONUS_DIR	:=	bonus
UTILS_DIR	:=	utils

## Source files
MANDA_FILES	:=	main.c
BONUS_FILES	:=	checker.c
UTILS_FILES	:=	init.c ft_split.c stack.c utils.c \
				action.c tiny.c butterfly.c sort.c

SRC_MANDA	:=	$(addprefix $(SRC_DIR)/$(MANDA_DIR)/, $(MANDA_FILES))
SRC_BONUS	:=	$(addprefix $(SRC_DIR)/$(BONUS_DIR)/, $(BONUS_FILES))
SRC_UTILS	:=	$(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS_FILES))

OBJ_MANDA	:=	$(addprefix $(OBJ_DIR)/$(MANDA_DIR)/, $(MANDA_FILES:.c=.o))
OBJ_BONUS	:=	$(addprefix $(OBJ_DIR)/$(BONUS_DIR)/, $(BONUS_FILES:.c=.o))
OBJ_UTILS	:=	$(addprefix $(OBJ_DIR)/$(UTILS_DIR)/, $(UTILS_FILES:.c=.o))

## Include
INC			:=	-I $(INC_DIR) -I $(GNL_DIR)/include

## Counters for progress
COMPILED	:=	0
TOTAL_FILES	:=	$(words $(OBJ_MANDA) $(OBJ_BONUS))

## Commands
RM			:=	rm -f
CC			:=	cc
FLAGS		:=	-Wall -Wextra -Werror

## Colors
CYAN		:=	\033[0;36m
GREEN		:=	\033[0;32m
RED			:=	\033[0;31m
BLUE		:=	\033[0;34m
YELLOW		:=	\033[0;33m
RESET		:=	\033[0m

## Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@ mkdir -p $(dir $@)
				@ $(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
				@ PERCENT=$$(($(COMPILED)*100/$(TOTAL_FILES))); \
				echo "$(BLUE)[$(COMPILED)/$(TOTAL_FILES)] Compiling $< ($$PERCENT%)$(RESET)\r"; \
				$(CC) $(FLAGS) $(INC) -c $< -o $@

## Targets
all: 			$(NAME)

$(NAME):		Makefile $(OBJ_UTILS) $(OBJ_MANDA)
				@ $(CC) $(FLAGS) $(OBJ_UTILS) $(OBJ_MANDA) $(INC) -o $(NAME)
				@ echo "$(GREEN)[OK] $(NAME) built succesfully.$(RESET)"

bonus:			Makefile $(GNL) $(OBJ_UTILS) $(OBJ_BONUS)
				@ $(CC) $(FLAGS) $(OBJ_UTILS) $(OBJ_BONUS) $(GNL) $(INC) -o $(CHECKER)
				@ echo "$(GREEN)[OK] $(CHECKER) built succesfully.$(RESET)"

$(GNL):			Makefile
				@ $(MAKE) -sC $(GNL_DIR)

clean:
				@ $(MAKE) -sC $(GNL_DIR) clean
				@ $(RM) -rf $(OBJ_DIR)
				@ echo "$(CYAN)All $(NAME) object files have been cleaned.$(RESET)"

fclean:			clean
				@ $(MAKE) -sC $(GNL_DIR) fclean
				@ $(RM) -f $(NAME) $(CHECKER)
				@ echo "$(CYAN)All $(NAME) executable files have been cleaned.$(RESET)"

re:				fclean all

.PHONY:			all clean fclean re bonus
