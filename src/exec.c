/*
** exec.c for mysh in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:39:14 2012 etienne debas
** Last update Thu Mar  7 15:09:31 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		exec_prg(char **argv, char **env)
{
  int		id;
  int		status;

  if (access(argv[0], X_OK | F_OK) == 0)
    {
      if ((id = fork()) == 0)
	{
	  if  (execve(argv[0], argv, env) == -1)
	    {
	      my_putstr2(argv[0], ": Can't execute.\n", 2);
	      exit (0);
	    }
	  exit (0);
	}
      else if (id < 0)
	my_putstr("Fork failed\n", 2);
      else
	wait(&status);
    }
  else
    my_putstr2(argv[0], ": Command not found.\n", 2);
}

int		my_exec(t_list *sct, char **argv, char *path_cmd)
{
  int		id;
  int		status;

  if ((id = fork()) == 0)
    {
      execve(path_cmd, argv, sct->env);
      exit (0);
    }
  else if (id < 0)
    my_putstr("Fork failed\n", 2);
  else
    wait(&status);
}
