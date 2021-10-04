/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/04 12:14:02 by vbachele         ###   ########.fr       */
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
	char	*echo;
	int		simple_quote;
	int		double_double;
	int		dash_n;
	int		dollar;
} t_echo;

typedef struct s_var{
	char	**env;
	char	*cmd;
	int	ac;
	struct s_list	*list;
	struct s_envar *envar;
	t_echo	*echo;
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

int	ft_echo(t_var *var);
int	ft_echo_without_quotes(t_var *var);
int	ft_echo_dollar(t_var *var);
int	ft_echo_simple_quote(t_var *var);
int	ft_strcmp(const char *s1, const char *s2);

#endif
