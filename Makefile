##
## Makefile for Makefile in /home/debas_e//projet/minishell1
## 
## Made by etienne debas
## Login   <debas_e@epitech.net>
## 
## Started on  Tue Dec 18 12:45:43 2012 etienne debas
## Last update Thu Mar  7 02:12:39 2013 etienne debas
##

CC	= cc -g

NAME	= mysh

RM	= rm -f

FILES	= mysh.c \
	  my_str_to_wordtab.c \
	  my_path_to_wordtab.c \
	  cpenv.c \
	  my_strdup.c \
	  my_putnbr.c \
	  setenv.c \
	  unsetenv.c \
	  env.c \
	  buildin.c \
	  check_cmd.c \
	  exec.c \
	  exit.c \
	  my_strcmp.c \
	  my_strncmp.c \
	  path_bin.c \
	  prompt.c \
	  my_putstr.c \
	  my_putchar.c \
	  my_strlen.c \
	  function_env.c \
	  found_in_env.c \
	  my_getpwd.c \
	  error_env.c \
	  init_prompt.c \
	  parse.c \
	  pipe.c \
	  get_next_line.c \
	  alias.c \
	  get_str_alias.c \
	  replace_alias.c \

OBJS	= $(FILES:.c=.o)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(FILES)

all: 	 $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: 
	 $(RM) $(OBJS)
	 $(RM) $(NAME)

re: fclean all

