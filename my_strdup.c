/*
** my_strdup.c for my_strdup in /home/debas_e//programmeC
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Mon Nov 26 03:31:54 2012 etienne debas
** Last update Thu Dec 27 15:51:05 2012 etienne debas
*/

#include "mysh.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*res;

  i = 0;
  res = malloc(my_strlen(str) + 1);
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char		*my_strdup_add_elem_env(char *str)
{
  int		i;
  char		*res;

  i = 0;
  res = malloc(my_strlen(str) + 2);
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '=';
  res[i + 1] = '\0';
  return (res);
}
