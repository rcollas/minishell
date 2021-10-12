/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/12 11:35:53 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_echo{
	struct s_list	*echo_list;
	char			*echo;
	int				simple_quote;
	int				double_double;
	int				dash_n;
	int				dollar;
}	t_echo;

typedef struct s_var{
	char			**env;
	char			*cmd;
	char			*variable;
	int				ac;
	struct s_list	*list;
	struct s_envar	*envar;
	t_echo			*echo;
}		t_var;

typedef struct s_builtin{
	char	*cmd;
	int		(*func)(t_var *);
}		t_builtin;

int		is_between_double_quotes(t_var *var, int i);
int		is_between_simple_quotes(t_var *var, int i);
int		check_unmatched_quotes(t_var *var);
int		ft_echo(t_var *var);
int		ft_env(t_var *var);
int		ft_strcmp(const char *s1, const char *s2);
void	get_env_var(t_var *var, struct s_envar **envar);
int		ft_excve(t_var *var, char **argv);
char	*get_path(t_var *var, char **path_fromenvp, char **argv);
void	execve_error(t_var *var, char *path_final);
int		ft_pwd(t_var *var);
int		ft_exit(t_var *var);
int		ft_export(t_var *var);
int		cmd_export_alone(t_var *var, char *name, int equal);
int		export_reassigned_check(t_var *var, char *name, char *content);
int		export_insert(t_var *var, char *name, char *content);
int		ft_unset(t_var *var);

#endif
