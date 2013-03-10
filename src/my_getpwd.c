/*
** my_pwd_norme.c for mysh in /home/debas_e//Downloads
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Sun Dec 30 18:23:05 2012 etienne debas
** Last update Thu Mar  7 17:03:30 2013 etienne debas
*/

# include "../mysh.h"
# include "../lib.h"

char		*my_getpwd()
{
  t_pwd		*sct;

  if ((sct = malloc(sizeof(*sct))) == NULL)
    {
      my_putstr("Allocation Problem\n", 2);
      return (NULL);
    }
  sct->fnd = 0;
  if (init_sct(sct) == -1)
    return (NULL);
  if (check_pwd(sct) == 1);
  else if (recursif(sct) == -1)
      return (NULL);
  sct->length = my_strlen(sct->res_dir);
  if (sct->length != 1)
    sct->res_dir = my_strcat(sct->res_dir, "/");
  if (sct->fnd_dir)
    {
      sct->length2 = my_strlen(sct->fnd_dir);
      sct->res_dir = my_strcat(sct->res_dir, sct->fnd_dir);
      free(sct->fnd_dir);
    }
  chdir(sct->res_dir);
  return (sct->res_dir);
}

int		init_sct(t_pwd *sct)
{
  if (stat(".", &sct->cur) != 0)
    {
      my_putstr("Can't stat current dir\n", 2);
      return (-1);
    }
  chdir("..");
  if (stat(".", &sct->par) != 0)
    {
      my_putstr("Can't stat parrent directory\n", 2);
      return (-1);
    }
  if ((sct->dir = opendir(".")) == NULL)
    {
      my_putstr("Can't open current directory\n", 2);
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
	  my_putstr("Couldn't alloc\n", 2);
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
	    my_putstr("Can not stat directory\n", 2);
	    return (-1);
	  }
	if ((sct->tmpbuffer.st_dev == sct->cur.st_dev)
	    && (sct->tmpbuffer.st_ino == sct->cur.st_ino))
	  sct->fnd = 1;
      }
  sct->fnd_dir = my_strdup(sct->entry->d_name);
  closedir(sct->dir);
  sct->res_dir = my_getpwd();
}
