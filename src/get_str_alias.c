/*
** get_str_alias.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Mar  6 23:19:34 2013 etienne debas
** Last update Thu Mar  7 14:34:40 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

char		*get_str1_alias(char *str)
{
  int		i;
  char		*alias;
  int		j;

  j = 0;
  i = 0;
  if ((alias = malloc(my_strlen(str))) == NULL)
    return (NULL);
  while ((str[i] == ' ') && str[i])
    i++;
  while ((str[i] != '=') && str[i])
    alias[j++] = str[i++];
  alias[j] = 0;
  epur_and_check(alias);
  return (alias);
}

char		*get_str2_alias(char *str)
{
  int		i;
  char		*alias;
  int		j;

  j = 0;
  i = 0;
  if ((alias = malloc(my_strlen(str))) == NULL)
    return (NULL);
  while ((str[i] != '=') && str[i])
    i++;
  i++;
  while (str[i])
    alias[j++] = str[i++];
  alias[j] = 0;
  epur_and_check(alias);
  return (alias);
}
