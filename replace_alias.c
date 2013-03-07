/*
** replace_alias.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar  7 01:28:14 2013 etienne debas
** Last update Thu Mar  7 03:04:00 2013 etienne debas
*/

# include "mysh.h"

char		**check_and_replace_alias(char **old_argv, char **alias)
{
  char		**new_argv;
  char		**alias_cmd;
  int		i;
  int		len_alias;
  int		len_old_argv;

  len_alias = 0;
  i = 0;
  len_old_argv = 0;
  if ((i = found_alias(old_argv[0], alias)) == -1)
    return (old_argv);
  alias_cmd = my_str_to_word_tab(alias[i], ' ');
  while (alias_cmd[len_alias])
    len_alias++;
  while (old_argv[len_old_argv])
    len_old_argv++;
  if ((new_argv = malloc((len_alias + len_old_argv) * sizeof(char *))) == NULL)
    return (old_argv);
  mk_new_cmd(new_argv, old_argv, alias_cmd);
  my_free_word_tab(old_argv);
  return (new_argv);
}

void		mk_new_cmd(char **new_argv, char **old_argv, char **alias)
{
  int		count_alias;
  int		count_old_argv;
  int		count_new_argv;

  count_new_argv = 0;
  count_alias = 0;
  count_old_argv = 1;
  while (alias[count_alias])
    new_argv[count_new_argv++] = my_strdup(alias[count_alias++]);
  while (old_argv[count_old_argv])
    new_argv[count_new_argv++] = my_strdup(old_argv[count_old_argv++]);
  new_argv[count_new_argv] = NULL;
}

int		found_alias(char *cmd, char **alias)
{
  int		i;

  i = 0;
  while (alias[i])
    {
      if (my_strcmp2(alias[i], cmd) == 1)
	return (i + 1);
      i += 2;
    }
  return (-1);
}
