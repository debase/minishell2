/*
** pipe.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Mar  6 00:34:02 2013 etienne debas
** Last update Thu Mar  7 20:33:29 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		exec_pipe_line(t_list *sct, char *cmd)
{
  t_pipe	sct_pipe;
  int		*pfd;
  int		prev_read;

  sct_pipe.i = 0;
  sct_pipe.pipe_tab = my_str_to_word_tab(cmd, '|');
  if ((pfd = malloc(2 * sizeof(int))) == NULL)
    my_perror(PBALLOC);
  if ((sct_pipe.nb_pipe = count_arg_pipe(sct_pipe.pipe_tab)) == 1)
    return (my_putstr("Invalid null command\n", 2));
  while (sct_pipe.i < sct_pipe.nb_pipe)
    choose_exec_pipe(&sct_pipe, pfd, sct, &prev_read);
  sct_pipe.i = 0;
  while (sct_pipe.i < sct_pipe.nb_pipe)
    {
      wait(NULL);
      sct_pipe.i += 1;
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

void		choose_exec_pipe(t_pipe *sct_pipe, int *pfd,
				 t_list *sct, int *prev_read)
{
  if (sct_pipe->i == 0)
    {
      pipe(pfd);
      mk_first_pipe(pfd[0], pfd[1], sct_pipe->pipe_tab[sct_pipe->i], sct);
      close(pfd[1]);
      *prev_read = pfd[0];
    }
  else if (sct_pipe->i == (sct_pipe->nb_pipe - 1))
    {
      mk_last_pipe(pfd[0], pfd[1], sct_pipe->pipe_tab[sct_pipe->i], sct);
      close(pfd[0]);
      close(pfd[1]);
    }
  else
    {
      pipe(pfd);
      mk_pipe(*prev_read, pfd[1], sct_pipe->pipe_tab[sct_pipe->i], sct);
      close(*prev_read);
      close(pfd[1]);
      *prev_read = pfd[0];
    }
  sct_pipe->i += 1;
}
