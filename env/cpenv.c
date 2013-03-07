/*
** cpenv.c for cpenv in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 24 13:48:22 2012 etienne debas
** Last update Thu Mar  7 14:37:19 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

char		**cpenv(char **env)
{
  int		i;
  char		**cpenv;

  i = 0;
  while (env[i])
    i++;
  if ((cpenv = malloc((i + 2) * sizeof (char *))) == NULL)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      cpenv[i] = my_strdup(env[i]);
      i++;
    }
  cpenv[i] = NULL;
  return (cpenv);
}
