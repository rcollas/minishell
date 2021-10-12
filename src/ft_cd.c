/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:43:47 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/08 11:48:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	errors_chdir_handling(int dir)
{
	if (dir < 0)
		perror("cd failed");
	// rajouter la fonction qui free
	return (0);
}

void	free_list(t_var *var) // fonction a virer au parsing
{
	t_list	*tmp;

	while (var->list)
	{
		tmp = var->list->next;
		free(var->list->content);
		free(var->list);
		var->list = tmp;
	}
}

int	ft_cd(t_var *var)
{
	int		dir;
	t_list	*tmp;
	t_envar	*tmp2;
	char	*str;

	str = NULL;
	tmp2 = var->envar;
	var->cmd = &(var->cmd[3]); // a recuperer plus proprement
	print_echo(var);
	tmp = var->list;
	tmp2 = var->envar;
	// if (var->cmd[3] == 0) // a modifier avec les bonnes valeurs
	// {
	// 	str = ft_envar_find_content(tmp2, "HOME");
	// 	dir = chdir(str);
	// 	str = ft_envar_swap_1(var, "PWD");
	// 	printf("%s\n", getcwd(0, 150));
	// 	return (0);
	// }
	dir = chdir(var->list->content);
	str = ft_envar_swap_1(var, "PWD");
	ft_envar_swap_2(var, "OLDPWD", str);
	if (dir < 0)
		errors_chdir_handling(dir);
	return (0);
}

char	*ft_envar_swap_1(t_var *var, char *str)
{
	char	*str2;
	t_envar	*tmp;

	tmp = var->envar;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str))
		{
			str = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	str2 = getcwd(0, 150);
	tmp->content = str2;
	return (str);
}

void	ft_envar_swap_2(t_var *var, char *str, char *str2)
{
	t_envar	*tmp;

	tmp = var->envar;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str))
		{
			tmp->content = str2;
			break ;
		}
		tmp = tmp->next;
	}
}
