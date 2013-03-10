/*
** init_pipe.c for mysh in /home/debas_e//Desktop/projet/minishell2
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar  8 23:20:57 2013 etienne debas
** Last update Sun Mar 10 12:24:29 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		choose_exec_pipe(t_pipe *sct_pipe, int *pfd,
				 t_list *sct, int *prev_read)
{
  if (sct_pipe->i == 0)
    {
      if (prepare_first_pipe(sct_pipe, pfd, sct, prev_read) == -1)
	return (-1);
    }
  else if (sct_pipe->i == (sct_pipe->nb_pipe - 1))
    {
      if (prepare_last_pipe(sct_pipe, pfd, sct, prev_read) == -1)
	return (-1);
    }
  else
    {
      if (prepare_middle_pipe(sct_pipe, pfd, sct, prev_read) == -1)
	return (-1);
    }
}

int		prepare_first_pipe(t_pipe *sct_pipe, int *pfd,
				   t_list *sct, int *prev_read)
{
  if (pipe(pfd) != 0)
    return (-1);
  if (mk_first_pipe(pfd[0], pfd[1],
		    sct_pipe->pipe_tab[sct_pipe->i], sct) == -1)
    return (-1);
  close(pfd[1]);
  *prev_read = pfd[0];
  return (0);
}

int		prepare_middle_pipe(t_pipe *sct_pipe, int *pfd,
				    t_list *sct, int *prev_read)
{
  if (pipe(pfd) != 0)
    return (-1);
  if (mk_pipe(*prev_read, pfd[1],
	      sct_pipe->pipe_tab[sct_pipe->i], sct) == -1)
    return (-1);
  close(*prev_read);
  close(pfd[1]);
  *prev_read = pfd[0];
  return (0);
}

int		prepare_last_pipe(t_pipe *sct_pipe, int *pfd,
				  t_list *sct, int *prev_read)
{
  if (mk_last_pipe(pfd[0], pfd[1],
		   sct_pipe->pipe_tab[sct_pipe->i], sct) == -1)
    return (-1);
  close(pfd[0]);
  close(pfd[1]);
  return (0);
}
