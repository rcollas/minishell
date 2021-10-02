/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:23:03 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/02 15:18:56 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char **env, int i)
{
	int		j;
	char	*name;

	j = 0;
	while (env[i][j] != '=')
		j++;
	name = (char *)malloc(sizeof(char) * (j + 1));
	name[j] = 0;
	while (--j >= 0)
		name[j] = env[i][j];
	return (name);
}

char	*get_var_content(char **env, int i)
{
	int		var_len;
	int		j;
	int		k;
	char	*content;

	j = 0;
	k = 0;
	var_len = ft_strlen(env[i]);
	while (env[i][j - 1] != '=')
		j++;
	content = (char *)malloc(sizeof(char) * (var_len - j + 1));
	while (env[i][j])
		content[k++] = env[i][j++];
	content[k] = '\0';
	return (content);
}

void	get_env_var(t_var *var, t_envar **envar)
{
	int		i;
	t_envar	*tmp;

	i = -1;
	while (var->env[++i])
	{
		tmp = ft_envar_new(get_var_name(var->env, i),
				get_var_content(var->env, i));
		ft_envaradd_back(envar, tmp);
	}
}

int	is_between_double_quotes(t_var *var, int i)
{
	int	j;
	int	check;

	j = i;
	check = 0;
	while (i >= 0)
	{
		if (var->cmd[i--] == '"')
		{
			check++;
			break ;
		}
	}
	while (var->cmd[j++])
	{
		if (var->cmd[j] == '"')
		{
			check++;
			break ;
		}
	}
	return (check == 2);
}

int	is_between_simple_quotes(t_var *var, int i)
{
	int	j;
	int	check;

	j = i;
	check = 0;
	while (i >= 0)
	{
		if (var->cmd[i--] == '\'')
		{
			check++;
			break ;
		}
	}
	while (var->cmd[j++])
	{
		if (var->cmd[j] == '\'')
		{
			check++;
			break ;
		}
	}
	return (check == 2);
}

int	check_unmatched_quotes(t_var *var)
{
	int	i;
	int	d_quote_count;
	int	s_quote_count;

	i = -1;
	d_quote_count = 0;
	s_quote_count = 0;
	while (var->cmd[++i])
	{
		if (var->cmd[i] == '"' && is_between_simple_quotes(var, i) == FALSE)
			d_quote_count++;
		if (var->cmd[i] == '\'' && is_between_double_quotes(var, i) == FALSE)
			s_quote_count++;
	}
	return (d_quote_count % 2 + s_quote_count % 2);
}

int	print_simple_quotes(t_var *var, int i)
{
	while (var->cmd[i] != '\'')
		write (1, &var->cmd[i++], 1);
	return (++i);
}

int	print_double_quotes(t_var *var, int i)
{
	while (var->cmd[i] != '"')
		write (1, &var->cmd[i++], 1);
	return (++i);
}

int	print_echo(t_var *var)
{
	int	i;

	i = 0;
	if (check_unmatched_quotes(var) >= TRUE)
		return (write(2, "Unmatched quote\n", 16));
	while (var->cmd[i])
	{
		if (var->cmd[i] == '\'')
		{
			i = print_simple_quotes(var, ++i);
			continue ;
		}
		if (var->cmd[i] == '"')
		{
			i = print_double_quotes(var, ++i);
			continue ;
		}
		write (1, &var->cmd[i++], 1);
	}
	write (1, "\n", 1);
	return (1);
}

int	ft_echo(t_var *var)
{
	var->cmd = &(var->cmd[5]);
	print_echo(var);
	return (0);
}

int	ft_cd(t_var *var)
{
	return (0);
}

int	ft_pwd(t_var *var)
{
	return (0);
}

int	ft_export(t_var *var)
{
	return (0);
}

int	ft_unset(t_var *var)
{
	return (0);
}

int	ft_env(t_var *var)
{
	return (0);
}

int	ft_exit(t_var *var)
{
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		if (s2[i + 1] == 0 && (s1[i + 1] == ' ' || s1[i + 1] == 0))
			return (1);
		i++;
	}
	return (0);
}

void	init_builtin(t_builtin *builtin)
{
	builtin[0].cmd = "echo";
	builtin[0].func = ft_echo;
	builtin[1].cmd = "cd";
	builtin[1].func = ft_cd;
	builtin[2].cmd = "pwd";
	builtin[2].func = ft_pwd;
	builtin[3].cmd = "export";
	builtin[3].func = ft_export;
	builtin[4].cmd = "unset";
	builtin[4].func = ft_unset;
	builtin[5].cmd = "env";
	builtin[5].func = ft_env;
	builtin[6].cmd = "exit";
	builtin[6].func = ft_exit;
	builtin[7].cmd = NULL;
	builtin[7].func = NULL;
}

int	is_builtin(char *line, t_builtin *builtin)
{
	int	i;

	i = 0;
	while (builtin[i].cmd)
	{
		if (ft_strcmp(line, builtin[i].cmd) == 1)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	main(int ac, char **av, char **env)
{
	int			ret;
	int			i;
	t_builtin	*builtin;
	t_var		var[1];
	t_envar		*envar;

	builtin = malloc(sizeof(t_builtin) * 8);
	init_builtin(builtin);
	i = -1;
	ret = 0;
	var->env = env;
	var->ac = ac;
	(void)av;
	envar = NULL;
	get_env_var(var, &envar);
	while (1)
	{
		var->cmd = readline("minishell $> ");
		ret = is_builtin(var->cmd, builtin);
		if (ret >= 0)
			builtin[ret].func(var);
	}
	return (0);
}
