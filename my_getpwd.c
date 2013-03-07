/*
** my_pwd_norme.c for mysh in /home/debas_e//Downloads
** 
** Made by etienne debas
** Login   <debas_e@epitech.net>
** 
** Started on  Sun Dec 30 18:23:05 2012 etienne debas
** Last update Sun Dec 30 20:11:18 2012 etienne debas
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

typedef struct s_pwd
{
  struct stat	cur;
  struct stat	par;
  struct stat	tmpbuffer;
  DIR		*dir;
  struct dirent *entry;
  int		fnd;
  int		length;
  int		length2;
  char		*res_dir;
  char		*fnd_dir;

} t_pwd;

char		*my_getpwd()
{
  t_pwd		*sct;

  if ((sct = malloc(sizeof(*sct))) == NULL)
    {
      my_putstr("Allocation Problem\n");
      return (NULL);
    }
  sct->fnd = 0;
  if (init_sct(sct) == -1)
    return (NULL);
  if (check_pwd(sct) == 1);
  else if (recursif(sct) == -1)
      return (NULL);
  sct->length = strlen(sct->res_dir);
  if (sct->length != 1)
    strcat(sct->res_dir, "/");
  if (sct->fnd_dir)
    {
      sct->length2 = strlen(sct->fnd_dir);
      strncat(sct->res_dir, sct->fnd_dir, sct->length2);
      free(sct->fnd_dir);
    }
  chdir(sct->res_dir);
  return (sct->res_dir);
}

int		init_sct(t_pwd *sct)
{
  if (stat(".", &sct->cur) != 0)
    {
      my_putstr("Can't stat current dir\n");
      return (-1);
    }
  chdir("..");
  if (stat(".", &sct->par) != 0)
    {
      my_putstr("Can't stat parrent directory\n");
      return (-1);
    }
  if ((sct->dir = opendir(".")) == NULL)
    {
      my_putstr("Can't open current directory\n");
      return (-1);
    }
}

int		check_pwd(t_pwd *sct)
{
  if ((sct->cur.st_dev == sct->par.st_dev) &&
      (sct->cur.st_ino == sct->par.st_ino))
    {
      if ((sct->res_dir = malloc(sizeof(char) * FILENAME_MAX)) == NULL)
	{
	  my_putstr("Couldn't alloc\n");
	  return (-1);
	}
      sct->res_dir[0] = 0;
      sct->fnd_dir = NULL;
      return (1);
    }
}

int		recursif(t_pwd *sct)
{
  while (sct->fnd != 1)
    if (sct->entry = readdir(sct->dir))
      {
	if (lstat(sct->entry->d_name, &sct->tmpbuffer) != 0)
	  {
	    my_putstr("Can not stat directory\n");
	    return (-1);
	  }
	if ((sct->tmpbuffer.st_dev == sct->cur.st_dev)
	    && (sct->tmpbuffer.st_ino == sct->cur.st_ino))
	  sct->fnd = 1;
      }
  sct->fnd_dir = strdup(sct->entry->d_name);
  closedir(sct->dir);
  sct->res_dir = my_getpwd();
}
