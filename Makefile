#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 19:38:04 by evilsbol          #+#    #+#              #
#    Updated: 2014/02/07 17:20:14 by evilsbol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# PROJECT VARIABLES
NAME = ft_minishell
LIBA = minishell.a
TEST = test
RUN_ARGS = 

LPATH = -L./libs/libft -lft\
		-L./libs/liblst -llst\
		-L./libs/libprt -lprt\
		-L./libs/libgnl -lgnl\
		-L./ -llem

HPATH = -Iincludes\
		-I./libs/libft/includes\
		-I./libs/liblst/includes\
		-I./libs/libprt/includes\
		-I./libs/libgnl/includes

SRCS =  main.c 

# STANDARD VARIABLES
CC = gcc -Wall -Wextra -Werror -g #-pedantic
AR = ar -cvq
RM = rm -rf
SRCDIR = srcs
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
NOW := $(shell date +"%c" | tr ' :' '_')

# COLORS
RESET=		\033[0m
DARK=		\033[1;32m
RED=		\033[31m
GREEN=		\033[32m
YELLOW=		\033[33m
BLUE=		\033[34m
MAGENTA=	\033[35m
CYAN=		\033[36m
WHITE=		\033[37m
BOLDBLACK=	\033[1m\033[30m
BOLDRED=	\033[1m\033[31m
BOLDWHITE=	\033[1m\033[37m

# MAKEHELP
LOADING = ./makehelp/loading

ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

# START RULES
.PHONY: depend clean fclean re build run save

all: $(NAME)

$(NAME): libdep $(LIBA)
	@echo "$(YELLOW)building $(NAME)$(RED)"
	@$(CC) -o $(NAME) $(LPATH) $(HPATH)
	@echo "$(RESET)$(GREEN)ready to rumble!$(RESET)"

$(LIBA): $(OBJS)
	@echo "$(YELLOW)linking project lib...$(DARK)"
	@$(AR) $@ $^
	@ranlib $@
	@echo "$(RESET)$(YELLOW)$(LIBA) built$(RESET)\n"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(HPATH) -o $@ -c $^

libdep:
	@make -C libs 

libdepclean:
	@make -C libs fclean

clean:
	@echo "$(YELLOW)removing $(OBJDIR)...$(RESET)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(YELLOW)removing $(NAME) and $(LIBA)...$(RESET)"
	@$(RM) $(NAME) $(LIBA)

re: fclean
	@make all

# Personnal rules
start:
	@mkdir libs
	@cp -rf ~/Dropbox/Projects/42libs/libft ./libs/
	@cp -rf ~/Dropbox/Projects/42libs/libprt ./libs/
	@mkdir ./srcs
	@mkdir ./includes
	@git init

save:
	@git add --all
	@git commit -m 'saving $(NOW)'
	@echo "$(YELLOW)all files added and commited$(RESET)"

run:
	@make re
	@echo "$(BLUE)TEST BEGIN\n $(RESET)"
	@./$(NAME) $(RUN_ARGS)
	@echo "$(BLUE) \nTEST END $(RESET)"

test: libdep
	@$(CC) -o $(TEST) tests.c $(LPATH) $(HPATH)

# DO NOT DELETE THIS LINE -- make depends on it
