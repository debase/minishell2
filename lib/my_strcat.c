/*
** my_strcat.c for my_strcat in /home/debas_e//minishell1-2017-debas_e/lib
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Mar  7 13:47:46 2013 etienne debas
** Last update Thu Mar  7 14:28:58 2013 etienne debas
*/

# include <stdlib.h>

char		*my_strcat(char *dest, char *src)
{
  char		*ret;
  int		i;
  int		j;
  int		k;

  k = 0;
  i = 0;
  j = 0;
  if ((ret = malloc((my_strlen(dest) +
		     my_strlen(src) + 1) * sizeof(char))) == NULL)
      return (dest);
  while (dest[i])
    ret[j++] = dest[i++];
  while (src[k])
    ret[j++] = src[k++];
  ret[j] = 0;
  free(dest);
  return (ret);
}
