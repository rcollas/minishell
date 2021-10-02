/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/02 14:35:01 by rcollas          ###   ########.fr       */
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
	t_echo	*echo;
}		t_var;

typedef struct s_builtin{
	char	*cmd;
	int	(*func)(t_var *);
}		t_builtin;

#endif
