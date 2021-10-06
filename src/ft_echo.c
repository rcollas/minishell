/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:29:41 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/05 19:05:21 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	charcmp(char c1, char c2)
{
	if (c1 != c2)
		return (0);
	return (1);
}

int		is_valid_dollar(t_var *var, int i)
{
	if (var->cmd[i] == '$')
	{
		if (ft_isalnum(var->cmd[i + 1]))
			return (1);
	}
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
			if ((ft_isalnum(var->cmd[k]) == 0) || var->cmd[k] == 0)
				return (tmp->content);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	expand_envar(t_var *var, int i)
{
	char	*str;
	int			k;
	int			dollar;
	int			j;

	k = 0;
	dollar= 1;
	j = i;
	while (dollar == TRUE && var->cmd[j])
	{
		if (get_valid_envar(var, j) == FAIL)
		{
			while (ft_isalnum(var->cmd[j]) && var->cmd[j])
				j++;
			while (var->cmd[j] != ' ' && var->cmd[j] != '"' && is_valid_dollar(var, j - 1) == FALSE)
			{
				j++;
				k++;
			}
		}
		else
		{
			k += ft_strlen(get_valid_envar(var, j));
			while (ft_isalnum(var->cmd[j]) && var->cmd[j])
				j++;
			while (var->cmd[j] && var->cmd[j] != '"' && var->cmd[j] != ' ' && is_valid_dollar(var, j) == FALSE)
			{
				j++;
				k++;
			}
		}
		if (var->cmd[j] == '$')
			j++;
		else if (var->cmd[j] != '$')
			dollar = 0;
		}
	dollar = 1;
	str = (char *)malloc(sizeof(char) * (k + 1));
	j = 0;
	while (dollar == TRUE && var->cmd[i])
	{
		k = 0;
		if (get_valid_envar(var, i) == FAIL)
		{
			while (ft_isalnum(var->cmd[i]) && var->cmd[i])
				i++;
			while (var->cmd[j] && var->cmd[j] != '"' && var->cmd[j] != ' ' && is_valid_dollar(var, j - 1) == FALSE)
				str[j++] = var->cmd[++i - 2];;
		}
		else
		{
			while (get_valid_envar(var, i)[k])
				str[j++] = get_valid_envar(var, i)[k++];
			while (ft_isalnum(var->cmd[i]) && var->cmd[i])
				i++;
			while (var->cmd[i] && var->cmd[i] != '"' && var->cmd[i] != ' ' && is_valid_dollar(var, i) == FALSE)
			{
				printf("var cmd = %c\n", var->cmd[i]);
				str[j++] = var->cmd[++i - 1];
				//if (var->cmd[i] == '$')
				//	j--;
			}
		}
		if (var->cmd[i] == '$')
			i++;
		else if (var->cmd[i] != '$')
			dollar = 0;
		printf("var after i++ = %c\n", var->cmd[i]);
	}
	str[j] = 0;
	ft_lstadd_back(&var->list, ft_lstnew(str));
	return (i);
}

int	print_simple_quotes(t_var *var, int i)
{
	int	j;
	
	char	*str;
	j = i;
	while (var->cmd[j] != '\'')
	{
		j++;
		while (var->cmd[j] == '\'' && var->cmd[j + 1] == '\'')
			j += 2;
	}
	str = (char *)malloc(sizeof(char) * j);
	j = 0;
	while (var->cmd[i] != '\'')
	{
		str[j++] = var->cmd[i++];
		while (var->cmd[i] == '\'' && var->cmd[i + 1] == '\'')
			i += 2;
	}
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
		if (var->cmd[j] == '$')
		{
			i = expand_envar(var, ++j);
			while (ft_isalnum(var->cmd[1 + j++]) == TRUE)
				k++;
		}
		j++;
		while (var->cmd[j] == '"' && var->cmd[j + 1] == '"')
			j += 2;
	}
	str = (char *)malloc(sizeof(char) * (j - k));
	j = 0;
	while (var->cmd[i] != '"')
	{
		if (var->cmd[i] == '$')
			i += k;
		str[j++] = var->cmd[i++];
		while (var->cmd[i] == '"' && var->cmd[i + 1] == '"')
			i += 2;
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
	while (var->cmd[i] != '\'' && var->cmd[i] != '"' && is_valid_dollar(var, i) == FALSE && var->cmd[i] && var->cmd[i] != ' ')
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
			i = print_simple_quotes(var, ++i);
		else if (var->cmd[i] == '"')
			i = print_double_quotes(var, ++i);
		else if (var->cmd[i] == '$' && ft_isalnum(var->cmd[i + 1]))
			i = expand_envar(var, ++i);
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
		printf("%s", var->list->content);
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
