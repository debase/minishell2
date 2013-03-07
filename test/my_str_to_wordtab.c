/*
** my_str_to_wordtab.c for str2wordtab in /home/debas_e//projet/minishell1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 17 17:06:29 2012 etienne debas
** Last update Wed Mar  6 03:10:58 2013 etienne debas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		mk_pipe(int, int, char *, char **);

int		count_word(char *str, char sepa)
{
  int		i;
  int		nb_word;

  nb_word = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] == sepa)
    i++;
  while (str[i])
    {
      if (str[i] == sepa)
	nb_word++;
      while (str[i] == sepa)
	i++;
      i++;
    }
  if (str[my_strlen(str) - 1] == sepa)
    return (nb_word);
  return (nb_word + 1);
}

char		*get_word(int begin, int end, char *str)
{
  char		*word;
  int		i;

  i = 0;
  if ((word = malloc((end - begin + 1) * sizeof(char))) == NULL)
    exit (0);
  while (begin < end)
    word[i++] = str[begin++];
  word[i] = 0;
  return (word);
}

void		supress_space(char *str, char **tab, char sepa)
{
  int		i;
  int		j;
  int		cur_word;

  cur_word = 0;
  i = 0;
  j = 0;
  while (str[i++] == sepa)
    j++;
  while (str[i])
    {
      if (str[i] == sepa)
	{
	  tab[cur_word++] = get_word(j, i, str);
	  j = i + 1;
	  i++;
	  while (str[i++] == sepa)
	    j++;
	}
      else
	i++;
    }
  tab[cur_word++] = get_word(j, i, str);
}

int		epur_and_check(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    if (str[i] != ' ' && str[i] != '\t')
      str[j++] = str[i++];
    else
      {
	str[j++] = ' ';
	while (str[i] == ' ' || str[i] == '\t')
	  i++;
      }
  str[j] = 0;
  if (str[0] == 0)
    return (0);
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (1);
}

void		epur_tab(char **tab)
{
  int		i;
  int		j;

  i = 0;
  while (tab[i])
    {
      if (epur_and_check(tab[i]) == 0)
	{
	  j = i;
	  free(tab[i]);
	  while (tab[j])
	    tab[j] = tab[++j];
	}
      else
	i++;
    }
}

char		**my_str_to_word_tab(char *str, char sepa)
{
  char		**tab_str;
  int		nb_word;

  if (my_strcmp2(str, "\n") == 1)
    str[0] = 0;
  if (str != NULL && my_strlen(str) != 0)
    {
      if (str[my_strlen(str) - 1] == '\n')
	str[my_strlen(str) - 1] = 0;
      nb_word = count_word(str, sepa);
      if ((tab_str = malloc((nb_word + 1) * sizeof(char *))) == NULL)
	exit (my_putstr("Allocation Problem\n"));
      supress_space(str, tab_str, sepa);
      tab_str[nb_word] = NULL;
      epur_tab(tab_str);
      return (tab_str);
    }
  return (NULL);
}

int		main(int ac, char **av, char **env)
{
  char		**toto;
  int		i;
  int		pfd[2];
  char		**argv;
  int		prev_read;
  int		status;

  i = 0;
  toto = my_str_to_word_tab(av[1], '|');

  pipe(pfd);
  argv = my_str_to_word_tab(toto[i++], ' ');
  mk_first_pipe(pfd[0], pfd[1], "/bin/ls", argv);
  close(pfd[1]);
  prev_read = pfd[0];

  pipe(pfd);
  argv = my_str_to_word_tab(toto[i++], ' ');
  mk_pipe(prev_read, pfd[1], "/bin/cat", argv);
  close(prev_read);
  close(pfd[1]);
  prev_read = pfd[0];

  pipe(pfd);
  argv = my_str_to_word_tab(toto[i++], ' ');
  mk_pipe(prev_read, pfd[1], "/bin/grep", argv);
  close(prev_read);
  close(pfd[1]);
  prev_read = pfd[0];

  argv = my_str_to_word_tab(toto[i++], ' ');
  mk_last_pipe(pfd[0], pfd[1], "/usr/bin/wc", argv);
  close(pfd[0]);
  close(pfd[1]);
}
