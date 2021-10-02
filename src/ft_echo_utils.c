/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:21:33 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/02 15:22:08 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
