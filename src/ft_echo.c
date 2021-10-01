/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:33:52 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/01 16:45:12 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_var *var)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = var->envar;
	while (tmp[i])
	{
		if (var->echo->simple_quote == 0
			&& var->echo->double_quote == 0)
			ft_echo_without_quotes(var);
		else if (var->echo->simple_quote == 1)
			ft_echo_simple_quote(var);
		else if (var->echo->double_quote == 1)
			ft_echo_double_quote(var);
		i++;
	}
	return (0);
}

int	ft_echo_without_quotes(t_var *var)
{	
	var->echo->echo = ft_strtrim(var->echo->echo, 32);
	if (var->echo->dollar == 0 && var->echo->dash_n == 1)
		ft_putendl_fd(var->echo->echo, 1);
	else if (var->echo->dash_n == 1 && var->echo->dollar == 0)
		ft_putstr_fd(var->echo->echo, 1);
	else if (var->echo->dollar == 1)
		ft_echo_dollar(var);
	return (0);
}

int	ft_echo_simple_quote(t_var *var)
{
	if (var->echo->dollar == 1)
		write(1, "$", 1);
	ft_putstr_fd(var->echo->echo, 1);
	if (var->echo->dash_n == 0)
		write(1, "\n", 1);
	return (0);
}

int	ft_echo_double_quote(t_var *var)
{
	if (var->echo->dollar == 0)
		ft_putendl_fd(var->echo->echo, 1);
	else if (var->echo->dash_n == 1 && var->echo->dollar == 0)
		ft_putstr_fd(var->echo->echo, 1);
	else if (var->echo->dollar == 1)
		ft_echo_dollar(var);
}

int	ft_echo_dollar(t_var *var)
{
	ft_putstr_fd(var->echo->echo, 1);
	if (var->echo->dash_n == 0)
		write(1, "\n", 1);
	return (0);
}
