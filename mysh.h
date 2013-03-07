/*
** mysh.h for mysh.h in /home/debas_e//projet/minishell1
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Mon Dec 17 22:06:33 2012 etienne debas
** Last update Thu Mar  7 16:29:26 2013 etienne debas
*/

#ifndef MYSH_H_
# define MYSH_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# define PBALLOC "Couldn't alloc\n"

typedef struct l_list
{
  char	**argv;
  char	*buff_command;
  char	**path;
  char	**env;
  char	**env_o;
  char	*path_home;
  char	*last_dir;
  int	env_0;
  char	*old_pwd;
  char	*old_pwd2;
  char	**alias;
} t_list;

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

typedef struct data_prmt
{
  char		*usr_name;
  char		*pc_name;
  int		nbr_cmd_exec;
  char		*cur_dir;
  char		*pwd;
} data_prmt;

typedef struct s_pipe
{
  char		**pipe_tab;
  char		**argv;
  int		i;
  int		nb_pipe;
}		t_pipe;

data_prmt	*prmt;
char		**cpenv(char **);
void		mysh(t_list *);
char		**init_path(char **, char **);
char		**path_to_word_tab(char **, char *, int, int);
char		*check_cmd(char **, char *);
char		*my_path_file(char *, char *);
void		change_dir(char **, t_list *);
void		change_dir_2(char **, t_list *);
char		*my_get_home(char **);
char		*home_to_str(char *, int);
int		exec_prg(char **, char **);
int		my_exec(t_list *, char **, char *);
void		prompt();
void		prompt_ctrl();
int		special_case(t_list *, char **);
void		my_free_word_tab(char **);
void		my_free_path_tab(t_list *);
int		my_setenv(t_list *, char **);
int		found_in_env(char *, char **);
void		supress_value_env(t_list *, int);
void		replace_value(t_list *, int);
char		**add_elem_env(t_list *, char **, char *);
void		my_free_cpenv(t_list *);
char		*my_strdup_add_elem_env(char *);
char		**add_env_with_value(t_list *);
void		supress_value_env(t_list *, int);
int		my_unsetenv(t_list *, char **);
void		my_exit(t_list *);
char		*my_get_dir(char **);
char		*get_pwd(char *, int);
int		aff_env(t_list *);
int		aff_env_u(t_list *, int);
char		*my_getpwd();
int		init_sct(t_pwd *);
int		check_pwd(t_pwd *);
int		recursif(t_pwd *);
void		env_u_error();
void		env_invalid_option(char *);
void		env_no_such(char **, int);
int		analyse(char *);
void		init_data_prompt(char **);
char		*get_in_env(int, char **);
void		search_and_exec(t_list *, char **);
int		search_multi_exec(char **);
void		exec_multi(t_list *);
void		exec_simple_cmd(t_list *, char *);
void		my_perror(char *);
/*
** pipe
*/
int		check_pipe(char *);
int		count_arg_pipe(char **);
int		exec_pipe_line(t_list *, char *);
int		mk_pipe(int , int, char *, t_list *);
int		mk_first_pipe(int, int, char *, t_list *);
int		mk_last_pipe(int, int, char *, t_list *);
void		choose_exec_pipe(t_pipe *, int *, t_list *, int *);

/*
** get_next_line
*/
char		*get_next_line(int );
char		*my_realloc(char *, int);
char		*xmalloc(int);

/*
** alias
*/
char		*get_str1_alias(char *);
char		*get_str2_alias(char *);
char		**get_alias();
void		fill_alias(char **);
int		get_nbr_alias();
int		is_alias(char *);
char		**check_and_replace_alias(char **, char **);
void		mk_new_cmd(char **, char **, char **);
int		found_alias(char *, char **);

char		*my_strcat(char *, char *);

#endif
