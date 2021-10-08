/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:39:06 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/08 11:50:09 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_var *var)
{
	t_envar	*tmp;

	tmp = var->envar;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PWD") == 1)
		{
			// if (argv[2][0] == '-') // il faudra recuperer l'element + 1 de la liste apres pwd
			// {
			// 	printf("Invalid option\n"); // Rajouter une vraie erreur pour ce cas
			// 	exit (1);
			// }
			if (access(tmp->content, F_OK) == 0)
			{
				printf("%s\n", tmp->content);
				break ;
			}
			if (access(tmp->content, F_OK) == -1)
			{
				perror("Path is invalid");
				exit (1); // je dois surement le changer pour free autre chose
			}
			//rajouter la fonction pour changer le old name et le new name
		}
		tmp = tmp->next;
	}
	return (0);
}
