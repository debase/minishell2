/*
** my_putstr.c for my_pustr.c in /afs/epitech.net/users/all/debas_e/rendu/pis**cine/Jour_04
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Thu Oct  4 14:23:53 2012 etienne debas
** Last update Fri Dec 28 17:31:17 2012 etienne debas
*/

int		my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      str = str + 1;
    }
}
