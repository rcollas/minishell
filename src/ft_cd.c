/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:43:47 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/07 11:34:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int Errors_chdir_handling(int dir)
{
	if (dir < 0)
		perror("cd failed"); 
	// rajouter la fonction qui free
	return (0);
}

void	free_list(t_var *var) // fonction a virer au parsing
{
	t_list *tmp;
	
	while(var->list)
	{
		tmp = var->list->next;
		free(var->list->content);
		free(var->list);
		var->list = tmp;
	}
}

int ft_cd(t_var *var)
{
	int 	dir;
	t_list 	*tmp;
	t_envar	*tmp2;
	t_envar	*tmp3;
	t_envar	*tmp4;
	char	*str;
	
	var->cmd = &(var->cmd[3]);
	print_echo(var);
	tmp = var->list;
	tmp2 = var->envar;
	dir = chdir(tmp->content);
	tmp3 = var->envar;
	tmp4 = var->envar;
	// if (tmp->content == 0)
	// {
	// 	dir = chdir("~");
	// 	printf("%s\n", getcwd(0, 150));
	// 	return(0);
	// }
	printf("%s\n", getcwd(0, 150));
	while(tmp3)
	{
		if(ft_strcmp(tmp3->name, "OLDPWD"))
		{
			str = tmp3->content;
			break;
		}
		tmp3 = tmp3->next;
	}
	while(tmp4)
	{
		if (ft_strcmp(tmp4->name, "PWD"))
		{
			break;
		}
		tmp4 = tmp4->next;
	}
	tmp4->content = tmp3->content;
	tmp3->content = str;
	if (dir < 0)
		Errors_chdir_handling(dir);
	// printf("%s\n", getcwd(0, 150));
	return (0);
}
