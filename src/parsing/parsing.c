/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:41:26 by rcollas           #+#    #+#             */
/*   Updated: 2021/10/11 17:01:59 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
			if (ft_charcmp((tmp->name)[j], str[k]) == FAIL)
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

int	get_arguments(t_var *var)
{
	char	*content;
	char	**split_input;
	int		i;
	int		len;

	i = -1;
	if (check_unmatched_quotes(var) == TRUE)
	{
		printf("Unmatched quotes\n");
		return (0);
	}
	split_input = ft_split(var->cmd, ' ');
	while (split_input[++i])
	{
		var->s_quote = 0;
		var->d_quote = 0;
		len = get_string_len(split_input[i], var);
		var->s_quote = 0;
		var->d_quote = 0;
		content = ft_trim(var, split_input[i], len);
		ft_lstadd_back(&var->list, ft_lstnew(content));
	}
	free_split(split_input);
	return (1);
}
