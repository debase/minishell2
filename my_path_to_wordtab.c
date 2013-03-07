/*
** path_to_word_tab.c for path_to_word_tab in /home/debas_e//projet/minishell1
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Tue Dec 18 12:44:46 2012 etienne debas
** Last update Fri Dec 28 17:17:50 2012 etienne debas
*/

#include "mysh.h"

char		**init_path(char **path, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'P' &&
	  env[i][1] == 'A' &&
	  env[i][2] == 'T' &&
	  env[i][3] == 'H')
	return (path_to_word_tab(path, env[i], 4, 0));
      i++;
    }
  return (NULL);
}

char		**path_to_word_tab(char **path, char *env_path, int i, int j)
{
  int		k;

  k = 0;
  if ((path = malloc(50 * sizeof(char *))) == NULL)
    exit (my_putstr(PBALLOC));
  if ((path[j] = malloc(50 * sizeof(char ))) == NULL)
    exit (my_putstr(PBALLOC));
  while (env_path[++i])
    {
      if (env_path[i] == ':')
	{
	  path[j][k] = 0;
	  i++;
	  j++;
	  if ((path[j] = malloc(50 * sizeof(char ))) == NULL)
	    exit (my_putstr(PBALLOC));
	  k = 0;
	}
      path[j][k] = env_path[i];
      k++;
    }
  path[j][k] = 0;
  path[j + 1] = NULL;
  return (path);
}

char		*my_get_home(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'H' &&
	  env[i][1] == 'O' &&
	  env[i][2] == 'M' &&
	  env[i][3] == 'E')
	return (home_to_str(env[i], 5));
      i++;
    }
  return (NULL);
}

char		*home_to_str(char *home, int i)
{
  char		*path_home;
  int		j;

  j = 0;
  if ((path_home = malloc(100 * sizeof(char))) == NULL)
    exit (my_putstr(PBALLOC));
  while (home[i])
    {
      path_home[j] = home[i];
      j++;
      i++;
    }
  path_home[j] = 0;
  return (path_home);
}
