/*
** prompt.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:37:57 2012 etienne debas
** Last update Sun Mar 10 11:51:01 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

void		prompt()
{
  write(1, "\033[1;33;40m", 10);
  my_putchar('[');
  write(1, g_prmt->usr_name, my_strlen(g_prmt->usr_name));
  write(1, "@", 1);
  write(1, g_prmt->pc_name, my_strlen(g_prmt->pc_name));
  my_putchar(' ');
  my_putnbr(g_prmt->nbr_cmd_exec);
  my_putchar(']');
  write(1, "\033[0m", 4);
  my_putstr(" ", 1);
  write(1, "\033[1;31;40m", 10);
  write(1, g_prmt->pwd, my_strlen(g_prmt->pwd));
  my_putstr("# ", 1);
  write(1, "\033[0m", 4);
}

void		prompt_ctrl()
{
  g_prmt->signal = 1;
  write(1, "\033[1;33;40m", 10);
  my_putstr("\n[", 1);
  write(1, g_prmt->usr_name, my_strlen(g_prmt->usr_name));
  write(1, "@", 1);
  write(1, g_prmt->pc_name, my_strlen(g_prmt->pc_name));
  my_putchar(' ');
  my_putnbr(g_prmt->nbr_cmd_exec);
  my_putchar(']');
  write(1, "\033[0m", 4);
  my_putstr(" ", 1);
  write(1, "\033[1;31;40m", 10);
  write(1, g_prmt->pwd, my_strlen(g_prmt->pwd));
  my_putstr("# ", 1);
  write(1, "\033[0m", 4);
}
