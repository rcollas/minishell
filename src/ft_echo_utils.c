/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <rcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:21:33 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/08 17:15:17 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unmatched_quotes(t_var *var)
{
	int	i;
	int	d_quote_count;
	int	s_quote_count;
	int	d_quote;
	int	s_quote;

	i = -1;
	d_quote_count = 0;
	s_quote_count = 0;
	d_quote = 0;
	s_quote = 0;
	while (var->cmd[++i])
	{
		if (var->cmd[i] == '"' && s_quote == FALSE)
		{
			if (d_quote == FALSE)
				d_quote = TRUE;
			else
				d_quote = FALSE;
			d_quote_count++;
		}
		if (var->cmd[i] == '\'' && d_quote == FALSE)
		{
			if (s_quote == FALSE)
				s_quote = TRUE;
			else
				s_quote = FALSE;
			s_quote_count++;
		}
	}
	return (d_quote_count % 2 + s_quote_count % 2);
}
