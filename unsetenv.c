/*
** unsetenv.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 24 21:24:01 2012 etienne debas
** Last update Tue Mar  5 13:25:12 2013 etienne debas
*/

#include "mysh.h"

int		my_unsetenv(t_list *sct, char**argv)
{
  int		i;
  int		elem_env;

  i = 0;
  while (argv[i])
    i++;
  if (i == 1)
    return (my_putstr("unsetenv: Too few arguments.\n"));
  i = 1;
  if (argv != 0 && sct != 0)
    while (argv[i] != NULL)
      {
	if ((elem_env = found_in_env(argv[i], sct->env)) == -1)
	  i++;
	else
	  {
	    supress_elem_env(sct, elem_env);
	    i++;
	  }
      }
  my_free_path_tab(sct);
  sct->path = init_path(sct->path, sct->env);
}
