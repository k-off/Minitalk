#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pacovali <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 11:11:47 by pacovali      #+#    #+#                  #
#    Updated: 2019/04/18 19:16:26 by pacovali      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = client

SRCS = main.c
OBJS = main.o

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIB = -L ../libft/ -lft

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRCS) -c
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

clean:
	@rm -f $(OBJS)
	@rm -f *~
	@rm -f \#*#

fclean: clean
	@rm -f $(NAME)

re: fclean all
