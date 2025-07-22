# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 16:49:57 by nyousfi           #+#    #+#              #
#    Updated: 2025/07/22 12:48:07 by nyousfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

ARGS =
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
CFLAGS_NO_COLORS = -Wall -Werror -Wextra -MMD -MP \
                   -DRESET='""' \
                   -DRED='""' \
                   -DGREEN='""' \
                   -DYELLOW='""' \
                   -DORANGE='""' \
                   -DCYAN='""' \
                   -DBLUE='""' \
                   -DPURPLE='""'
SRCS = src/main.c \
	   src/args.c \
	   src/error.c \
	   src/mutexes.c \
	   src/mutexes_error.c \
	   src/threads_errors.c \
	   src/free.c \
	   src/philos.c \
	   src/time.c \
	   src/routines.c \
	   src/philo_routine.c \
	   src/routine_utils.c \
	   src/monitor_routine.c

MAKEDIR = make
OBJDIR = make/objs
DEPDIR = make/deps

OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:src/%.c=$(DEPDIR)/%.d)

HEADER = include/philo.h \

COMPILED = 0
MESSAGE_COLOR_GREEN = \033[1;32m
MESSAGE_COLOR_BLUE = \033[1;34m
MESSAGE_COLOR_YELLOW = \033[1;33m
MESSAGE_COLOR_RED = \033[1;31m
MESSAGE_RESET = \033[1;0m

all: $(NAME)
	@if [ $(COMPILED) -eq 1 ]; then \
		echo "$(MESSAGE_COLOR_BLUE)compilation done 🎉$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_BLUE)everything is already up to date 😉$(MESSAGE_RESET)"; \
	fi
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@$(eval COMPILED := 1)

$(OBJDIR)/%.o: src/%.c $(HEADER)
	@echo "$(MESSAGE_COLOR_YELLOW)Compiling $@... 🛠️$(MESSAGE_RESET)"
	@mkdir -p $(OBJDIR) $(DEPDIR)
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@
	@mv -f $(OBJDIR)/$*.d $(DEPDIR)/$*.d
	@$(eval COMPILED := 1)
	@echo "$(MESSAGE_COLOR_GREEN)Compilation of $@ done! ✅$(MESSAGE_RESET)"

-include $(DEPS)

wcolors: CFLAGS = $(CFLAGS_NO_COLORS)
wcolors: clean $(OBJS)
	@echo "$(MESSAGE_COLOR_YELLOW)Linking without colors... 🎨$(MESSAGE_RESET)"
	@$(CC) $(OBJS) -o $(NAME)
	@$(eval COMPILED := 1)
	@echo "$(MESSAGE_COLOR_GREEN)Compilation without colors done! ✅$(MESSAGE_RESET)"	
valgrind:
	@valgrind --leak-check=full \
			  --show-leak-kinds=all \
			  --track-origins=yes \
			  --track-fds=yes \
			  --error-exitcode=42 \
			  ./$(NAME) $(ARGS)

helgrind:
	@valgrind --tool=helgrind \
			  --track-lockorders=yes \
			  --error-exitcode=42 \
			  ./$(NAME) $(ARGS)

clean:
	@if [ -d $(MAKEDIR) ] || [ -f $(NAME) ]; then \
		rm -rf $(MAKEDIR); \
		echo "$(MESSAGE_COLOR_RED)all files are deleted 🗑️$(MESSAGE_RESET)"; \
	else \
		echo "$(MESSAGE_COLOR_GREEN)files already deleted 😉$(MESSAGE_RESET)"; \
	fi


fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all files clean fclean re