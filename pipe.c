/*
** pipe.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Mar  6 00:34:02 2013 etienne debas
** Last update Wed Mar  6 10:22:41 2013 etienne debas
*/

#include "mysh.h"

int		exec_pipe_line(t_list *sct, char *cmd)
{
  char		**pipe_tab;
  int		i;
  int		pfd[2];
  char		**argv;
  int		prev_read;
  int		nb_pipe;

  i = 0;
  pipe_tab = my_str_to_word_tab(cmd, '|');
  if ((nb_pipe = count_arg_pipe(pipe_tab)) == 1)
    return (my_putstr("Invalid null command\n"));
  while (i < nb_pipe)
    {
      if (i == 0)
  	{
	  pipe(pfd);
	  mk_first_pipe(pfd[0], pfd[1], pipe_tab[i], sct);
	  close(pfd[1]);
	  prev_read = pfd[0];
      	}
      else if (i == (nb_pipe - 1))
      	{
	  mk_last_pipe(pfd[0], pfd[1], pipe_tab[i], sct);
	  close(pfd[0]);
	  close(pfd[1]);
      	}
      else
      	{
	  pipe(pfd);
	  mk_pipe(prev_read, pfd[1], pipe_tab[i], sct);
	  close(prev_read);
	  close(pfd[1]);
	  prev_read = pfd[0];
    	}
      i++;
    }
  i = 0;
  while (i < nb_pipe)
    {
      wait(NULL);
      i++;
    }
}

int		mk_pipe(int stdin, int stdout, char *cmd, t_list *sct)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      dup2(stdin, 0);
      dup2(stdout, 1);
      close(stdin);
      close(stdout);
      exec_simple_cmd(sct, cmd);
      exit(0);
    }
}

int		mk_first_pipe(int stdin, int stdout, char *cmd, t_list *sct)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      dup2(stdout, 1);
      close(stdout);
      close(stdin);
      exec_simple_cmd(sct, cmd);
      exit(0);
    }
}

int		mk_last_pipe(int stdin, int stdout, char *cmd, t_list *sct)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      dup2(stdin, 0);
      close(stdin);
      close(stdout);
      exec_simple_cmd(sct, cmd);
      exit(0);
    }
}
