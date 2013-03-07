/*
** alias.c for mysh in /home/debas_e//minishell1-2017-debas_e
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Wed Mar  6 19:51:15 2013 etienne debas
** Last update Thu Mar  7 15:03:43 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

char		**get_alias()
{
  int		nbr_alias;
  char		**alias;

  if ((nbr_alias = get_nbr_alias()) == -1)
    return (NULL);
  if ((alias = malloc(((2 * nbr_alias) + 1 )* sizeof(char *))) == NULL)
    return (NULL);
  fill_alias(alias);
  return (alias);
}

void		fill_alias(char **alias)
{
  char		*line;
  int		fd_alias;
  int		i;

  i = 0;
  fd_alias = open("config.cfg", O_RDONLY);
  while (line = get_next_line(fd_alias))
    {
      if (my_strncmp(line, "alias ", 6))
	{
	  if (is_alias(line + 6) == 1)
	  {
	    alias[i] = get_str1_alias(line + 5);
	    alias[i + 1] = get_str2_alias(line + 5);
	    i += 2;
	  }
	}
      free(line);
    }
  alias[i] = NULL;
  close(fd_alias);
}

int		get_nbr_alias()
{
  char		*line;
  int		fd_alias;
  int		nb_line;

  nb_line = 0;
  if ((fd_alias = open("config.cfg", O_RDONLY)) == -1)
    {
      my_putstr("Can't open alias config\n", 2);
      return (-1);
    }
  while (line = get_next_line(fd_alias))
    {
      if (my_strncmp(line, "alias ", 6))
	nb_line++;
      free(line);
    }
  if (close(fd_alias) != 0)
    return (-1);
  return (nb_line);
}

int		is_alias(char *str)
{
  char		**tmp;
  int		i;

  i = 0;
  while (str[i] == ' ' && str[i])
    i++;
  if ((str[i] == '=') || (str[i] == '\0'))
    return (0);
  tmp = my_str_to_word_tab(str, '=');
  i = 0;
  while (tmp[i])
    i++;
  if (i < 2)
    return (0);
  else
    return (1);
}
