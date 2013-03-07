/*
** error_env.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Sun Dec 30 21:38:27 2012 etienne debas
** Last update Sun Dec 30 22:40:17 2012 etienne debas
*/

#include "mysh.h"

void		env_no_such(char **argv, int i)
{
  if (i >= 4)
    {
      my_putstr("env: ");
      my_putstr(argv[3]);
      my_putstr(": No such file or directory\n");
    }
  else
    {
      my_putstr("env: ");
      my_putstr(argv[1]);
      my_putstr(": No such file or directory\n");
    }
}

void		env_u_error()
{
  my_putstr("env: option requires an argument -- 'u'\n");
  my_putstr("Try `env --help' for more information.\n");
}

void		env_invalid_option(char *option)
{
  if (my_strlen(option) >= 2)
    {
      my_putstr("env: invalid option -- '");
      my_putchar(option[1]);
      my_putstr("'\n");
    }
}
