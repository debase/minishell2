/*
** check_cmd.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:42:08 2012 etienne debas
** Last update Wed Mar  6 11:44:18 2013 etienne debas
*/

#include "mysh.h"

char		*check_cmd(char **path, char *cmd)
{
  int		i;
  char		*path_bin;

  i = 0;
  if (path != NULL && path[i] != NULL)
    while (path[i] != NULL)
      {
	path_bin = my_path_file(path[i], cmd);
	if (access(path_bin, X_OK | F_OK) == 0)
	  return (path_bin);
	else
	  free(path_bin);
	i++;
      }
  return (NULL);
}
