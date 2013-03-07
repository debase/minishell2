/*
** path_bin.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Thu Dec 27 15:40:26 2012 etienne debas
** Last update Thu Dec 27 15:40:50 2012 etienne debas
*/

#include "mysh.h"

char		*my_path_file(char *path, char *name)
{
  char		*path_return;
  int		i;
  int		j;

  j = 0;
  i = 0;
  path_return = malloc(my_strlen(path) + my_strlen(name) + 2);
  while (path[j])
    {
      path_return[i] = path[j];
      i += 1;
      j += 1;
    }
  path_return[i] = '/';
  i += 1;
  j = 0;
  while (name[j])
    {
      path_return[i] = name[j];
      i += 1;
      j += 1;
    }
  path_return[i] = '\0';
  return (path_return);
}
