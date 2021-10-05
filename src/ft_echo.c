/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:33:52 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/05 13:53:11 by rcollas          ###   ########.fr       */
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
	ft_lstadd_back(&var->list, ft_lstnew(get_valid_envar(var, i)));
	while (is_alnum(var->cmd[i]) && var->cmd[i])
		i++;
	return (i);
}

int	print_simple_quotes(t_var *var, int i)
{
	int	j;
	
	char	*str;
	j = i;
	while (var->cmd[j] != '\'')
		j++;
	str = (char *)malloc(sizeof(char) * j);
	j = 0;
	while (var->cmd[i] != '\'')
		str[j++] = var->cmd[i++];
	str[j] = '\0';
	ft_lstadd_back(&var->list, ft_lstnew(str));
	return (++i);
}

int	print_double_quotes(t_var *var, int i)
{
	int	j;
	int	k;
	char	*str;

	j = i;
	k = 0;
	while (var->cmd[j] != '"' && var->cmd[j])
	{
		while (var->cmd[j] == '$')
		{
			i = expand_envar(var, ++j);
			while (is_alnum(var->cmd[j++]) == TRUE)
				k++;
			if (var->cmd[j - 1] == '$')
				j--;
		}
		j++;
	}
	str = (char *)malloc(sizeof(char) * (j - k));
	j = 0;
	while (var->cmd[i] != '"')
	{
		if (var->cmd[i] == '$')
			i += k;
		str[j++] = var->cmd[i++];
	}
	str[j] = '\0';
	ft_lstadd_back(&var->list, ft_lstnew(str));
	return (++i);
}

int	print_basic(t_var *var, int i)
{
	int	k;
	int	j;
	int	len;
	char	*str;

	j = 0;
	k = i;
	while (var->cmd[i] != '\'' && var->cmd[i] != '"' && var->cmd[i] != '$' && var->cmd[i] && var->cmd[i] != ' ')
		i++;
	len = i - k;
	str = (char *)malloc(sizeof(char) * len);
	while (j < len)
		str[j++] = var->cmd[k++];
	str[j] = '\0';
	ft_lstadd_back(&var->list, ft_lstnew(str));
	return (i);
}

int	is_dash_n(t_var *var)
{
	int	i;

	i = 0;
	if (!var->list)
		return (0);
	if (var->list->content[i] == '-')
	{
		i++;
		while (var->list->content[i] == 'n')
		{
			if (var->list->content[i + 1] == '\0' || var->list->content[i + 1] == ' ')
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	print_echo(t_var *var)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	if (check_unmatched_quotes(var) >= TRUE)
		return (write(2, "Unmatched quote\n", 16));
	while (var->cmd[i])
	{
		if (var->cmd[i] == ' ')
		{
			while (var->cmd[i] == ' ')
				i++;
		}
		else if (var->cmd[i] == '\'')
		{
			i = print_simple_quotes(var, ++i);
		}
		else if (var->cmd[i] == '"')
		{
			i = print_double_quotes(var, ++i);
		}
		else if (var->cmd[i] == '$')
		{
			i = expand_envar(var, ++i);
		}
		else
			i = print_basic(var, i);
	}
	return (1);
}

int	ft_echo(t_var *var)
{
	int	print_n;
	int	i;

	var->cmd = &(var->cmd[5]);
	print_echo(var);
	print_n = is_dash_n(var);
	i = 0;
	while (is_dash_n(var) == TRUE)
		var->list = var->list->next;
	while (var->list)
	{
		printf("list %d = %s\n", i, var->list->content);
		if (var->list->next && var->list->content[0] != 0 && var->list->next->content[0] != 0)
		{
			printf(" ");
		}
		var->list = var->list->next;
		i++;
	}
	if (print_n == FALSE)
		printf("\n");
	return (0);
}

// int	ft_echo_without_quotes(t_var *var)
// {	
// 	var->echo->echo = ft_strtrim(var->echo->echo, 32);
// 	if (var->echo->dollar == 0 && var->echo->dash_n == 1)
// 		ft_putendl_fd(var->echo->echo, 1);
// 	else if (var->echo->dash_n == 1 && var->echo->dollar == 0)
// 		ft_putstr_fd(var->echo->echo, 1);
// 	else if (var->echo->dollar == 1)
// 		ft_echo_dollar(var);
// 	return (0);
// }

// int	ft_echo_simple_quote(t_var *var)
// {
// 	if (var->echo->dollar == 1)
// 		write(1, "$", 1);
// 	ft_putstr_fd(var->echo->echo, 1);
// 	if (var->echo->dash_n == 0)
// 		write(1, "\n", 1);
// 	return (0);
// }

// int	ft_echo_double_quote(t_var *var)
// {
// 	if (var->echo->dollar == 0)
// 		ft_putendl_fd(var->echo->echo, 1);
// 	else if (var->echo->dash_n == 1 && var->echo->dollar == 0)
// 		ft_putstr_fd(var->echo->echo, 1);
// 	else if (var->echo->dollar == 1)
// 		ft_echo_dollar(var);
// }

// int	ft_echo_dollar(t_var *var)
// {
// 	ft_putstr_fd(var->echo->echo, 1);
// 	if (var->echo->dash_n == 0)
// 		write(1, "\n", 1);
// 	return (0);
// }
