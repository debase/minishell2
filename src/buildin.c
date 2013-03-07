/*
** buildin.c for mysh.c in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:41:14 2012 etienne debas
** Last update Thu Mar  7 15:29:38 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		special_case(t_list *sct, char **argv)
{
  if (my_strcmp(argv[0], "cd") == 1 ||
      my_strcmp(argv[0], "chdir") == 1)
    {
      change_dir(argv, sct);
      return (1);
    }
  else if (my_strcmp(argv[0], "exit") == 1)
    my_exit(sct);
  else if (my_strcmp(argv[0], "setenv") == 1)
    {
      my_setenv(sct, argv);
      return (1);
    }
  else if (my_strcmp(argv[0], "unsetenv") == 1)
    {
      my_unsetenv(sct, argv);
      return (1);
    }
  else if (my_strcmp(argv[0], "env") == 1)
    {
      env(sct, argv);
      return (1);
    }
  return (0);
}

void		change_dir(char **argv, t_list *sct)
{
  int		i;

  i = 0;
  while (argv[i] != NULL)
    i++;
  if (sct->path_home == NULL && i == 1)
    my_putstr("Command not found\n", 2);
  else if (i == 1)
    chdir(sct->path_home);
  else if (i == 2)
    change_dir_2(argv, sct);
  else
    my_putstr2(argv[0], ": Too many arguments.\n", 2);
  free(prmt->pwd);
  prmt->pwd = my_getpwd();
}

void		change_dir_2(char **argv, t_list *sct)
{
  if (my_strcmp("-", argv[1]) == 0)
    sct->old_pwd = my_getpwd();
  if (my_strcmp("-", argv[1]))
    {
      sct->old_pwd2 = my_getpwd();
      if (chdir(sct->old_pwd) == -1)
	my_putstr2(sct->old_pwd, ": No such file or directory.\n", 2);
      sct->old_pwd = sct->old_pwd2;
    }
  else if (chdir(argv[1]) == -1)
    my_putstr2(argv[1], ": No such file or directory.\n", 2);
}
