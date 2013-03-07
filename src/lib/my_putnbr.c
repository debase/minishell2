/*
** my_putnbr.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Feb  3 01:49:18 2013 etienne debas
** Last update Thu Mar  7 14:28:59 2013 etienne debas
*/

int	my_putnbr(int nb)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
    }
  my_putchar((nb%10) + 48);
}
