/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:29:41 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/11 12:39:00 by rcollas          ###   ########.fr       */
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
	int		j;
	int		k;

	tmp = var->envar;
	while (tmp)
	{
		j = 0;
		k = i;
		while (tmp->name[j] && str[k])
		{
			if (charcmp((tmp->name)[j], str[k]) == FAIL)
				break ;
			j++;
			k++;
			if ((ft_isalnum(str[k]) == 0) || str[k] == 0)
				return (tmp->content);
		}
		tmp = tmp->next;
	}
	return ("");
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

void	get_envar_len(int *j, int *i, t_var *var, char *str)
{
	*j += ft_strlen(get_valid_envar(var, str, ++(*i)));
	while (ft_isalnum(str[*i]) == TRUE)
		(*i)++;
	(*i)--;
}

int	get_string_len(char *str, t_var *var)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '$' && var->s_quote == FALSE && is_valid_dollar(str, i))
		{
			get_envar_len(&j, &i, var, str);
			continue ;
		}
		if (str[i] == '"' && var->s_quote == FALSE)
		{
			check_s_quote(&var->s_quote);
			continue ;
		}
		if (str[i] == '\'' && var->d_quote == FALSE)
		{
			check_d_quote(&var->d_quote);
			continue ;
		}
		j++;
	}
	return (j);
}

int	check_quotes(char *str, int *j, t_var *var)
{
	if (str[*j] == '"' && var->s_quote == FALSE)
	{
		check_d_quote(&var->d_quote);
		(*j)++;
		return (1);
	}
	if (str[*j] == '\'' && var->d_quote == FALSE)
	{
		check_s_quote(&var->s_quote);
		(*j)++;
		return (1);
	}
	return (0);
}

void	skip_alnum(char *str, int *j)
{
	while (ft_isalnum(str[*j]) == TRUE)
		(*j)++;
}

char	*ft_trim(t_var *var, char *str, int len)
{
	char	*trim_str;
	int		i;
	int		j;
	int		k;

	trim_str = (char *)malloc(sizeof(char) * (len + 1));
	j = 0;
	i = 0;
	while (i < len)
	{
		k = 0;
		if (check_quotes(str, &j, var) == TRUE)
			continue ;
		if (str[j] == '$' && var->s_quote == FALSE && ft_isalnum(str[j + 1]))
		{
			j++;
			while (get_valid_envar(var, str, j)[k])
				trim_str[i++] = get_valid_envar(var, str, j)[k++];
			skip_alnum(str, &j);
			continue ;
		}
		trim_str[i++] = str[j++];
	}
	trim_str[i] = 0;
	return (trim_str);
}

int	get_arguments(char **split_cmd, t_var *var)
{
	char	*content;
	int		i;
	int		len;

	i = -1;
	while (split_cmd[++i])
	{
		len = get_string_len(split_cmd[i], var);
		var->s_quote = 0;
		var->d_quote = 0;
		content = ft_trim(var, split_cmd[i], len);
		ft_lstadd_back(&var->list, ft_lstnew(content));
	}
	return (1);
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
			if (var->list->content[i + 1] == '\0'
				|| var->list->content[i + 1] == ' ')
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	ft_echo(t_var *var)
{
	char	**test;
	t_list	*start;
	int		i;

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
		printf("%s ", start->content);
		start = start->next;
	}
	if (is_dash_n(var) == FALSE)
		printf("\n");
	return (0);
}
