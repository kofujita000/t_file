# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kofujita <kofujita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 20:29:24 by kofujita          #+#    #+#              #
#    Updated: 2024/08/24 18:27:03 by kofujita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := tests
CFLAGS      := -Wall -Wextra -Werror

SRCS		:=

OBJS_DIR	:= objs
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

AR			:= ar rcs
CC          := cc
RM          := rm -rf
CP          := cp -r
MKDIR       := mkdir -p
MAKE        := make

INSTALL_DIR := /usr/local

# Progress bar information
SRCS_COUNT := $(words $(SRCS))
PROGRESS := 0
BAR_LENGTH := 40

.PHONY :
	all clean fclean re install

$(NAME):
	@$(MKDIR) lib include
	@$(MAKE) -C .. install "INSTALL_DIR=./tests"
	@$(MAKE) -C ../../t_string install "INSTALL_DIR=../t_file/tests"
	@$(CC) -o 00_test_t_file_open 00_test_t_file_open.c ./lib/t_file.a ./lib/t_string.a
	@$(CC) -o 01_test_t_file_getc 01_test_t_file_getc.c ./lib/t_file.a ./lib/t_string.a
	@$(CC) -o 02_test_t_file_getline 02_test_t_file_getline.c ./lib/t_file.a ./lib/t_string.a
	@$(CC) -o 03_test_t_file_gets 03_test_t_file_gets.c ./lib/t_file.a ./lib/t_string.a

all : $(NAME)

clean :
	@$(RM) 00_test_t_file_open
	@$(RM) 01_test_t_file_getc
	@$(RM) 02_test_t_file_getline
	@$(RM) 03_test_t_file_gets
	@echo Deleted

fclean : clean
	@$(RM) include lib
	@echo Deleted

re : fclean all

install : all
	@$(CP) $(NAME) $(INSTALL_DIR)/lib
	@$(CP) t_string.h $(INSTALL_DIR)/include
