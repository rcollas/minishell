/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:39:06 by vbachele          #+#    #+#             */
/*   Updated: 2021/10/05 14:34:15 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **argv)
{
	int dir;
	if (strcmp(argv[1], "pwd") == 0) // enlever cette condition
	{
		if (argv[2][0] == '-') // il faudra recuperer l'element + 1 de la liste apres pwd
		{
			printf("Invalid option\n"); // Rajouter une vraie erreur pour ce cas
			exit (1);
		}
		if (access(argv[2], F_OK) == 0) //remplacer argv[2] par ce que robin envoie
		{
			printf("%s\n", argv[2]); // je remplace par la string aue robin m'envoie
		}
		if (access(argv[2], F_OK) == -1)
		{
			perror("Path is invalid");
			exit (1); // je dois surement le changer pour free autre chose
		}
	}
	return(0);
}

int main(int argc, char **argv) // Enlever le main 
{
	(void) argc;
	ft_pwd(argv);
	return (0);
}
