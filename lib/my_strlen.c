/*
** my_strlen.c for my_strlen.c in /afs/epitech.net/users/all/debas_e/rendu/piscine/Jour_04
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Oct  4 15:22:00 2012 etienne debas
** Last update Thu Mar  7 14:28:57 2013 etienne debas
*/

int		my_strlen(char *str)
{
  int		i;

  i= 0;
  while (str[i] != 0)
    i = i + 1;
  return (i);
}
