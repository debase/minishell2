/*
** setenv.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 24 15:20:41 2012 etienne debas
** Last update Thu Mar  7 22:07:15 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		my_setenv(t_list *sct, char **argv)
{
  int		i;
  int		elem_env;

  i = 0;
  while (argv[i])
    i++;
  if (i == 1)
    return (aff_env(sct));
  else if (i == 2)
    if (analyse(argv[1]) == -1)
      return (my_putstr("setenv: Syntax Error.\n", 2));
    else if ((elem_env = found_in_env(argv[1], sct->env)) == -1)
      add_env_value_less(sct, argv);
    else
      supress_value_env(sct, elem_env);
  else if (i == 3)
    if ((elem_env = found_in_env(argv[1], sct->env)) == -1)
      add_env_with_value(sct, argv);
    else
      replace_value(sct, elem_env, argv);
  else
    return (my_putstr("setenv: Too many arguments.\n", 2));
  my_free_path_tab(sct);
  sct->path = init_path(sct->path, sct->env);
}

int		analyse(char *av)
{
  int		i;

  i = 0;
  while (av[i])
    {
      if (av[i] == '=')
	return (-1);
      i++;
    }
  return (0);
}
