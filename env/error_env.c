/*
** error_env.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Dec 30 21:38:27 2012 etienne debas
** Last update Thu Mar  7 14:55:13 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

void		env_no_such(char **argv, int i)
{
  if (i >= 4)
    {
      my_putstr3("env:", argv[3], ": No such file or directory\n", 2);
    }
  else
    {
      my_putstr3("env:", argv[1], ": No such file or directory\n", 2);
    }
}

void		env_u_error()
{
  my_putstr("env: option requires an argument -- 'u'\n", 2);
  my_putstr("Try `env --help' for more information.\n", 2);
}

void		env_invalid_option(char *option)
{
  if (my_strlen(option) >= 2)
    {
      my_putstr("env: invalid option -- '", 2);
      my_putstr(&option[1], 2);
      my_putstr("'\n", 2);
    }
}
