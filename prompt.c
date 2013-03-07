/*
** prompt.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:37:57 2012 etienne debas
** Last update Thu Mar  7 01:18:16 2013 etienne debas
*/

#include "mysh.h"

void		prompt()
{
  write(1, "\033[1;33;40m", 10);
  my_putchar('[');
  write(1, prmt->usr_name, my_strlen(prmt->usr_name));
  write(1, "@", 1);
  write(1, prmt->pc_name, my_strlen(prmt->pc_name));
  my_putchar(' ');
  my_putnbr(prmt->nbr_cmd_exec);
  my_putchar(']');
  write(1, "\033[0m", 4);
  my_putstr(" ");
  write(1, "\033[1;31;40m", 10);
  write(1, prmt->pwd, my_strlen(prmt->pwd));
  my_putstr("# ");
  write(1, "\033[0m", 4);
}

void		prompt_ctrl()
{
  write(1, "\033[1;33;40m", 10);
  my_putstr("\n[");
  write(1, prmt->usr_name, my_strlen(prmt->usr_name));
  write(1, "@", 1);
  write(1, prmt->pc_name, my_strlen(prmt->pc_name));
  my_putchar(' ');
  my_putnbr(prmt->nbr_cmd_exec);
  my_putchar(']');
  write(1, "\033[0m", 4);
  my_putstr(" ");
  write(1, "\033[1;31;40m", 10);
  write(1, prmt->pwd, my_strlen(prmt->pwd));
  my_putstr("# ");
  write(1, "\033[0m", 4);
  signal(SIGINT, prompt_ctrl);
}
