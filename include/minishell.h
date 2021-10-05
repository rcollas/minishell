/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/05 14:33:56 by vbachele         ###   ########.fr       */
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
	struct	s_list	*echo_list;
	char	*echo;
	int		simple_quote;
	int		double_double;
	int		dash_n;
	int		dollar;
} t_echo;

typedef struct s_var{
	char	**env;
	char	*cmd;
	char	*variable;
	int	ac;
	struct s_list	*list;
	struct s_envar *envar;
	t_echo	*echo;
}		t_var;

typedef struct s_builtin{
	char	*cmd;
	int	(*func)(t_var *);
}		t_builtin;

typedef struct s_cd{
	struct	s_list	*cd_list;
	char			*string_cd;
} t_cd;

typedef struct s_pwd{
	struct	s_list	*pwd_list;
	char			*string_pwd;
} t_pwd;

int		is_between_double_quotes(t_var *var, int i);
int		is_between_simple_quotes(t_var *var, int i);
int		check_unmatched_quotes(t_var *var);
int		ft_echo(t_var *var);
int		ft_env(t_var *var);
int		ft_strcmp(const char *s1, const char *s2);
void	get_env_var(t_var *var, struct s_envar **envar);
int		ft_pwd(char **argv);

#endif
