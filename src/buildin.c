/*
** buildin.c for mysh.c in /home/debas_e//projet/minishell1/minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Dec 27 15:41:14 2012 etienne debas
** Last update Thu Mar  7 21:28:48 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

int		special_case(t_list *sct, char **argv)
{
  char		*tab[6];
  int		(*builtin_tab[6])(t_list *sct, char **argv);
  int		i;

  i = 0;
  tab[0] = "cd";
  tab[1] = "chdir";
  tab[2] = "exit";
  tab[3] = "setenv";
  tab[4] = "unsetenv";
  tab[5] = "env";
  tab[6] = NULL;
  builtin_tab[0] = &(change_dir);
  builtin_tab[1] = &(change_dir);
  builtin_tab[2] = &(my_exit);
  builtin_tab[3] = &(my_setenv);
  builtin_tab[4] = &(my_unsetenv);
  builtin_tab[5] = &(env);

  while (tab[i] && (my_strcmp(argv[0], tab[i]) == 0))
      i++;
  if (i >= 5)
    return (0);
  builtin_tab[i](sct, argv);
  return (1);
}

int		change_dir(t_list *sct, char **argv)
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
