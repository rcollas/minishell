/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:43:47 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/06 18:04:26 by vbachele         ###   ########.fr       */
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
	
	var->cmd = &(var->cmd[3]);
	print_echo(var);
	tmp = var->list;
	tmp2 = var->envar;
	dir = chdir(tmp->content);
	// if (tmp->content == 0)
	// {
	// 	dir = chdir("~");
	// 	printf("%s\n", getcwd(0, 150));
	// 	return(0);
	// }
	if (dir < 0)
		Errors_chdir_handling(dir);
	printf("%s\n", getcwd(0, 150));
	return (0);
}
