# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 19:20:04 by varuiz            #+#    #+#              #
#    Updated: 2019/10/07 19:54:04 by varuiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker

NAME_P = push_swap

# Path

SRC_PATH_C = ./srcs_checker/

OBJ_PATH_C = ./objs/

INC_PATH_C = -I./includes/

SRC_PATH_P = ./srcs/

OBJ_PATH_P = ./objs/

INC_PATH_P = -I./includes/

# Name

SRC_NAME_C = 	main.c					\
				check_action.c			\
				ft_swap_checker.c		\
				ft_push_checker.c		\
				ft_rotate_checker.c		\
				ft_rotate_rev_checker.c	\
				tab_free.c				\
				com.c					\
				dlist_create_node.c		\
				dlist_new.c				\
				dlist_push_back.c		\
				dlist_push_front.c		\
				dlist_remove_head.c		\
				dlist_remove_tail.c		\
				ft_end.c				\
				ft_prepare.c			\
				ft_operation_ops.c		\
				ft_check.c				\
				ft_operation_a.c		\
				ft_operation_b.c		\
				ft_operation_ab.c		\
				ft_algo.c				\
				ft_algo3.c				\
				is_sorted.c				\
				op.c					\
				op2.c					\
				store_op.c				\

OBJ_NAME_C = $(SRC_NAME_C:.c=.o)

SRC_NAME_P = 	main_p.c				\
				ft_algo2.c				\
				split.c					\
				next_target.c			\
				get_value.c				\
				tab_free.c				\
				com.c					\
				dlist_create_node.c		\
				dlist_new.c				\
				dlist_push_back.c		\
				dlist_push_front.c		\
				dlist_remove_head.c		\
				dlist_remove_tail.c		\
				ft_end.c				\
				ft_prepare.c			\
				ft_operation_ops.c		\
				ft_check.c				\
				ft_operation_a.c		\
				ft_operation_b.c		\
				ft_operation_ab.c		\
				ft_algo.c				\
				ft_algo3.c				\
				is_sorted.c				\
				op.c					\
				op2.c					\
				store_op.c				\

OBJ_NAME_P = $(SRC_NAME_P:.c=.o)

# Files

SRC_C = $(addprefix $(SRC_PATH_C)/,$(SRC_NAME_C))

OBJ_C = $(addprefix $(OBJ_PATH_C), $(OBJ_NAME_C))

SRC_P = $(addprefix $(SRC_PATH_P)/,$(SRC_NAME_P))

OBJ_P = $(addprefix $(OBJ_PATH_P), $(OBJ_NAME_P))

# Flags

LDFLAGS = -L./libft/

LFT = -lft

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

# Rules

all: $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJ_C)
	@make -C./libft/
	@echo "\033[34mCreation of $(NAME_C) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ_C) -o $@
	@echo "\033[32m$(NAME_C) created\n\033[0m"

$(NAME_P): $(OBJ_P)
	@make -C./libft/
	@echo "\033[34mCreation of $(NAME_P) ...\033[0m"
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ_P) -o $@
	@echo "\033[32m$(NAME_P) created\n\033[0m"

$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	@mkdir $(OBJ_PATH_C) 2> /dev/null || true
	@$(CC) $(INC_PATH_C) -o $@ -c $<

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	@mkdir $(OBJ_PATH_P) 2> /dev/null || true
	@$(CC) $(INC_PATH_P) -o $@ -c $<

clean: cleanlib
	@echo "\033[33mRemoval of .o files of $(NAME_C) and $(NAME_P) ...\033[0m"
	@rm -f $(OBJ_C)
	@rm -f $(OBJ_P)
	@rmdir $(OBJ_PATH_C) 2> /dev/null || true
	@rmdir $(OBJ_PATH_P) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

cleanlib:
	@make clean -C ./libft/

fclean: clean fcleanlib
	@echo "\033[33mRemoval of $(NAME_C) and $(NAME_P) ...\033[0m"
	@rm -f $(NAME_C)
	@rm -f $(NAME_P)
	@echo "\033[31mBinary $(NAME_C) and $(NAME_P) deleted\033[0m"

fcleanlib:
	@make fclean -C ./libft/

rm: fclean
	@rmdir "checker.dSYM" 2> /dev/null || true
	@rmdir "push_swap.dSYM" 2> /dev/null || true

re: fclean all
	@make re -C ./libft/

git:
	@git add .
	@git commit -m "$(NAME_P)"
	@git push

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re
