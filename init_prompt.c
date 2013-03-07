/*
** init_prompt.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Feb  3 02:03:08 2013 etienne debas
** Last update Sun Feb  3 02:03:35 2013 etienne debas
*/

#include "mysh.h"

void		init_data_prompt(char **env)
{
  int		i;

  if ((prmt = malloc(sizeof (*prmt))) == NULL)
    exit (my_putstr(PBALLOC));
  if ((i = found_in_env("USERNAME", env)) == -1)
    prmt->usr_name = "toto";
  else
    prmt->usr_name = get_in_env(i, env);
  if ((i = found_in_env("HOSTNAME", env)) == -1)
    prmt->pc_name = "titi";
  else
    prmt->pc_name = get_in_env(i, env);
  prmt->nbr_cmd_exec = 0;
}

char		*get_in_env(int i, char **env)
{
  int		j;
  int		k;
  char		*data;

  j = 0;
  k = 0;
  if ((data = malloc(500)) == NULL)
    exit (my_putstr(PBALLOC));
  while (env[i][j] != '=')
    j++;
  j++;
  while (env[i][j] != '\0')
    data[k++] = env[i][j++];
  data[k] = 0;
  return (data);
}
