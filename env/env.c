/*
** env.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 24 15:58:02 2012 etienne debas
** Last update Thu Mar  7 21:19:12 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		aff_env(t_list *sct)
{
  int		i;

  i = 0;
  while (sct->env[i])
    {
      my_putstr(sct->env[i], 1);
      if (sct->env_0 == 0)
	my_putstr("\n", 1);
      i++;
    }
  return (0);
}

int		env(t_list *sct, char **argv)
{
  int		i;

  i = 0;
  while (argv[i])
    i++;
  if (i == 1)
    aff_env(sct);
  else if (i == 2 && my_strcmp("-0", argv[1]) == 1)
    {
      sct->env_0 = 1;
      aff_env(sct);
      sct->env_0 = 0;
    }
  else if (i == 2 && my_strcmp("-u", argv[1]) == 1)
    env_u_error();
  else if (i == 3 && my_strcmp("-u", argv[1]) == 1)
    {
      i = found_in_env(argv[2], sct->env);
      aff_env_u(sct, i);
    }
  else if ((i >= 4 && my_strcmp("-u", argv[1]) == 1)
	   || argv[1][0] != '-')
    env_no_such(argv, i);
  else
    env_invalid_option(argv[1]);
}

int		aff_env_u(t_list *sct, int j)
{
  int		i;

  i = 0;
  while (sct->env[i])
    {
      if (i != j)
	{
	  my_putstr(sct->env[i], 1);
	  my_putstr("\n", 1);
	}
      i++;
    }
  return (0);
}
