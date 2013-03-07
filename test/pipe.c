/*
** pipe.c for pipe in /home/debas_eprojet/minishell2
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Fri Feb  1 18:09:51 2013 etienne debas
** Last update Wed Mar  6 01:31:22 2013 etienne debas
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int		mk_pipe(int stdin, int stdout, char *path_cmd, char **argv)
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
	  if (execv(path_cmd, argv) < 0)
	    printf("error exec\n");
    }
  else
    wait(&status);
}

int		mk_first_pipe(int stdin, int stdout, char *path_cmd, char **argv)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      dup2(stdout, 1);
      close(stdout);
      close(stdin);
      if (execv(path_cmd, argv) < 0)
	printf("error exec\n");
    }
  else
    wait(&status);
}

int		mk_last_pipe(int stdin, int stdout, char *path_cmd, char **argv)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      dup2(stdin, 0);
      close(stdin);
      close(stdout);
      if (execv(path_cmd, argv) < 0)
	printf("error exec\n");
    }
  else
    wait(&status);
}

