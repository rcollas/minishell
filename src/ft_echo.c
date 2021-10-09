/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:29:41 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/08 17:34:06 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	charcmp(char c1, char c2)
{
	if (c1 != c2)
		return (0);
	return (1);
}

int	is_valid_dollar(char *str, int i)
{
	if (str[i] == '$')
	{
		if (ft_isalnum(str[i + 1]))
			return (1);
	}
	return (0);
}

char	*get_valid_envar(t_var *var, char *str, int i)
{
	t_envar	*tmp;
	int	j;
	int	k;

	tmp = var->envar;
	(void)str;
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
	return ("");
}

int	expand_envar(t_var *var, char *str, int i)
{
	int	len;

	len = ft_strlen(get_valid_envar(var, str, i));
	if (get_valid_envar(var, str, i) == FAIL)
	{
		while (ft_isalnum(str[i]) && str[i])
			i++;
		return (i);
	}
	while (ft_isalnum(str[i]) && str[i])
		i++;
	return (i);
}

void	check_s_quote(int *s_quote)
{
	if (*s_quote == FALSE)
		*s_quote = TRUE;
	else
		*s_quote = FALSE;
}

void	check_d_quote(int *d_quote)
{
	if (*d_quote == FALSE)
		*d_quote = TRUE;
	else
		*d_quote = FALSE;
}

int	get_string_len(char *str, t_var *var)
{
	int	i;
	int	j;
	int	d_quote;
	int	s_quote;

	d_quote = 0;
	s_quote = 0;
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '$' && s_quote == FALSE && is_valid_dollar(str, i) == TRUE)
		{
			j += ft_strlen(get_valid_envar(var, str, ++i));
			while (ft_isalnum(str[i]) == TRUE)
				i++;
			i--;
			continue ;
		}
		if (str[i] == '"' && s_quote == FALSE)
		{
			check_s_quote(&s_quote);
			continue ;
		}
		if (str[i] == '\'' && d_quote == FALSE)
		{
			check_d_quote(&d_quote);
			continue ;
		}
		j++;
	}
	return (j);
}

char	*ft_trim(t_var *var, char *str, int len)
{
	char	*trim_str;
	int	i;
	int	j;
	int	k;
	int	s_quote;
	int	d_quote;

	trim_str = (char *)malloc(sizeof(char) * (len + 1));
	j = 0;
	i = 0;
	s_quote = 0;
	d_quote = 0;
	while (i < len)
	{
		k = 0;
		if (str[j] == '"' && s_quote == FALSE)
		{
			if (d_quote == FALSE)
				d_quote = TRUE;
			else
				d_quote = FALSE;
			j++;
			continue ;
		}
		if (str[j] == '\'' && d_quote == FALSE)
		{
			if (s_quote == FALSE)
				s_quote = TRUE;
			else
				s_quote = FALSE;
			j++;
			continue ;
		}
		if (str[j] == '$' && s_quote == FALSE && ft_isalnum(str[j + 1]) == TRUE)
		{
			j++;
			while (get_valid_envar(var, str, j)[k])
				trim_str[i++] = get_valid_envar(var, str, j)[k++];
			while (ft_isalnum(str[j]) == TRUE)
				j++;
			continue ;
		}
		trim_str[i++] = str[j++];
	}
	trim_str[i] = 0;
	return (trim_str);
}

int	get_arguments(char **split_cmd, t_var *var)
{
	int	i;
	char	*content;

	i = -1;
	while (split_cmd[++i])
	{
		content = ft_trim(var, split_cmd[i], get_string_len(split_cmd[i], var));
		ft_lstadd_back(&var->list, ft_lstnew(content));
	}
	return (1);
}

int	ft_echo(t_var *var)
{
	int	i;
	char	**test;
	t_list	*start;

	var->cmd = &(var->cmd[5]);
	if (check_unmatched_quotes(var) == TRUE)
	{
		printf("Unmatched quotes\n");
		return (0);
	}
	test = ft_split(var->cmd, ' ');
	i = -1;
	get_arguments(test, var);
	start = var->list;
	while (start)
	{
		printf("content = %s ", start->content);
		start = start->next;
	}
	printf("\n");
	return (0);
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
