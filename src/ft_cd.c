/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:43:47 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/06 01:25:18 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int Errors_chdir_handling(int dir)
{
	if (dir < 0)
		perror("cd failed"); 
	// rajouter la fonction qui free
	exit(1);
}

int ft_cd(t_var *var)
{
	int 	dir;
	t_list *tmp;
	
	tmp = var->list;
	while (tmp)
	{
		printf("POUET2");
		if (ft_strcmp(tmp->content, "cd") == 1)
		{
			tmp = tmp->next;
			dir = chdir(tmp->content);
			if (dir < 0)
				Errors_chdir_handling(dir);
			break;
		}
		printf("%s\n", getcwd(0, 100));
		tmp = tmp->next;
	}
	return (0);
}
