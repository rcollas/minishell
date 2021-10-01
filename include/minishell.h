/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/01 11:47:22 by vbachele         ###   ########.fr       */
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

typedef struct s_var{
	char	**env;
	t_list	*list;
	t_echo	*echo;
}		t_var;

typedef struct s_builtin{
	char	*cmd;
	int	(*func)(t_var);
}		t_builtin;

typedef struct s_echo{
	t_list	*list_echo;
	char	*echo;
	int		simple_quote;
	int		double_double;
	int		dash_n;
} t_echo;

#endif
