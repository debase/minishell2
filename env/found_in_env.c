/*
** function_env2.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 18:49:42 2012 etienne debas
** Last update Thu Mar  7 14:37:18 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		found_in_env(char *av, char **env)
{
  int		i;
  int		j;

  i = j = 0;
  while (env[i])
    if (env[i][j] != av[j])
      {
	if (env[i][j] == '=' && av[j] == 0)
	  return (i);
	j = 0;
	i++;
      }
    else
      j++;
  return (-1);
}
