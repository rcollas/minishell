/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:21:33 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/08 00:58:20 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_between_simple_quotes(char *str, int i)
{
	int	j;
	int	check;
	int	check_d_quote;
	int	check_d_quote2;

	j = i;
	check = 0;
	check_d_quote = 0;
	check_d_quote2 = 0;
	while (i >= 0)
	{
		if (str[i--] == '\'')
		{
			while (i >= 0 && check_d_quote < 2)
			{
				if (str[i] == '"')
					check_d_quote++;
				i--;
			}
			check++;
			break ;
		}
	}
	while (str[j])
	{
		if (str[j] == '\'')
		{
			while (str[j] && check_d_quote2 < 2)
			{
				if (str[j] == '"')
					check_d_quote2++;
				j++;
			}
			check++;
			break ;
		}
		j++;
	}
	if (check == 2 && (check_d_quote + check_d_quote2 == 0 || check_d_quote + check_d_quote2 == 4))
		return (1);
	return (0);
}

int	is_between_double_quotes(char *str, int i)
{
	int	j;
	int	check;
	int	check_s_quote;
	int	check_s_quote2;

	j = i;
	check = 0;
	check_s_quote = 0;
	check_s_quote2 = 0;
	while (i >= 0)
	{
		if (str[i--] == '"')
		{
			while (i >= 0 && check_s_quote < 2)
			{
				if (str[i] == '\'')
					check_s_quote++;
				i--;
			}
			check++;
			break ;
		}
	}
	while (str[j])
	{
		if (str[j] == '"')
		{
			while (str[j] && check_s_quote2 < 2)
			{
				if (str[j] == '\'')
					check_s_quote2++;
				j++;
			}
			check++;
			break ;
		}
		j++;
	}
	if (check == 2 && (check_s_quote + check_s_quote2 == 0 || check_s_quote + check_s_quote2 == 4))
		return (1);
	return (0);
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
		if (var->cmd[i] == '"' && is_between_simple_quotes(var->cmd, i) == FALSE)
			d_quote_count++;
		if (var->cmd[i] == '\'' && is_between_double_quotes(var->cmd, i) == FALSE)
			s_quote_count++;
	}
	return (d_quote_count % 2 + s_quote_count % 2);
}
