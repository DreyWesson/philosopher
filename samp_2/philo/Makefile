# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 23:46:27 by lfrasson          #+#    #+#              #
#    Updated: 2021/09/11 11:13:08 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := gcc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -g
CFLAGS += -fsanitize=address
DELAY := 1000

INCLUDEDIR := ./includes/

SRCDIR := ./srcs/
SRCS := main.c\
		parser.c\
		init.c\
		create_philos.c\
		routine.c\
		time.c\
		free_resources.c\
		create_threads.c\
		eating.c\
		death_control.c\
		utils.c

VPATH := $(SRCDIR)\
		 $(SRCDIR)parser

OBJDIR := ./objs/
OBJS := $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

$(OBJDIR)%.o:	%.c
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -D DELAY=$(DELAY) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

delay:
	@python3 delay_o_meter.py

.PHONY: all clean fclean re delay
