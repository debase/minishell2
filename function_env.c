/*
** function_env.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 18:38:14 2012 etienne debas
** Last update Thu Jan 31 03:46:30 2013 etienne debas
*/

#include "mysh.h"

void		supress_value_env(t_list *sct, int elem_env)
{
  int		i;

  i = 0;
  while (sct->env[elem_env][i] != '=')
    i++;
  sct->env[elem_env][i + 1] = '\0';
}

void		replace_value(t_list *sct, int elem_env)
{
  char		*new_elem_env;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((new_elem_env = malloc(my_strlen(sct->env[elem_env])
			     + my_strlen(sct->argv[2]) + 1)) == NULL)
    exit (my_putstr(PBALLOC));
  while (sct->env[elem_env][i] != '=')
    new_elem_env[j++] = sct->env[elem_env][i++];
  new_elem_env[j++] = '=';
  i = 0;
  while (sct->argv[2][i])
    new_elem_env[j++] = sct->argv[2][i++];
  new_elem_env[j] = 0;
  free(sct->env[elem_env]);
  sct->env[elem_env] = new_elem_env;
}

char		**add_env_value_less(t_list *sct)
{
  int		i;
  char		**cpenv;

  i = 0;
  while (sct->env[i])
    i++;
  if ((cpenv = malloc((i + 2) * sizeof (char *))) == NULL)
    return (NULL);
  i = 0;
  while (sct->env[i] != NULL)
    {
      cpenv[i] = my_strdup(sct->env[i]);
      i++;
    }
  cpenv[i] = my_strdup_add_elem_env(sct->argv[1]);
  cpenv[i + 1] = NULL;
  my_free_cpenv(sct);
  sct->env = cpenv;
}

char		**add_env_with_value(t_list *sct)
{
  int		i;
  char		**cpenv;

  i = 0;
  while (sct->env[i])
    i++;
  if ((cpenv = malloc((i + 2) * sizeof (char *))) == NULL)
    return (NULL);
  i = 0;
  while (sct->env[i] != NULL)
    {
      cpenv[i] = my_strdup(sct->env[i]);
      i++;
    }
  cpenv[i] = my_strdup_add_elem_env(sct->argv[1]);
  cpenv[i + 1] = NULL;
  my_free_cpenv(sct);
  sct->env = cpenv;
  replace_value(sct, i);
}

void		supress_elem_env(t_list *sct, int elem_env)
{
  int		i;
  int		j;
  char		**cpenv;

  i = 0;
  j = 0;
  while (sct->env[i] != NULL)
    {
      if (i == elem_env)
	i++;
      sct->env[j] = sct->env[i];
      if (sct->env[i] != NULL)
	i++;
      j++;
    }
  sct->env[j] = NULL;
}
