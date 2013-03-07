/*
** my_strncmp.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Mar  6 20:26:00 2013 etienne debas
** Last update Wed Mar  6 23:18:01 2013 etienne debas
*/

#include "mysh.h"

int		my_strncmp(char *str1, char *str2, int n)
{
  int		i;

  i = 0;
  while ((str1[i] || str2[i]) && (i < n))
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}
