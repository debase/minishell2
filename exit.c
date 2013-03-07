/*
** exit.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:38:19 2012 etienne debas
** Last update Tue Mar  5 13:39:18 2013 etienne debas
*/

#include "mysh.h"

void		my_exit(t_list *sct)
{
  int		i;

  i = 0;
  free(sct->buff_command);
  my_free_cpenv(sct);
  my_free_path_tab(sct);
  free (sct);
  exit (my_putstr("exit\n"));
}

void		my_free_word_tab(char **argv)
{
  int		i;

  i = 0;
  if (argv != 0 && argv[0] != 0)
    {
      while (argv[i] != 0)
	{
	  free(argv[i]);
	  i++;
	}
      free(argv);
    }
}

void		my_free_path_tab(t_list *sct)
{
  int		i;

  i = 0;
  if (sct->path != 0 && sct != 0)
    {
      while (sct->path[i] != 0)
	{
	  free(sct->path[i]);
	  i++;
	}
      free(sct->path);
    }
}

void		my_free_cpenv(t_list *sct)
{
  int		i;

  i = 0;
  if (sct->env != 0 && sct != 0)
    {
      while (sct->env[i] != 0)
	{
	  free(sct->env[i]);
	  i++;
	}
      free(sct->env);
    }
}
