/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:33:52 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/02 17:18:19 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	charcmp(char c1, char c2)
{
	if (c1 != c2)
		return (0);
	return (1);
}

int	is_alnum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*get_valid_envar(t_var *var, int i)
{
	t_envar	*tmp;
	int	j;
	int	k;

	tmp = var->envar;
	while (tmp)
	{
		j = 0;
		k = i;
		while (tmp->name[j] && var->cmd[k])
		{
			if (charcmp((tmp->name)[j], var->cmd[k]) == FAIL)
				break ;
			j++;
			k++;
			if ((is_alnum(var->cmd[k]) == 0) || var->cmd[k] == 0)
				return (tmp->content);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	expand_envar(t_var *var, int i)
{
	if (get_valid_envar(var, i) == FAIL)
	{
		while (is_alnum(var->cmd[i]) && var->cmd[i])
			i++;
		return (i);
	}
	write (1, get_valid_envar(var, i), ft_strlen(get_valid_envar(var, i)));
	while (is_alnum(var->cmd[i]) && var->cmd[i])
		i++;
	return (i);
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
	{
		if (var->cmd[i] == '$')
		{
			i = expand_envar(var, ++i);
			continue ;
		}
		write (1, &var->cmd[i++], 1);
	}
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
		if (var->cmd[i] == '$')
		{
			i = expand_envar(var, ++i);
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
