##
## Makefile for Makefile in /home/debas_e//projet/minishell1
## 
## Made by etienne debas
## Login   <debas_e@epitech.net>
## 
## Started on  Tue Dec 18 12:45:43 2012 etienne debas
## Last update Thu Mar  7 15:31:09 2013 etienne debas
##

CC	= cc -g

NAME	= mysh

RM	= rm -f

FLAGS	=

SRCS	= ./lib/my_str_to_wordtab.c \
	  ./lib/my_str_to_wordtab2.c \
	  ./lib/my_strdup.c \
	  ./lib/my_strcat.c \
	  ./lib/my_putnbr.c \
	  ./lib/my_strcmp.c \
	  ./lib/my_strncmp.c \
	  ./lib/my_putstr.c \
	  ./lib/my_putchar.c \
	  ./lib/my_strlen.c \
	  ./lib/get_next_line.c \
	  ./env/cpenv.c \
	  ./env/setenv.c \
	  ./env/unsetenv.c \
	  ./env/env.c \
	  ./env/function_env.c \
	  ./env/found_in_env.c \
	  ./env/error_env.c \
	  ./src/my_getpwd.c \
	  ./src/my_path_to_wordtab.c \
	  ./src/mysh.c \
	  ./src/buildin.c \
	  ./src/check_cmd.c \
	  ./src/exec.c \
	  ./src/exit.c \
	  ./src/path_bin.c \
	  ./src/prompt.c \
	  ./src/init_prompt.c \
	  ./src/parse.c \
	  ./src/pipe.c \
	  ./src/alias.c \
	  ./src/get_str_alias.c \
	  ./src/replace_alias.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	 $(CC) $(FLAGS) -o $(NAME) $(SRCS)

all: 	 $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	 $(RM) $(OBJS)
	 $(RM) $(NAME)

re: fclean all

