/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:27:30 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/08 18:08:41 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_var *var)
{
	int		i;
	int		j;
	char	*name;
	char	*content;
	int		equal;

	j = 0;
	i = 0;
	equal = 0;
	name = 0;
	var->cmd = &(var->cmd[7]);
	if (cmd_not_alpha(var) == -1)
		return (-1);
	name = malloc(sizeof(ft_strlen(var->cmd)));
	content = malloc(sizeof(ft_strlen(var->cmd)));
	while (var->cmd[i])
	{
		if (var->cmd[i] == '=')
		{
			equal = 1;
			break ;
		}
		name[i] = var->cmd[i];
		i++;
	}
	while (var->cmd[i++])
	{
		content[j] = var->cmd[i];
		j++;
	}
	if (export_reassigned_check(var, name, content) == -1 || equal == 0)
		return (-1);
	export_insert(var, name, content);
	return (0);
}

int	cmd_not_alpha(t_var *var)
{
	if (!ft_isalpha(var->cmd[0]))
	{
		ft_putendl_fd("export: not valid in this context", 2);
		return (-1);
	}
	return (0);
}

int	export_reassigned_check(t_var *var, char *name, char *content)
{
	t_envar	*tmp;

	tmp = var->envar;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 1)
		{
			tmp->content = content;
			return (-1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	export_insert(t_var *var, char *name, char *content)
{
	int		size;
	t_envar	*tmp;
	t_envar	*tmp2;

	tmp = var->envar;
	tmp2 = var->envar;
	size = 0;
	tmp = ft_envar_new(name, content);
	size = ft_envarsize(tmp2);
	if (envar_insert(&var->envar, tmp, size) == 1)
	{
		// free (content);
		// free (name);
		return (0);
	}
	return (0);
}
// int export_find_equal(t_var *var)
// {
// 	int	i;
// 	int	equal;

// 	i = 0;
// 	equal = 0;
// 	while (var->cmd[i])
// 	{
// 		if (var->cmd[i] == '=')
// 		{
// 			equal = 1;
// 			break ;
// 		}
// 		name[i] = var->cmd[i];
// 		i++;
// 	}
// 	if (equal == 0)
// 		return (- 1);
// }
