/*
** my_strcmp.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Thu Dec 27 15:43:02 2012 etienne debas
** Last update Thu Dec 27 15:50:47 2012 etienne debas
*/

#include "mysh.h"

int		my_strcmp2(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
