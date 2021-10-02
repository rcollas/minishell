/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:33:52 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/02 15:21:03 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
