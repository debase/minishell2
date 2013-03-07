/*
** test.c for test in /home/debas_e//projet/minishell1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 17 16:15:58 2012 etienne debas
** Last update Thu Mar  7 00:59:29 2013 etienne debas
*/

#include "mysh.h"

int		main(int ac, char **av, char **env)
{
  t_list	*sct;
  int		i;

  if ((sct = malloc(sizeof(*sct))) == NULL)
    exit (my_putstr(PBALLOC));
  if ((sct->buff_command = malloc(READ)) == NULL)
    exit (my_putstr(PBALLOC));
  sct->old_pwd = my_getpwd();
  sct->env_0 = 0;
  sct->env_o = env;
  sct->env = cpenv(sct->env_o);
  sct->path_home = my_get_home(sct->env);
  sct->path = init_path(sct->path, sct->env);
  sct->alias = get_alias();
  init_data_prompt(env);
  signal(SIGINT, prompt_ctrl);
  prmt->pwd = my_getpwd();
  mysh(sct);
}

void		mysh(t_list *sct)
{
  char		**argv;
  int		ret;

  while (42)
    {
      prompt();
      if ((sct->buff_command = get_next_line(0)) == NULL)
	my_exit (sct);
      argv = my_str_to_word_tab(sct->buff_command, ';');
      if (sct != 0 && argv != 0 && argv[0] != 0)
	if (argv[0][0] != '\0')
	  {
	    search_and_exec(sct, argv);
	    prmt->nbr_cmd_exec++;
	  }
      my_free_word_tab(argv);
    }
}
