/*
** parse.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Mar  6 00:28:11 2013 etienne debas
** Last update Thu Mar  7 14:34:39 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

void		search_and_exec(t_list *sct, char **argv)
{
  int		count;

  count = 0;
  while (argv[count])
    {
      if (check_pipe(argv[count]) == 1)
	exec_pipe_line(sct, argv[count]);
      else
	exec_simple_cmd(sct, argv[count]);
      count++;
    }
}

void		exec_simple_cmd(t_list *sct, char *cmd)
{
  char		**argv;
  char		*path_bin;

  argv = my_str_to_word_tab(cmd, ' ');
  if (sct->alias != NULL)
    argv = check_and_replace_alias(argv, sct->alias);
  if (special_case(sct, argv));
  else if ((path_bin = check_cmd(sct->path, argv[0])) == NULL)
    exec_prg(argv, sct->env);
  else
    my_exec(sct, argv, path_bin);
  my_free_word_tab(argv);
}

int		check_pipe(char *cmd)
{
  int		i;

  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

int		count_arg_pipe(char **tab_pipe)
{
  int		i;

  i = 0;
  while (tab_pipe[i])
    i++;
  return (i);
}
