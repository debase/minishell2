/*
** test.c for test in /home/debas_e//projet/minishell1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 17 16:15:58 2012 etienne debas
** Last update Sun Mar 10 11:49:09 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		main(int ac, char **av, char **env)
{
  t_list	*sct;
  int		i;

  if ((sct = malloc(sizeof(*sct))) == NULL)
    my_perror(PBALLOC);
  sct->old_pwd = my_getpwd();
  sct->env_i = 0;
  sct->env_o = env;
  sct->env = cpenv(sct->env_o);
  sct->path_home = my_get_home(sct->env);
  sct->path = init_path(sct->path, sct->env);
  if ((sct->alias = get_alias()) == NULL)
    my_putstr("Can't load alias config\n", 2);
  init_data_prompt(env);
  signal(SIGINT, prompt_ctrl);
  g_prmt->pwd = my_getpwd();
  g_prmt->signal = 0;
  mysh(sct);
}

void		mysh(t_list *sct)
{
  char		**argv;
  int		ret;

  while (42)
    {
      if (g_prmt->signal == 0)
	prompt();
      else
	g_prmt->signal = 0;
      if ((sct->buff_command = get_next_line(0)) == NULL)
	my_exit(sct, argv);
      argv = my_str_to_word_tab(sct->buff_command, ';');
      if (sct != 0 && argv != 0 && argv[0] != 0)
	if (argv[0][0] != '\0')
	  {
	    search_and_exec(sct, argv);
	    g_prmt->nbr_cmd_exec++;
	  }
      my_free_word_tab(argv);
    }
}
