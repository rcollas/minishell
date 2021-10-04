/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/04 11:54:31 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

typedef struct s_var{
	char	**env;
	t_list	*list;
	t_echo	*echo;
	t_cd	*cd;
	t_pwd	*pwd;
}		t_var;

typedef struct s_builtin{
	char	*cmd;
	int		(*func)(t_var);
}		t_builtin;

typedef struct s_echo{
	t_list	*list_echo;
	char	*echo;
	int		simple_quote;
	int		double_quote;
	int		dash_n;
	int		dollar;
}	t_echo;

typedef struct s_cd{
	char	*string_cd;
}	t_cd;

typedef struct s_pwd{
	char	*string_pwd;
}	t_pwd;

int	ft_echo(t_var *var);
int	ft_echo_without_quotes(t_var *var);
int	ft_echo_dollar(t_var *var);
int	ft_echo_simple_quote(t_var *var);
int	ft_strcmp(const char *s1, const char *s2);
int	Eerrors_chdir_handling(t_var *var, int dir)

#endif
