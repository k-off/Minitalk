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

NAME = minitalk

EXEC1 = server
EXEC2 = client
LFT = lft

all:  $(NAME)

$(NAME):
	@echo "compiling:"
	@make $(LFT)
	@make $(EXEC1)
	@make $(EXEC2)
	@echo "done"

$(LFT):
	@echo "-   lft"
	@make -C libft

$(EXEC1):
	@echo "-   server"
	@make -C src_server
	@mv src_server/$(EXEC1) $(EXEC1)

$(EXEC2):
	@echo "-   client"
	@make -C src_client
	@mv src_client/$(EXEC2) $(EXEC2)

clean:
	@echo "cleaning ..."
	@make -C libft clean
	@make -C src_server clean
	@make -C src_client clean
	@echo "done"

fclean: clean
	@make -C libft fclean
	@make -C src_server fclean
	@make -C src_client fclean
	@rm -f $(EXEC1)
	@rm -f $(EXEC2)

re: fclean all
